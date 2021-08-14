#ifndef COMMAND2_H
#define COMMAND2_H

#include <vector>
#include <iostream>
using namespace std;

//https://en.wikipedia.org/wiki/Command_pattern

namespace Command2
{

//Command interface
class ICommand
{
public:
    virtual void Execute() = 0;
};


//Invoker
class Switcher
{
public:
    void StoreAndExecute(ICommand *command)
    {
        if (command)
        {
            _commands.push_back(command);
            command->Execute();
        }
    }

private:
    std::vector<ICommand *> _commands;
};


//Receiver
class Light
{
public:
    void TurnOn()
    {
        std::cout<<"The light is on."<<std::endl;
    }

    void TurnOff()
    {
        std::cout << "The light is off." << std::endl;
    }
};


//ConcreteCommand #1
class FlipUpCommand : public ICommand
{
public:
    FlipUpCommand(Light *light)
    {
        _light = light;
    }

    void Execute()
    {
        _light->TurnOn();
    }

private:
    Light *_light;
};


//ConcreteCommand #2
class FlipDownCommand : public ICommand
{
public:
    FlipDownCommand(Light *light)
    {
        _light = light;
    }

    void Execute()
    {
        _light->TurnOff();
    }

private:
    Light *_light;
};

}

#endif // COMMAND2_H
