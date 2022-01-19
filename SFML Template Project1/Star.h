#pragma once
#include "GameObject.h"
class Star : public GameObject
{
public:
	Star(sf::Vector2f _screenSize);

private:
	sf::Texture starTexture;
	sf::Vector2f screenSize;
};

