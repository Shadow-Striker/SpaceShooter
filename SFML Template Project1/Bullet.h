#pragma once
#include "GameObject.h"
class Bullet :
    public GameObject
{
public:
    Bullet();

private:
    int damage;
    bool isAlive;
    static sf::Texture* bulletTexture;
};

