#ifndef COMMAND1_H
#define COMMAND1_H

#include <vector>

#include <iostream>
using namespace std;

//http://myprogrammingworks.blog.ir/post/%D8%A7%D9%84%DA%AF%D9%88%DB%8C-%D8%B7%D8%B1%D8%A7%D8%AD%DB%8C-Command-%D8%AF%D8%B1-c

namespace Command1
{

//Command interface
class Command
{
  public:
    virtual ~Command() {}
    virtual void execute() = 0;
};


//Invoker
class StockAgent
{
  public:
    void order(Command *command)
    {
        commandList.push_back(command);
        command->execute();
    }

  private:
    vector<Command *> commandList;
};


//Receiver
class StockTrade
{
  public:
    void buy()
    {
        cout << "Buy stock" << endl;
    }

    void sell()
    {
        cout << "Sell stock" << endl;
    }
};


//Concrete command 1
class BuyOrder : public Command
{
  public:
    BuyOrder(StockTrade *stock)
    {
        this->stock = stock;
    }

    void execute() override
    {
        stock->buy();
    }

private:
    StockTrade *stock;
};


//Concrete command 2
class SellOrder : public Command
{
  public:
    SellOrder(StockTrade *stock)
    {
        this->stock = stock;
    }

    void execute() override
    {
        stock->sell();
    }

private:
    StockTrade *stock;
};

}

#endif // COMMAND1_H
