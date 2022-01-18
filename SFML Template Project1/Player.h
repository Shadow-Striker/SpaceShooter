#pragma once
#include "Ship.h"
class Player :
    public Ship
{

public:
    //Constructor and destructors
    Player();

    //Overridden Functions
    virtual void Update(sf::Time deltaTime);

private:
    void Input();

        sf::Texture playerTexture;
};

