#ifndef FAMILYVEHICLESTRATEGY_H
#define FAMILYVEHICLESTRATEGY_H

#include <iostream>

class Vehicle
{
public:
    virtual void useVehicle() = 0;
};

class FordFigo : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Driving FordFigo" << std::endl;
    }
};

class TataNano : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Driving TataNano" << std::endl;
    }
};

class BlackPulsar : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Riding BlackPulsar" << std::endl;
    }
};

class HondaActiva : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Riding HondaActiva" << std::endl;
    }
};

class Family
{
public:
    Vehicle *myVehicle;
    virtual void display() = 0;
    void setVehicle(Vehicle *v)
    {
        myVehicle = v;
    }
    void driveVehicle()
    {
        myVehicle->useVehicle();
    }
};

class Father : public Family
{
public:
    virtual void display()
    {
        std::cout << "I am Father" << std::endl;
    }
};

class Mother : public Family
{
public:
    virtual void display()
    {
        std::cout << "I am Mother" << std::endl;
    }
};


class Son : public Family
{
public:
    virtual void display()
    {
        std::cout << "I am Son" << std::endl;
    }
};


class Daughter : public Family
{
public:
    virtual void display()
    {
        std::cout << "I am Daughter" << std::endl;
    }
};

#endif // FAMILYVEHICLESTRATEGY_H
