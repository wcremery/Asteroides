#include "../include/Asteroid.h"

Asteroid::Asteroid() :
	SpaceObject::SpaceObject("resources/asteroid.png")
{
	auto seed = std::random_device{};
	auto generator = std::mt19937{ seed() };
	auto speedDistribution = std::uniform_real_distribution<double>(80.0, 150.0);
	auto positionDistribution = std::uniform_real_distribution<double>(0, 300);

	spaceObjectPosition_ = Coordinates{ positionDistribution(generator), positionDistribution(generator) };
	spaceObjectSpeed_ = MyVector{ speedDistribution(generator), speedDistribution(generator) };
}
 
void Asteroid::updateSpaceObject(double const& deltaTime)
{
	SpaceObject::updateSpaceObject(deltaTime);
}
