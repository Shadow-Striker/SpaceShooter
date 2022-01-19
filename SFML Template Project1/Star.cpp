#include "Star.h"

Star::Star(sf::Vector2f _screenSize)
	:starTexture	()
	, screenSize	(_screenSize)
{
	starTexture.loadFromFile("Assets/Graphics/Star.png");
	objectSprite.setTexture(starTexture);

	//Random Position
	sf::Vector2f newPosition(0, 0);
	rand();
	rand();
	//randomNumber = lower + rand() % (upper - lower)
	newPosition.x = rand() % (int)_screenSize.x;
	newPosition.y = rand() % (int)_screenSize.y;
	newPosition.y;
	SetPosition(newPosition);
}
