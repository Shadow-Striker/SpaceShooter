#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Star.h"

class Game
{
public:

	Game();

	void Run();
	void Draw();
	void Update();

private:
	void SetupGame();

	sf::RenderWindow window;
	sf::Clock gameClock;
	Player playerInstance;
	Star starInstance;
	sf::Vector2f GetScreenSize();

};

