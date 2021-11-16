#pragma once

#include <iostream>
#include <string_view>
#include <SFML/Graphics.hpp>
#include "MyVector.h"
#include "Coordinates.h"

class SpaceObject
{
public:
	explicit SpaceObject(std::string_view const& spritePath);
	SpaceObject(SpaceObject const&) = delete;
	void operator=(SpaceObject const&) = delete;
	void display(sf::RenderWindow& window) const;
	virtual void updateSpaceObject(double const& deltaTime);
	void checkCollision(SpaceObject& collider);
protected:
	std::string_view spaceObjectName_;
	sf::Texture spaceObjectTexture_;
	sf::Sprite spaceObjectSprite_;
	MyVector spaceObjectSpeed_;
	Coordinates spaceObjectPosition_;
	double spaceObjectRadius_;
private:
};

