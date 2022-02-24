#include "Bullet.h"
#include "Ship.h"
#include <iostream>

sf::Texture* Bullet::bulletTexture = nullptr;

Bullet::Bullet()
	: GameObject()
	, damage(3)
	, alive(true)
{
	sf::Vector2f newPosition(0, 0);
	SetPosition(newPosition);
	if (bulletTexture == nullptr)
	{
		bulletTexture = new sf::Texture();
		bulletTexture->loadFromFile("Assets/Graphics/playerBullet.png");
	}
	objectSprite.setTexture(*bulletTexture);
}

void Bullet::HandleCollision(Ship* target)
{
	sf::FloatRect bulletCollider = GetCollider();
	sf::FloatRect shipCollider = target->GetCollider();

	if (bulletCollider.intersects(shipCollider))
	{
		target->TakeDamage(100);
	}
}

bool Bullet::IsAlive()
{
	return false;
}
