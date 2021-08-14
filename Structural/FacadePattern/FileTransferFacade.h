#ifndef FILETRANSFERFACADE_H
#define FILETRANSFERFACADE_H

#include <iostream>
#include <memory>
using namespace std;

// Transfer library
class Usb
{
public:
    bool isAvailable() { return false; }
    void connect() { cout << "Connecting via USB" << endl; }
    void send(string file) { cout << file << " sent." << endl; }
};


class Bluetooth
{
public:
    bool isAvailable() { return true; }
    void connect() { cout << "Connecting via BT" << endl; }
    void authenticate() { cout << "Authenticating BT" << endl; }
    void send(string file) { cout << file << " sent." << endl; }
};


// The Facade
class FileTransfer
{
public:
    void sendFile(string fileName)
    {
        shared_ptr<Usb> u(new Usb());
        shared_ptr<Bluetooth> b(new Bluetooth());

        if (u->isAvailable())
        {
            u->connect();
            u->send(fileName);
        }
        else if (b->isAvailable())
        {
            b->connect();
            b->authenticate();
            b->send(fileName);
        }
        else
        {
            cout << "Not sent" << endl;
        }
    }
};

#endif // FILETRANSFERFACADE_H
