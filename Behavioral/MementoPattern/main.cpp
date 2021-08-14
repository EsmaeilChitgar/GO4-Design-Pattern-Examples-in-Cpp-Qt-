#include <QApplication>

#include "Memento.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    int i;
      cout << "Integer: ";
      cin >> i;
      Number *object = new Number(i);

      Command *commands[3];
      commands[1] = new Command(object, &Number::dubble);
      commands[2] = new Command(object, &Number::half);

      cout << "Exit[0], Double[1], Half[2], Undo[3], Redo[4]: ";
      cin >> i;

      while (i)
      {
        if (i == 3)
          Command::undo();
        else if (i == 4)
          Command::redo();
        else
          commands[i]->execute();
        cout << "   " << object->getValue() << endl;
        cout << "Exit[0], Double[1], Half[2], Undo[3], Redo[4]: ";
        cin >> i;
      }

    return 0;
}
