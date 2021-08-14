#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <vector>
using namespace std;

namespace Observer1ns
{

class AlarmListener
{
public:
    virtual void alarm() = 0;
};


class SensorSystem
{
public:
    void attach(AlarmListener *al)
    {
        listeners.push_back(al);
    }

    void soundTheAlarm()
    {
        for (size_t i = 0; i < listeners.size(); i++)
        {
            listeners[i]->alarm();
        }
    }

private:
    vector <AlarmListener *> listeners;
};


class Lighting: public AlarmListener
{
public:
    /*virtual*/void alarm()
    {
        cout << "lights up" << '\n';
    }
};


class Gates: public AlarmListener
{
public:
    /*virtual*/void alarm()
    {
        cout << "gates close" << '\n';
    }
};


class CheckList
{
private:
    virtual void localize()
    {
        cout << "   establish a perimeter" << '\n';
    }
    virtual void isolate()
    {
        cout << "   isolate the grid" << '\n';
    }
    virtual void identify()
    {
        cout << "   identify the source" << '\n';
    }

public:
    void byTheNumbers()
    {
        // Template Method design pattern
        localize();
        isolate();
        identify();
    }
};


// class inheri.  // type inheritance
class Surveillance: public CheckList, public AlarmListener
{
public:
    /*virtual*/void alarm()
    {
        cout << "Surveillance - by the numbers:" << '\n';
        byTheNumbers();
    }

private:
    /*virtual*/void isolate()
    {
        cout << "   train the cameras" << '\n';
    }
};

}

#endif // OBSERVER_H
