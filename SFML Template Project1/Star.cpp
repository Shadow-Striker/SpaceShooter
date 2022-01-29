#include "Star.h"

//Initilisation of static variable
sf::Texture* Star::starTexture = nullptr;

Star::Star(sf::Vector2f _screenSize)
	: GameObject()
	, screenSize(_screenSize)
	, moveSpeed(200.0f)
{
	if (starTexture == nullptr)
	{
		starTexture = new sf::Texture();
		starTexture->loadFromFile("Assets/Graphics/Star.png");
	}


	objectSprite.setTexture(*starTexture);

	//Random Position
	sf::Vector2f newPosition(0, 0);
	rand();
	rand();
	//randomNumber = lower + rand() % (upper - lower)
	newPosition.x = rand() % (int)_screenSize.x;
	newPosition.y = rand() % (int)_screenSize.y;
	newPosition.y;
	SetPosition(newPosition);

	//Set initial velocity

	sf::Vector2f moveDirection(-1.0f, 0.0f);
	SetVelocity(moveDirection * moveSpeed);
}

void Star::Update(sf::Time deltaTime)
{
	SetVelocity(moveSpeed * sf::Vector2f(-1.0f, 0.0f));

	//We're getting the right side of the star. This is because the origin point is in the top left.
	float starPosition = GetPosition().x + objectSprite.getGlobalBounds().width;

	if (starPosition < 0)
	{
		Reset();
	}

	GameObject::Update(deltaTime);
}

void Star::Reset()
{
	sf::Vector2f newPosition(0, 0);
	newPosition.x = (int)screenSize.x;
	newPosition.y = rand() % (int)screenSize.y;
	SetPosition(newPosition);
}
