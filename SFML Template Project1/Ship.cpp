#include "Ship.h"

Ship::Ship()
	:moveSpeed(0)
{
}

void Ship::Move(sf::Vector2f direction)
{
	float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);
	sf::Vector2f directionNormalised = direction / magnitude;

	SetVelocity(direction * moveSpeed);
}
