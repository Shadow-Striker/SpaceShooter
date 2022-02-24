#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game()
	: window			(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Titlebar | sf::Style::Close)
	, gameClock			()
	, playerInstance	(this)
	, starVector		()
	, enemyVector		()
	, bulletVector		()
	, timeSinceEnemy	()
{
	//New keyword gives us the address to an object
	//AddBullet(new Bullet());
}

void Game::Run()
{
	SetupGame();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//Update
		Update();
		//Draw
		Draw();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
	}

	//Close the game if escape is pressed
}

void Game::Draw()
{
	window.clear();

	playerInstance.Draw(window);

	for (int i = 0; i < enemyVector.size(); ++i)
	{
		enemyVector[i]->Draw(window);
	}
	
	for (int i = 0; i < starVector.size(); ++i)
	{
		starVector[i]->Draw(window);
	}

	for (int i = 0; i < bulletVector.size(); ++i)
	{
		bulletVector[i]->Draw(window);
	}

	window.display();
}

void Game::Update()
{
	//sf::Time is for storing time precisely.
	//Time passed since last frame.
	sf::Time deltaTime = gameClock.restart();
	playerInstance.Update(deltaTime);
	for (int i = 0; i < starVector.size(); ++i)
	{
		starVector[i]->Update(deltaTime);
	}

	for (int i = 0; i < enemyVector.size(); ++i)
	{
		enemyVector[i]->Update(deltaTime);
	}

	//Enemy spawn frequency
	float enemyFrequency = 2.0f;
	timeSinceEnemy += deltaTime;

	if (timeSinceEnemy.asSeconds() >= enemyFrequency)
	{
		SpawnEnemy();
		timeSinceEnemy = sf::Time();
	}

	for (size_t i = 0; i < bulletVector.size(); i++)
	{
		bulletVector[i]->Update(deltaTime);
	}

	//Check collision for the bullets
	for (size_t bulletIndex = 0; bulletIndex < bulletVector.size(); ++bulletIndex)
	{
		for (size_t enemyIndex = 0; enemyIndex < enemyVector.size(); ++enemyIndex)
		{
 			bulletVector[bulletIndex]->HandleCollision(enemyVector[enemyIndex]);
		}
	}

	//Check if any enemies are dead
	for (size_t enemyIndex = 0; enemyIndex < enemyVector.size(); ++enemyIndex)
	{
		if (!enemyVector[enemyIndex]->IsAlive())
		{
			//De-allocate memory
			//Doesn't really delete it. Just becomes garbage memory and is inaccessible.
			delete enemyVector[enemyIndex];
			enemyVector[enemyIndex] = nullptr;

			//Remove enemy from vector
			enemyVector.erase(enemyVector.begin() + enemyIndex);
		}
		else
		{
			++enemyIndex;
		}
	}

	//Check if any bullets are dead
	for (size_t bulletIndex = 0; bulletIndex < bulletVector.size(); ++bulletIndex)
	{
		if (!bulletVector[bulletIndex]->IsAlive())
		{
			//De-allocate memory
			//Doesn't really delete it. Just becomes garbage memory and is inaccessible.
			delete bulletVector[bulletIndex];
			bulletVector[bulletIndex] = nullptr;

			//Remove enemy from vector
			bulletVector.erase(bulletVector.begin() + bulletIndex);
		}
		else
		{
			++bulletIndex;
		}
	}
}

void Game::SetupGame()
{
	sf::Vector2f screenSize(window.getSize());

	//Put our player in the centre of the screen vertically and near the left side.
	playerInstance.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));

	//Create stars
	int numStars = 10;
	for (int i = 0; i < numStars; ++i)
	{
		starVector.push_back(new Star(screenSize));
	}
}

void Game::SpawnEnemy()
{
	//Special pointer EVERY class has called "this"

	enemyVector.push_back(new ChaseEnemy(this, sf::Vector2f(window.getSize()), &playerInstance));
}

void Game::AddBullet(Bullet* bulletToAdd)
{
	bulletVector.push_back(bulletToAdd);
}

sf::Vector2f Game::GetScreenSize()
{
	return (sf::Vector2f)window.getSize();
}
