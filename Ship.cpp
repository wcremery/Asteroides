#include "Ship.hpp"
#include <iostream>

Ship::Ship(sf::Color const& color)
{
	if (!texture.loadFromFile("resources/Vaisseau.png"))
	{
		std::cerr << "[ERROR] The ship png has not been found !" << std::endl;
	}
	sprite.setTexture(texture);
	sprite.setColor(color);
	sprite.setOrigin(sprite.getLocalBounds().width /2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(position.getX(), position.getY());

}

Ship::~Ship()
{
	std::cout << "[OBJECT DESTROYED] Ship !" << std::endl;
}

void Ship::Print(sf::RenderWindow& window) const
{
	window.draw(sprite);
}

void Ship::UpdateState()
{
	isAccelerate = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	isTurningLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	isTurningRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Ship::UpdatePos(float deltaTime)
{
	if (isAccelerate)
	{
		speed += Vector::createFromAngle(ACCELERATION* deltaTime, sprite.getRotation());
	}
	speed -= speed * FRICTION * deltaTime;
	auto movement = speed * deltaTime;
	position += movement;
	sprite.setPosition(position.getX(), position.getY());
	if (isTurningLeft)
	{
		sprite.rotate(-ANGULAR_SPEED * deltaTime);
	}
	if (isTurningRight)
	{
		sprite.rotate(ANGULAR_SPEED * deltaTime);
	}
}