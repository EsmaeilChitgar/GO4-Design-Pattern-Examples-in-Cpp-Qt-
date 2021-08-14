#ifndef COMPUTERFACADE_H
#define COMPUTERFACADE_H

#include <iostream>
#include <memory>
using namespace std;

#define BOOT_ADDRESS    100
#define SECTOR_SIZE     110
#define BOOT_SECTOR     120

class CPU
{
public:
    void freeze() { cout<<"cpu freezed"<<endl; }
    void jump(long position) { cout<<"cpu jumped to "<<position<<endl; }
    void execute() { cout<<"cpu executed"<<endl; }
};

class HardDrive
{
public:
    char* read(long lba, int size) { cout<<"HardDrive read"<<endl; }
};

class Memory
{
public:
    void load(long position, char* data) { cout<<"Memory load"<<endl; }
};

/* Facade */

class ComputerFacade
{
private:
    CPU* processor;
    Memory* ram;
    HardDrive* hd;

public:
    ComputerFacade()
    {
        processor = new CPU();
        ram = new Memory();
        hd = new HardDrive();
    }

    void start()
    {
        processor->freeze();
        ram->load(BOOT_ADDRESS, hd->read(BOOT_SECTOR, SECTOR_SIZE));
        processor->jump(BOOT_ADDRESS);
        processor->execute();
    }

    ~ComputerFacade()
    {
        delete processor;
        delete ram;
        delete hd;
    }
};

#endif // COMPUTERFACADE_H
