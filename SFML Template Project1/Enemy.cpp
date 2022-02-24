#include "Enemy.h"

Enemy::Enemy(sf::Vector2f newScreenSize, Game* newGame)
//Initalising base class for clarity
	: Ship				(newGame)
	, movementTarget	(0,0)
	, arrivalDistance	(10)
	, arrivedAtTarget	(true)
{
	sf::Vector2f newPosition(0, 0);
	rand();
	rand();
	//randomNumber = lower + rand() % (upper - lower)
	//Gap between spaceship and edge of screen.
	float screenGap = 100;
	float estimatedSpriteHeight = 100;
	float lowerBound = screenGap;
	float upperBound = newScreenSize.y - screenGap - estimatedSpriteHeight;
	newPosition.x = (int)newScreenSize.x - 150;
	newPosition.y = rand() % (int)(upperBound - lowerBound);
	SetPosition(newPosition);

	//Setup our move speed
	moveSpeed = 200.0f;

	//Enemy should get player's position
	//SetTarget(sf::Vector2f(newPlayerPos));
}

void Enemy::Update(sf::Time deltaTime)
{
	AI(); //This sets the enemy's target to the player position

	if (!arrivedAtTarget)
	{
		sf::Vector2f direction = movementTarget - GetPosition();
		Move(direction);
	}
	else 
	{
		SetVelocity(sf::Vector2f(0, 0));
	}

	Ship::Update(deltaTime);

	//Check if we have arrived at target

	sf::Vector2f distanceVector = movementTarget - GetPosition();
	float magnitude = sqrtf(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);

	if (magnitude <= arrivalDistance)
	{
		arrivedAtTarget = true;
	}
}

void Enemy::SetTarget(sf::Vector2f newTarget)
{
	movementTarget = newTarget;
	arrivedAtTarget = false;
}

void Enemy::AI()
{
}
