#include <AbstractFactory1.h>
#include <AbstractFactory2.h>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)


    //    //Abstract Factory 1.....................................................................
#ifdef SIMPLE
    AbstractFactory1::Factory *factory1 = new AbstractFactory1::SimpleShapeFactory;
#else
    AbstractFactory1::Factory *factory1 = new AbstractFactory1::RobustShapeFactory;
#endif
    AbstractFactory1::Shape *shapes[3];

    shapes[0] = factory1->createCurvedInstance();   // shapes[0] = new Ellipse;
    shapes[1] = factory1->createStraightInstance(); // shapes[1] = new Rectangle;
    shapes[2] = factory1->createCurvedInstance();   // shapes[2] = new Ellipse;

    for (int i = 0; i < 3; i++)
    {
        shapes[i]->draw();
    }




  //Abstract Factory 2.....................................................................
    AbstractFactory2::Factory *factory;
    #ifdef Q_OS_WIN
    factory = new AbstractFactory2::WindowsFactory;
    #else
    factory = new AbstractFactory2::LinuxFactory;
    #endif

      AbstractFactory2::Client *c = new AbstractFactory2::Client(factory);
      c->draw();


    return 0;
}
