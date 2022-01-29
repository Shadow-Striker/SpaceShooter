#pragma once
#include "Ship.h"
class Enemy :
    public Ship
{
public:
    Enemy(sf::Vector2f newScreenSize);
    //Overridden Functions
    virtual void Update(sf::Time deltaTime) override;
private:
    sf::Vector2f movementTarget;
    float arrivalDistance;
    bool arrivedAtTarget;

protected:
    void SetTarget(sf::Vector2f newTarget);

    virtual void AI();
};

