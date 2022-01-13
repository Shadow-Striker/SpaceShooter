#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	GameObject();

	void Draw(sf::RenderTarget& target);
	virtual void Update(sf::Time deltaTime);
	void SetVelocity(sf::Vector2f _velocity);
	void SetPosition(sf::Vector2f newPosition);

private:

	sf::Sprite objectSprite;
	sf::Vector2f position;
	sf::Vector2f velocity;
};

