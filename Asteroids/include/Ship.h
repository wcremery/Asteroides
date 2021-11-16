#ifndef  SHIP_H
#define SHIP_H

#include "SpaceObject.h"

class Ship : public SpaceObject
{
public:
	explicit Ship(sf::Color const color);
	void updateState();
	virtual void updateSpaceObject(double const& deltaTime) override;
private:
	bool bIncreaseVelocity_{ false };
	bool bTurnLeft_{ false };
	bool bTurnRight_{ false };

	
	// constexpr = défini à la compilation
	static constexpr double VELOCITY_{ 2000.0 };
	static constexpr double ANGULAR_VELOCITY_{ 50.0 };
	static constexpr double COEFF_FRICTION_{ 2.0 };
};

#endif
