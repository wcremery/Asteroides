#pragma once

#include "MyVector.h"

class Coordinates
{
public:
    // Constructors
    Coordinates();
    Coordinates(double const& p_x, double const& p_y);
    // Getters
    float X();
    float Y();
    // Class methods
    static void initialize_space(int const& p_width, int const& p_height);
    void operator+=(MyVector const& p_vector);
    double computeDistance(Coordinates coordinates) const;

private:
    // Attributes
    double x_;
    double y_;
    // Class attributes
    static double width;
    static double height;
};