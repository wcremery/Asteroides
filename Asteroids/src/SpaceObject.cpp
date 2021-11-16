#include "../include/SpaceObject.h"

SpaceObject::SpaceObject(std::string_view const& spritePath) :
	spaceObjectSpeed_{ 0.0, 0.0 }
{
	const auto loadSuccess = spaceObjectTexture_.loadFromFile(spritePath.data());
	if (!loadSuccess) { std::cerr << "[ERROR] Load " << spritePath << " texture failed :(" << std::endl; }
	spaceObjectName_ = spritePath;
	spaceObjectSprite_.setTexture(spaceObjectTexture_);
	spaceObjectSprite_.setOrigin(spaceObjectSprite_.getLocalBounds().height / 2, spaceObjectSprite_.getLocalBounds().width / 2);
	spaceObjectPosition_ = Coordinates{};
	spaceObjectSprite_.setPosition(spaceObjectPosition_.X(), spaceObjectPosition_.Y());
	spaceObjectRadius_ = spaceObjectSprite_.getLocalBounds().height / 2.0;
}


void SpaceObject::display(sf::RenderWindow& window) const
{
	window.draw(spaceObjectSprite_);
}

void SpaceObject::updateSpaceObject(double const& deltaTime)
{
	spaceObjectPosition_ += (spaceObjectSpeed_ * deltaTime);
	spaceObjectSprite_.setPosition(spaceObjectPosition_.X(), spaceObjectPosition_.Y());
}

void SpaceObject::checkCollision(SpaceObject& collider)
{
	auto distance = spaceObjectPosition_.computeDistance(collider.spaceObjectPosition_);
	if (distance < spaceObjectRadius_ + collider.spaceObjectRadius_)
	{
		spaceObjectSprite_.setColor(sf::Color::Red);
		collider.spaceObjectSprite_.setColor(sf::Color::Red);
	}
}