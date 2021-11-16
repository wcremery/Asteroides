#include "../include/Coordinates.h"
#include <cmath>
#include <algorithm>

// class attributes (static) need to be initialize in cpp file !!!
double Coordinates::width{ 0 };
double Coordinates::height{ 0 };

Coordinates::Coordinates()
{
    x_ = width / 2;
    y_ = height / 2;
}

Coordinates::Coordinates(double const& p_x, double const& p_y)
{
    x_ = static_cast<int>(p_x) % static_cast<int>(width);
    y_ = static_cast<int>(p_y) % static_cast<int>(height);
}

float Coordinates::X()
{
    return x_;
}

float Coordinates::Y()
{
    return y_;
}

void Coordinates::initialize_space(int const& p_width, int const& p_height)
{
    height = p_height;
    width = p_width;
}

void Coordinates::operator+=(MyVector const& p_vector)
{
    x_ = std::fmod(width + x_ + p_vector.x, width);
    y_ = std::fmod(height + y_ + p_vector.y, height);
}

double Coordinates::computeDistance(Coordinates coordinates) const
{
    const auto delta = MyVector{std::min({abs(coordinates.X() - x_), abs(coordinates.X() - x_ - width), abs(coordinates.X() - x_ + width)}), std::min({abs(coordinates.Y() - y_), abs(coordinates.Y() - y_ - height), abs(coordinates.Y() - y_ + height)}) };
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}