#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

struct Vector
{
	void operator+=(Vector const& vector);
	void operator-=(Vector const& vector);
	Vector operator*(float coeff) const;
	static Vector createFromAngle(float size, float angle);
	float x{ 0.f };
	float y{ 0.f };
};
