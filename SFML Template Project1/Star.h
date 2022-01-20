#pragma once
#include "GameObject.h"
class Star : public GameObject
{
public:
	Star(sf::Vector2f _screenSize);
	//Overridden Functions
	virtual void Update(sf::Time deltaTime);
private:
	sf::Texture starTexture;
	sf::Vector2f screenSize;
	float moveSpeed;
};

