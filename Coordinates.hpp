#pragma once

#include "Vector.hpp"

class Coordinates
{
public:
    static void initiateSpace(int, int); 
    static inline int getWidthSpace() { return widthSpace; };
    static inline int getHeightSpace() { return heightSpace; };
    Coordinates();
    Coordinates(float, float);

    inline float getX() const { return x; };
    inline float getY() const { return y; };

    void operator+=(Vector const&);
    float calculateDistance(Coordinates const&) const;

private:
    void calculateBack();
    float x{ widthSpace / 2.f };
    float y{ heightSpace / 2.f };
    
    static int widthSpace;
    static int heightSpace;
};
