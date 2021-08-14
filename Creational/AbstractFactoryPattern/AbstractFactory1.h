#ifndef ABSTRACTFACTORY1_H
#define ABSTRACTFACTORY1_H

#include <QtDebug>

namespace AbstractFactory1
{

class Shape
{
public:
    Shape()
    {
        id_ = total_++;
    }

    virtual void draw() = 0;

protected:
    int id_;
    static int total_;
};
int Shape::total_ = 0;



class Circle : public Shape
{
public:
    void draw()
    {
        qDebug() << "circle " << id_ << ": draw";
    }
};

class Square : public Shape
{
public:
    void draw()
    {
        qDebug() <<"square " << id_ << ": draw";
    }
};

class Ellipse : public Shape
{
public:
    void draw()
    {
        qDebug() <<"ellipse " <<id_ <<": draw";
    }
};

class Rectangle : public Shape
{
public:
    void draw()
    {
        qDebug() << "rectangle " << id_ << ": draw";
    }
};



class Factory
{
public:
    virtual Shape *createCurvedInstance() = 0;
    virtual Shape *createStraightInstance() = 0;
};

class SimpleShapeFactory : public Factory
{
public:
    Shape *createCurvedInstance()
    {
        return new Circle;
    }

    Shape *createStraightInstance()
    {
        return new Square;
    }
};

class RobustShapeFactory : public Factory
{
public:
    Shape *createCurvedInstance()
    {
        return new Ellipse;
    }

    Shape *createStraightInstance()
    {
        return new Rectangle;
    }
};

}

#endif // ABSTRACTFACTORY1_H
