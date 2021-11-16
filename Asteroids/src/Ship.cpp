#include <iostream>
#include "../include/Ship.h"

Ship::Ship(sf::Color const color) : SpaceObject("resources/ship.png")
{
	SpaceObject::spaceObjectSprite_.setColor(color);
}

void Ship::updateState()
{
	bIncreaseVelocity_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	bTurnLeft_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bTurnRight_ = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Ship::updateSpaceObject(double const& deltaTime)
{
	if (bIncreaseVelocity_)
	{
		spaceObjectSpeed_ += MyVector::direction(VELOCITY_ * deltaTime, spaceObjectSprite_.getRotation());
	}

	if(bTurnLeft_)
	{
		spaceObjectSprite_.rotate(-ANGULAR_VELOCITY_ * deltaTime);
	}

	if (bTurnRight_)
	{
		spaceObjectSprite_.rotate(ANGULAR_VELOCITY_ * deltaTime);
	}

	spaceObjectSpeed_ -= spaceObjectSpeed_ * COEFF_FRICTION_ * deltaTime;

	SpaceObject::updateSpaceObject(deltaTime);
}