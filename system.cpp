#include "itemExchange.h"

void addItem()
{
   char name0[21];
   char owner0[9];
   char address0[40];
   char phoneNumber0[12];
   cout << "请输入物品名:\n";
   cin >> name0;
   cout << "请输入所有人:\n";
   cin >> owner0;
   cout << "请输入地址（小区）:\n";
   cin >> address0;
   cout << "请输入手机号:\n";
   cin >> phoneNumber0;
   Item newItem(name0, owner0, address0, phoneNumber0);

   fstream iofile("itemFile.txt");
   Item currentItem;

   int pos = 0;
   iofile.seekg(0);
   iofile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
   while (!iofile.eof())
   {
       if(currentItem.ifSameName((char*)"*"))
       {
           iofile.seekp(pos * sizeof(Item));
           iofile.write(reinterpret_cast<char *> (&newItem), sizeof(Item));
           iofile.close();
           return;
       }
       pos++;
       iofile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
   }

   iofile.clear();  //删除读空文件的置错
   iofile.seekp(0,ios::end);
   iofile.write(reinterpret_cast<char *> (&newItem), sizeof(Item));
   iofile.close();
}

void displayAll()
{
   ifstream infile("itemFile.txt");
   Item currentItem;

   infile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
   while (!infile.eof())
   {
       currentItem.display();
       infile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
   }

   infile.close();
}

bool searchItem(int mode)
{
   if (mode == 1)
   {
        char name0[21];
        cout << "请输入物品名:"<<endl;
        cin >> name0;

        ifstream infile("itemFile.txt");
        Item currentItem;
        bool ifExist = 0;

        infile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
        while (!infile.eof())
        {
            if(currentItem.ifSameName(name0))
            {
               currentItem.display();
               ifExist = 1;
             }
             infile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
         }

         infile.close();
         return ifExist;
    }
    else if (mode == 2)
    {
        char address0[40];
        cout << "请输入小区名:"<<endl;
        cin >> address0;

        ifstream infile("itemFile.txt");
        Item currentItem;
        bool ifExist = 0;

        infile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
        while (!infile.eof())
        {
            if(currentItem.ifSameAddress(address0))
            {
               currentItem.display();
               ifExist = 1;
             }
             infile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
         }

         infile.close();
         return ifExist;
    }
    else return 0;
}

bool delItem()
{
   char name0[21];
   char owner0[9];
   char address0[40];
   char phoneNumber0[12];
   cout << "请输入物品名:\n";
   cin >> name0;
   cout << "请输入所有人:\n";
   cin >> owner0;

   fstream iofile("itemFile.txt");
   Item currentItem;
   int  pos = 0;

   iofile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
   while (!iofile.eof())
   {
       if(currentItem.ifSameName(name0) && currentItem.ifSameOwner(owner0))
       {
           iofile.seekp(pos * sizeof(Item));
           iofile.write(reinterpret_cast<const char *> ("*"), sizeof(name0));
           iofile.write(reinterpret_cast<const char *> ("*"), sizeof(owner0));
           iofile.write(reinterpret_cast<const char *> ("*"), sizeof(address0));
           iofile.write(reinterpret_cast<const char *> ("*"), sizeof(phoneNumber0));
           iofile.close();
           return 1;
       }
       pos++;
       iofile.seekg(pos * sizeof(Item));
       iofile.read(reinterpret_cast<char *> (&currentItem), sizeof(Item));
   }

   iofile.close();
   return 0;
}
