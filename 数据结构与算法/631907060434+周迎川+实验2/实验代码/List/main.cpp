#include <iostream>
#include "list.h"
#include "list.cpp"
#include "student.h"
#include "student.cpp"
using namespace std;

int main()
{
    //²âÊÔint
    List<int> L;
    cout<<"Push back"<<endl;
    L.Push_back(10);
    cout<<"read file..."<<endl;
    L.ReadFile("E:\\Qtprojects\\List\\SeqListdata.txt");
   // cout<<"1"<<endl;
    cout<<"length"<<endl;
    cout<<L.Length()<<endl;
    cout<<"Find(0)"<<endl;
    int i=L.Find(0);
    cout<<i<<endl;
    cout<<"Insert(4,8)"<<endl;
    L.Insert(4,8);
    L.Display();
    cout<<"Rmove(5)"<<endl;
    L.Remove(5);
    L.Display();
    cout<<"pop"<<endl;
    L.Pop();
    L.Display();
    cout<<"make Empty"<<endl;
    L.makeEmpty();
    cout<<L.isEmpty()<<endl;
    //L.SaveFile("E:\\Qtprojects\\List\\SeqListdata.txt");
    cout<<"int over"<<endl;


    //²âÊÔstudent
    List<Student> Ls;
    cout<<"Push back"<<endl;
    Student s("66666","wang");
    Student s1("631907060434","zhouyingchuan");
    Student s2("630707060434","dong");
    Ls.Push_back(s);
    cout<<"read file..."<<endl;
    Ls.ReadFile("E:\\Qtprojects\\List\\SeqLIstStudent.txt");
   // cout<<"1"<<endl;
    cout<<"length"<<endl;
    cout<<Ls.Length()<<endl;
    cout<<"Find(s1)"<<endl;
    i=Ls.Find(s1);
    cout<<i<<endl;
    cout<<"Insert(4,s2)"<<endl;
    Ls.Insert(4,s2);
    Ls.Display();
    cout<<"Rmove(s1)"<<endl;
    Ls.Remove(s1);
    Ls.Display();
    cout<<"pop"<<endl;
    Ls.Pop();
    Ls.Display();
    cout<<"make Empty"<<endl;
    Ls.makeEmpty();
    cout<<Ls.isEmpty()<<endl;
    Ls.SaveFile("E:\\Qtprojects\\List\\SeqLIstStudent.txt");
    cout<<"student over"<<endl;
    return 0;
}
