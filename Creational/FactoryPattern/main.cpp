#include <QApplication>

#include "AbstractFactory.h"
#include "StaticFactory.h"

int main(int argc, char** argv)
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    //Abstract factory..............................................................................
    AbstractFactory::MobileFactory *mobileFactory = new AbstractFactory::MobileFactory();

    AbstractFactory::Mobile *myMobile1 = mobileFactory->GetMobile("Low-End");
    myMobile1->PrintSpecs();

    AbstractFactory::Mobile *myMobile2 = mobileFactory->GetMobile("High-End");
    myMobile2->PrintSpecs();



    //Static factory..............................................................................
    StaticFactory::Shape *circle = StaticFactory::Shape::Create("circle");
    StaticFactory::Shape *square = StaticFactory::Shape::Create("square");

    circle->draw();
    square->draw();

    return 0;
}
