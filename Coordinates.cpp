#include <iostream>
#include <cmath>
#include <algorithm>
#include "Coordinates.hpp"

int Coordinates::widthSpace{ 0 };
int Coordinates::heightSpace{ 0 };

Coordinates::Coordinates() 
{
    if (widthSpace == 0 || heightSpace == 0) 
    {
        std::cerr << "[ERROR] A coordinate has been create before space !" << std::endl;
    }
}

Coordinates::Coordinates(float posX, float posY) : x(posX), y(posY)
{
    calculateBack();
}

void Coordinates::operator+=(Vector const& vector) 
{
    x += vector.x;
    y += vector.y;
    calculateBack();
}

void Coordinates::initiateSpace(int width, int height) 
{
    if (widthSpace != 0 || heightSpace != 0) 
    {
        std::cerr << "[ERROR] Space was already initiate !" << std::endl;
    }
    widthSpace = width;
    heightSpace = height;
}

void Coordinates::calculateBack() 
{
    while (x > widthSpace) 
    {
        x -= widthSpace;
    }
    while (x < 0) 
    {
        x += widthSpace;
    }
    while (y > heightSpace)
    {
        y -= heightSpace;
    }
    while (y < 0) 
    {
        y += heightSpace;
    }
}

float Coordinates::calculateDistance(Coordinates const& coordinates) const 
{
    auto delta = Vector{ std::min({abs(x - coordinates.x), abs(x - coordinates.x - widthSpace), abs(x - coordinates.x + widthSpace)}), std::min({abs(y - coordinates.y), abs(y - coordinates.y - heightSpace), abs(y - coordinates.y + heightSpace)}) };
    return sqrt(delta.x * delta.x + delta.y * delta.y);
}
