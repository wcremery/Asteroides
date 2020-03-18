#include "Vector.hpp"

void Vector::operator+=(Vector const& vector)
{
	x += vector.x;
	y += vector.y;
}

void Vector::operator-=(Vector const& vector)
{
	x -= vector.x;
	y -= vector.y;
}

Vector Vector::operator*(float coeff) const
{
	return { x * coeff, y * coeff };
}

Vector Vector::createFromAngle(float size, float angle)
{
	return { size * cos(angle / 180.f*static_cast<float>(M_PI)), size * sin(angle / 180.f * static_cast<float>(M_PI)) };
}