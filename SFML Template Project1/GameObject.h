#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
public:
	GameObject();

	//Reference is really important here, as it refers to the original render target.
	void Draw(sf::RenderTarget& target);
	virtual void Update(sf::Time deltaTime);
	void SetVelocity(sf::Vector2f _velocity);
	void SetPosition(sf::Vector2f newPosition);

protected:
	sf::Sprite objectSprite;

private:
	sf::Vector2f position;
	sf::Vector2f velocity;
};

