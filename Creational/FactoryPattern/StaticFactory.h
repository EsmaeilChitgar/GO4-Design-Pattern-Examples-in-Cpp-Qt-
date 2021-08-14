#ifndef STATICFACTORY_H
#define STATICFACTORY_H

#include <QString>

namespace StaticFactory
{

// Abstract Base Class
class Shape
{
public:
    virtual void draw() = 0;

    // Static class to create objects
    // Change is required only in this function to create a new object type
    static Shape *Create(QString type);
};


class Circle : public Shape
{
public:
    void draw() { qDebug() <<__FUNCTION__ <<"I am circle"; }

    friend class Shape;
};



class Square : public Shape
{
public:
    void draw() { qDebug() <<__FUNCTION__ <<"I am square"; }

    friend class Shape;
};



Shape *Shape::Create(QString type)
{
    if (type == "circle")
        return new Circle();

    if (type == "square")
        return new Square();

    return nullptr;
}



}

#endif // STATICFACTORY_H
