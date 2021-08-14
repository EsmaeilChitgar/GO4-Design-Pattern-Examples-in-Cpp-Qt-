#ifndef STATICDECORATOR_H
#define STATICDECORATOR_H

#include <iostream>
#include <string>

struct CircleS
{
    float radius = 10.0f;

    void resize(const float factor)
    {
        radius *= factor;
    }
    std::string str()
    {
        return std::string("A circle of radius ") + std::to_string(radius);
    }
};

template <typename T> struct ColoredShapeS : T
{
    std::string color;

    ColoredShapeS(const std::string& clr)
    {
        color = clr;
    }
    std::string str()
    {
        return T::str() + " which is colored " + color;
    }
};

#endif // STATICDECORATOR_H
