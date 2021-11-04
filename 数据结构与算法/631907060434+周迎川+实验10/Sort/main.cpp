#include <iostream>
#include <cmath>
#include <time.h>
#include "sort.h"
#include "sort.cpp"
using namespace std;
int main()
{
   SeqList<int> SL;
   SeqList<int> SL2;
   SeqList<int> SL3;
   SeqList<int> SL4;
   SeqList<int> SL5;
   int account=0;
   srand((unsigned)time(nullptr));
   for(int i=0;i<100;i++)
   {
       int x=rand()%1000;
       SL.Push_back(x);
       SL3.Push_back(x);
       SL4.Push_back(x);
       SL5.Push_back(x);
   }
   SL.Display();
   cout<<"交换排序"<<endl;
   ChangeSort(SL,0,99);//对
   SL.Display();
   cout<<endl;
   SL3.Display();
   cout<<"选择排序"<<endl;
   SelectSort(SL3,0,99);//对
   SL3.Display();
   cout<<endl;
   SL4.Display();
   cout<<"插入排序"<<endl;
   InserSort(SL4,0,99);//对
   SL4.Display();
   cout<<endl;
   SL5.Display();
   cout<<"归并排序"<<endl;
   MergeSort(SL5,SL2,0,99,account);//对
   cout<<"交换次数"<<account<<endl;
   SL5.Display();
   return 0;
}
