#ifndef OBSERVER2_H
#define OBSERVER2_H

#include <iostream>
#include <vector>
using namespace std;

namespace Observer2ns
{
class Observer2;

class Subject
{
public:
    void attach(Observer2 *obs)
    {
        views.push_back(obs);
    }

    void setVal(int val)
    {
        value = val;

        notify();
    }

    int getVal()
    {
        return value;
    }

    void notify();

private:
    // 1. "independent" functionality
    vector < class Observer2 * > views; // 3. Coupled only to "interface"
    int value;
};


class Observer2
{
public:
    Observer2(Subject *mod, int div)
    {
        model = mod;
        denom = div;
        // 4. Observers register themselves with the Subject
        model->attach(this);
    }

    virtual void update() = 0;

protected:
    Subject *getSubject()
    {
        return model;
    }

    int getDivisor()
    {
        return denom;
    }

private:
    // 2. "dependent" functionality
    Subject *model;
    int denom;
};


void Subject::notify()
{
    // 5. Publisher broadcasts
    for (size_t i = 0; i < views.size(); i++)
    {
        views[i]->update();
    }
}


class DivObserver: public Observer2
{
public:
    DivObserver(Subject *mod, int div): Observer2(mod, div)
    {

    }

    void update()
    {
        // 6. "Pull" information of interest
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " div " << d << " is " << v / d << '\n';
    }
};


class ModObserver: public Observer2
{
public:
    ModObserver(Subject *mod, int div): Observer2(mod, div)
    {

    }

    void update()
    {
        int v = getSubject()->getVal(), d = getDivisor();
        cout << v << " mod " << d << " is " << v % d << '\n';
    }
};

}
#endif // OBSERVER2_H
