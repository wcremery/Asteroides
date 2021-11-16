#define _USE_MATH_DEFINES
#include <cmath>
#include "../include/MyVector.h"

void MyVector::operator+=(MyVector const& vector2)
{
	x += vector2.x;
	y += vector2.y;
}

void MyVector::operator-=(MyVector const& vector2)
{
	x -= vector2.x;
	y -= vector2.y;
}

MyVector MyVector::operator*(double const& coeff) const
{
	return {x * coeff, y * coeff};
}

MyVector MyVector::direction(double const& size, double const& angle)
{
	return {size * static_cast<double>(cos(angle / 180.0 * M_PI)), size * static_cast<double>(sin(angle / 180.0 * M_PI))};
}
