#include "itemExchange.h"

int main()
{
   int i;
   while (true)
   {
       cout << "请输入：\n";
       cout << "1-添加物品\n";
       cout << "2-删除物品\n";
       cout << "3-显示所有物品\n";
       cout << "4-搜索物品\n";
       cin >> i;
       switch (i)
       {
            case 1:addItem();break;
            case 2:
            {
                if(delItem()) cout<<"物品已删除\n";
                else cout<<"物品不存在\n";
                break;
            }
            case 3:displayAll();break;
            case 4:
            {
                cout << "请输入：\n";
                cout << "1-按物品名搜索\n";
                cout << "2-按小区搜索\n";
                cin >> i;
                if(!searchItem(i)) cout<<"物品不存在\n";
                break;
            }
       }

   }

   return 0;
}
