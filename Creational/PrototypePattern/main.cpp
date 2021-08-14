#include "Prototype.h"
#include <QObject>

//https://gist.github.com/pazdera/1122349

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    ObjectFactory::initialize();
    Prototype *object;

    /* All the object were created by cloning the prototypes. */
    object = ObjectFactory::getType1Value1();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType1Value2();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType2Value1();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;

    object = ObjectFactory::getType2Value2();
    std::cout << object->getType() << ": " << object->getValue() << std::endl;



    //    //Deep copy test
    //    Prototype *objectMain = new ConcretePrototype1(5);
    //    Prototype *objectDeepClone = objectMain->clone();
    //    objectMain->setValue(50);

    //    std::cout<<objectMain->getValue()<<"---"<<objectDeepClone->getValue();

    return 0;
}
