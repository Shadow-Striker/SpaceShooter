#include "Bullet.h"

sf::Texture* Bullet::bulletTexture = nullptr;

Bullet::Bullet()
	: GameObject()
	, damage(3)
	, isAlive(true)
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
