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
	std::vector<Star*> starVector;
	
	sf::Vector2f GetScreenSize();

};

