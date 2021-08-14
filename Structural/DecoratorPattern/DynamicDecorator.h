#ifndef DYNAMICDECORATOR_H
#define DYNAMICDECORATOR_H

#include <iostream>
#include <string>


//Interface component
struct Shape
{
  virtual std::string str() = 0;
};

//Concrete component
struct CircleD : Shape
{
  float radius = 10.0f;

  void resize(const float factor)
  {
    radius *= factor;
  }

  std::string str() override
  {
    return std::string("A circle of radius ") + std::to_string(radius);
  }
};

//Decorator
//Not exist

//Concrete decorator
struct ColoredShapeD : Shape
{
  std::string color;
  Shape *shape;

  ColoredShapeD(const std::string &clr, Shape *shp)
  {
    color = clr;
    shape = shp;
  }

  std::string str() override
  {
    return shape->str() + std::string(" which is coloured ") + color;
  }
};

#endif // DYNAMICDECORATOR_H
