#ifndef PROTOTYPE_H
#define PROTOTYPE_H
#include <iostream>
#include <string>

/* Prototype base class. */
class Prototype
{
protected:
    std::string type;
    int value;

public:
    //Implements deep copy method
    virtual Prototype *clone() = 0;

    std::string getType()
    {
        return type;
    }

    int getValue()
    {
        return value;
    }

    void setValue(int val)
    {
        value = val;
    }
};

class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1(int number)
    {
        type  = "Type1";
        value = number;
    }

    Prototype *clone()
    {
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2 : public Prototype
{
public:
    ConcretePrototype2(int number)
    {
        type  = "Type2";
        value = number;
    }

    Prototype *clone()
    {
        return new ConcretePrototype2(*this);
    }
};

/* Factory that manages prorotype instances and produces their clones. */
class ObjectFactory
{
    static Prototype *type1value1;
    static Prototype *type1value2;
    static Prototype *type2value1;
    static Prototype *type2value2;

public:
    static void initialize()
    {
        type1value1 = new ConcretePrototype1(1);
        type1value2 = new ConcretePrototype1(2);
        type2value1 = new ConcretePrototype2(1);
        type2value2 = new ConcretePrototype2(2);
    }

    static Prototype* getType1Value1()
    {
        return type1value1->clone();
    }

    static Prototype* getType1Value2()
    {
        return type1value2->clone();
    }

    static Prototype* getType2Value1()
    {
        return type2value1->clone();
    }

    static Prototype* getType2Value2()
    {
        return type2value2->clone();
    }
};

Prototype *ObjectFactory::type1value1 = nullptr;
Prototype *ObjectFactory::type1value2 = nullptr;
Prototype *ObjectFactory::type2value1 = nullptr;
Prototype *ObjectFactory::type2value2 = nullptr;

#endif // PROTOTYPE_H


