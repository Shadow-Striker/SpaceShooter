#pragma once
#include "GameObject.h"

class Ship;

class Bullet : public GameObject
{
public:
    Bullet();
    void HandleCollision(Ship* target);
    bool IsAlive();

private:
    int damage;
    bool alive;
    static sf::Texture* bulletTexture;
};

