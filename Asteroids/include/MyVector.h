#ifndef MY_VECTOR_H
#define MY_VECTOR_H

struct MyVector
{
	double x;
	double y;

	void operator+=(MyVector const& vector2);
	void operator-=(MyVector const& vector2);
	MyVector operator*(double const& coeff) const;
	static MyVector direction(double const& size, double const& angle);
};

#endif
