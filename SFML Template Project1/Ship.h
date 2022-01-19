#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Ship : public GameObject
{
public:
	Ship();

protected:

	void Move(sf::Vector2f direction);

	float moveSpeed;
private:


};

