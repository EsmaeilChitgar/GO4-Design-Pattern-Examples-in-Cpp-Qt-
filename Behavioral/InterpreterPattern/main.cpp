#include "Interpreter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    RNInterpreter interpreter;
    char input[20];
    std::cout << "Enter Roman Numeral: ";
    while (std::cin >> input)
    {
        std::cout << "   interpretation is " << interpreter.interpret(input) << std::endl;
        std::cout << "Enter Roman Numeral: ";
    }

    return 0;
}
