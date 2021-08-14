#include <QApplication>
#include <memory>

#include "Command1.h"
#include "Command2.h"

#include <QtDebug>

using namespace Command1;
using namespace Command2;

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    cout<<endl<<"Command1 playing................."<<endl;
    StockTrade stock;
    BuyOrder buy1(&stock);
    BuyOrder buy2(&stock);
    SellOrder sell1(&stock);

    StockAgent agent;
    agent.order(&buy1);
    agent.order(&buy2);
    agent.order(&sell1);


    cout<<endl<<"Command2 playing................."<<endl;

    //    std::unique_ptr<Light> light = std::make_unique<Light>();
    //    std::unique_ptr<ICommand> switchOn (new FlipUpCommand(light.get()));
    //    std::unique_ptr<ICommand> switchDown (new FlipDownCommand(light.get()));

    //    std::unique_ptr<Switcher> switcher = std::make_unique<Switcher>();
    //    switcher->StoreAndExecute(switchOn.get());
    //    switcher->StoreAndExecute(switchDown.get());


    Light *light = new Light;
    ICommand *switchOn = new FlipUpCommand(light);
    ICommand *switchDown = new FlipDownCommand(light);

    Switcher *switcher = new Switcher;
    switcher->StoreAndExecute(switchOn);
    switcher->StoreAndExecute(switchDown);

    return 0;
}
