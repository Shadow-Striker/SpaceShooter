#include "Game.h"
#include <SFML/Graphics.hpp>
Game::Game()
	:window(sf::VideoMode::getDesktopMode(), "Space Shooter", sf::Style::Titlebar | sf::Style::Close)
{
}

void Game::Run()
{

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

	window.display();
}

void Game::Update()
{
}
