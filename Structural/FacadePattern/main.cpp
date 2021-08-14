#include <QApplication>

#include "FileTransferFacade.h"
#include "ComputerFacade.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    cout<<"FileTransfer played.......\n";
    unique_ptr<FileTransfer> ft(new FileTransfer());
    ft->sendFile("mypicture");


    cout<<"\nComputerFacade played.......\n";
    ComputerFacade computer;
    computer.start();

    return 0;
}
