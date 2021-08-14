#include "NodeMediator.h"
#include "FileSelectionDialogMediator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    //    cout<<endl<<"NodeMediator playing.................................."<<endl;
    //    List lst;
    //    Node one(11), two(22);
    //    Node thr(33), fou(44);
    //    lst.add_node(&one);
    //    lst.add_node(&two);
    //    lst.add_node(&thr);
    //    lst.add_node(&fou);
    //    lst.traverse();
    //    lst.remove_node(44);
    //    lst.traverse();
    //    lst.remove_node(22);
    //    lst.traverse();
    //    lst.remove_node(11);
    //    lst.traverse();


    cout<<endl<<"FileSelectionDialogMediator playing.................................."<<endl;
    FileSelectionDialog fileDialog;
    int i;

    cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
    cin >> i;

    while (i)
    {
        fileDialog.handleEvent(i - 1);
        cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
        cin >> i;
    }

    return 0;
}
