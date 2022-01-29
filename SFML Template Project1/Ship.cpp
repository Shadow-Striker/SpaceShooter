#include "Ship.h"
#include "Bullet.h"
#include "Game.h"

Ship::Ship(Game* newGame)
	:moveSpeed	(0)
	,myGame		(newGame)
{
}

void Ship::Move(sf::Vector2f direction)
{
	float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);
	
	if (magnitude == 0)
	{
		SetVelocity(sf::Vector2f(0.0f, 0.0f));
	}
	else
	{
		sf::Vector2f directionNormalised = direction / magnitude;
		SetVelocity(directionNormalised * moveSpeed);
	}
}

void Ship::Fire()
{
	//Create a bullet
	Bullet* newBullet = new Bullet();

	//set the bullet's velocity
	//Set the bullet's pos to ship pos + offset
	newBullet->SetPosition(GetPosition()); 
	//set velocity based on type of ship
	newBullet->SetVelocity(sf::Vector2f(600, 0));
	//give the bullet to the Game class to manage

	myGame->AddBullet(newBullet);
}
