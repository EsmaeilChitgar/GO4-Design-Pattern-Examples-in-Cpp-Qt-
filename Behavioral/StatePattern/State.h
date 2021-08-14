#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;

class Machine
{
    class State *currentState;

public:
    Machine();

    void setCurrent(State *s)
    {
        currentState = s;
    }

    void on();

    void off();
};

class State
{
public:
    virtual void on(Machine *m)
    {
        cout << "   already ON\n";
    }

    virtual void off(Machine *m)
    {
        cout << "   already OFF\n";
    }
};

void Machine::on()
{
    currentState->on(this);
}

void Machine::off()
{
    currentState->off(this);
}

class ON: public State
{
public:
    ON()
    {
        cout << "   ON-ctor ";
    }

    ~ON()
    {
        cout << "   dtor-ON\n";
    }

    void off(Machine *m);
};

class OFF: public State
{
public:
    OFF()
    {
        cout << "   OFF-ctor ";
    }

    ~OFF()
    {
        cout << "   dtor-OFF\n";
    }

    void on(Machine *m)
    {
        cout << "   going from OFF to ON";
        m->setCurrent(new ON());

        delete this;
    }
};

void ON::off(Machine *m)
{
    cout << "   going from ON to OFF";
    m->setCurrent(new OFF());
    delete this;
}

Machine::Machine()
{
    currentState = new OFF();
    cout << '\n';
}

#endif // STATE_H
