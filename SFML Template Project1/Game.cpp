#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game()
	: window			(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Titlebar | sf::Style::Close)
	, gameClock			()
	, playerInstance	()
	, starVector		()
{
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

			//Update
			Update();
			//Draw
			Draw();
		}

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
	for (int i = 0; i < starVector.size(); ++i)
	{
		starVector[i]->Draw(window);
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

sf::Vector2f Game::GetScreenSize()
{
	return (sf::Vector2f)window.getSize();
}
