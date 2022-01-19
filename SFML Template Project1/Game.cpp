#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game()
	: window(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Titlebar | sf::Style::Close)
	, gameClock()
	, playerInstance()
	, starInstance(sf::Vector2f(window.getSize()))
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
	starInstance.Draw(window);

	window.display();
}

void Game::Update()
{
	//sf::Time is for storing time precisely.
	//Time passed since last frame.
	sf::Time deltaTime = gameClock.restart();
	playerInstance.Update(deltaTime);
}

void Game::SetupGame()
{
	sf::Vector2f screenSize(window.getSize());

	//Put our player in the centre of the screen vertically and near the left side.
	playerInstance.SetPosition(sf::Vector2f(100, screenSize.y / 2 - 50));
}

sf::Vector2f Game::GetScreenSize()
{
	return (sf::Vector2f)window.getSize();
}
