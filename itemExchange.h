#ifndef ITEMEXCHANGE_H_INCLUDED
#define ITEMEXCHANGE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

class Item{
public:
    Item(char *name0 = (char*)"*", char *owner0 = (char*)"*", char *address0 = (char*)"*", char *phoneNumber0 = (char*)"*");
    void display() const;
    bool ifSameName (char *name0) const;
    bool ifSameOwner(char *owner0) const;
    bool ifSameAddress(char *address0) const;

private:
    char name[21];
    char owner[9];
    char address[40];
    char phoneNumber[12];

};

void addItem();
bool delItem();
void displayAll();
bool searchItem(int mode);

#endif // ITEMEXCHANGE_H_INCLUDED
