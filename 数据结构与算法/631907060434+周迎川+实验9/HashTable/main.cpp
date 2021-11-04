#include <iostream>
#include "hashtable.h"
#include "hashtable.cpp"
#include "hashtable_close.h"
#include "hashtable_close.cpp"
using namespace std;

int main()
{
    cout<<"Open HashTable"<<endl;
    HashTable<long long> H(1000000000);
    H.Insert(17384017268,"zhou","chongqing");
    H.Insert(13320301731,"zhou","chongqing");
    H.Insert(15502324093,"wang","chongqing");
    H.Insert(13572955710,"zeng","chongqing");
    H.Remove(13320301731);
    if(H.Search(17384017268))
    {
       cout<<"find successfully"<<endl;
    }
    else
       cout<<"Not Found"<<endl;
    H.Display();
    cout<<"Closed HashTable"<<endl;
    HashTable_C<long  long> HC(1000000000);
    HC.Insert(17384017268,"zhou","chongqing");
    HC.Insert(13320301731,"zhou","chongqing");
    HC.Insert(15502324093,"wang","chongqing");
    HC.Insert(13572955710,"zeng","chongqing");
    HC.Remove(13320301731);
    if(HC.Search(17384017268))
    {
     cout<<"find successfully"<<endl;
    }
    else
        cout<<"Not Found"<<endl;
    HC.Display();
    return 0;
}
