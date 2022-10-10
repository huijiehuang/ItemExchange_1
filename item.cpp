#include "itemExchange.h"

Item::Item(char *name0, char *owner0, char *address0, char *phoneNumber0)
{
    strcpy(name,name0);
    strcpy(owner,owner0);
    strcpy(address,address0);
    strcpy(phoneNumber,phoneNumber0);
}


void Item::display() const
{
    if(strcmp(name,"*") != 0)cout<<"物品名："<<name<<" 所有人："<<owner<<" 地址："<<address<<" 手机号："<<phoneNumber<<endl;
}

bool Item::ifSameName (char *name0) const
{
    if (strcmp(name,name0) == 0) return 1;
    else return 0;
}

bool Item::ifSameOwner(char *owner0) const
{
    if (strcmp(owner,owner0) == 0) return 1;
    else return 0;
}

bool Item::ifSameAddress(char *address0) const
{
    if (strcmp(address,address0) == 0) return 1;
    else return 0;
}
