#pragma once

#include <random>
#include "SpaceObject.h"

class Asteroid : public SpaceObject
{
public:
	explicit Asteroid(); 
	virtual void updateSpaceObject(double const& deltaTime) override;
};

