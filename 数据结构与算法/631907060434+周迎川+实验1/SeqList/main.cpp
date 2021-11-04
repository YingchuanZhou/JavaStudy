#include <iostream>
#include <iomanip>
#include "seqlist.h"
#include "seqlist.cpp"
#include "student.h"
#include "student.cpp"
using namespace std;
void menu()
{
    cout<<"1、计算表的长度"<<endl;
    cout<<"2、搜索指定元素"<<endl;
    cout<<"3、搜索指定位置的元素"<<endl;
    cout<<"4、在尾部插入元素"<<endl;
    cout<<"5、在指定位置插入元素"<<endl;
    cout<<"6、删除指定元素"<<endl;
    cout<<"7、删除指定位置元素"<<endl;
    cout<<"8、遍历整个表"<<endl;
    cout<<"9、保存文件"<<endl;
    cout<<"0、退出"<<endl;
    cout<<"请选择......"<<endl;
}
int main()
{
//    SeqList<int> L(100);
//    cout<<"read file..."<<endl;
//    L.ReadFile("E:\\Qtprojects\\SeqList\\SeqListdata.txt");
//    L.Display(0,L.Getnum()-1);
//    cout<<"length:"<<endl;
//    int i=L.Length();
//    cout<<i<<endl;
//    cout<<"search"<<endl;
//    int j=3;
//    i=L.Search(j);
//    cout<<"3元素是第"<<i<<"个元素"<<endl;
//    cout<<"尾部插入元素"<<endl;
//    L.Push_back(5);
//    L.Display(0,L.Getnum()-1);
//    cout<<"删除第3个元素"<<endl;
//    L.RemovePos(3);
//    L.Display(0,L.Getnum()-1);
//    j=4;
//    L.Remove(j);
//    L.Display(0,L.Getnum()-1);
//    cout<<"在第3个元素位置插入6"<<endl;
//    L.Insert(2,6);
//    L.Display(0,L.Getnum()-1);
//    SeqList<Student> Ls(100);
//    cout<<"read file..."<<endl;
//    Ls.ReadFile("E:\\Qtprojects\\SeqList\\SeqListStudent.txt");
//    Ls.Display(0,L.Getnum()-1);
//    cout<<"length:"<<endl;
//    i=Ls.Length();
//    cout<<i<<endl;
//    cout<<"search"<<endl;
//    Student s("631907060434","zhouyingchuan");
//    i=Ls.Search(s);
//    cout<<"该元素是第"<<i<<"个元素"<<endl;
//    cout<<"尾部插入元素"<<endl;
//    Student s1("631907060555","zhangsan");
//    Ls.Push_back(s1);
//    Ls.Display(0,Ls.Getnum()-1);
//    cout<<"删除第3个元素"<<endl;
//    Ls.RemovePos(3);
//    Ls.Display(0,Ls.Getnum()-1);
//    Ls.Remove(s);
//    Ls.Display(0,Ls.Getnum()-1);
//    cout<<"在第3个元素位置插入s1"<<endl;
//    Ls.Insert(2,s1);
//    Ls.Display(0,Ls.Getnum()-1);
    SeqList<int> L(100);
    SeqList<Student> Ls(100);
    int i,j;string flag;
    Student s,s1;
    string id,name;
    L.ReadFile("E:\\Qtprojects\\SeqList\\SeqListdata.txt");
    Ls.ReadFile("E:\\Qtprojects\\SeqList\\SeqListStudent.txt");
    cout<<"输入数据类型int or Student"<<endl;
    cin>>flag;
    if(flag=="int")
    {
    while(1)
    {
    menu();
    int choice;//保存选择
    cin>>choice;
    switch(choice)
    {
        case 1:
            i=L.Length();
            cout<<"表的长度为："<<i<<endl;
        break;
        case 2:
            cout<<"输入一个元素"<<endl;
            cin>>i;
            j=L.Search(i);
            if(j==-1)
                break;
            cout<<i<<"元素是第"<<j<<"个元素"<<endl;
        break;
        case 3:
            cout<<"输入一个位置"<<endl;
            cin>>i;
            j=L.Get(i);
            cout<<"第"<<i<<"个元素是"<<j<<endl;
        break;
        case 4:
            cout<<"输入要插入的整数元素"<<endl;
            cin>>i;
            L.Push_back(i);
            L.Display(0,L.Getnum()-1);
        break;
        case 5:
            cout<<"输入要插入的位置"<<endl;
            cin>>i;
            cout<<"输入要插入的元素"<<endl;
            cin>>j;
            L.Insert(i,j);
            L.Display(0,L.Getnum()-1);
        break;
        case 6:
            cout<<"输入要删除的元素"<<endl;
            cin>>i;
            L.Remove(i);
            L.Display(0,L.Getnum()-1);
        break;
        case 7:
            cout<<"输入要删除的元素位置"<<endl;
            cin>>i;
            L.RemovePos(i);
            L.Display(0,L.Getnum()-1);
        break;
        case 8:
            cout<<"全部数据"<<endl;
            L.Display(0,L.Getnum()-1);
        break;
        case 9:
            L.SaveFile("E:\\Qtprojects\\SeqList\\SeqListdata.txt");
            break;
        case 0:
            exit(0);
    }
    }
    }
    else if(flag=="Student")
    {
    while(1)
    {
    menu();
    int choice;//保存选择
    cin>>choice;
    switch(choice)
    {
        case 1:
            i=Ls.Length();
            cout<<"表的长度为："<<i<<endl;
        break;
        case 2:
            cout<<"输入一个学生的学号"<<endl;
            cin>>id;
            cout<<"输入一个学生的名字"<<endl;
            cin>>name;
            s.setIdName(id,name);
            j=Ls.Search(s);
            cout<<s<<"学生是第"<<j<<"个学生"<<endl;
        break;
        case 3:
            cout<<"输入一个位置"<<endl;
            cin>>i;
            s1=Ls.Get(i);
            cout<<"第"<<i<<"个学生是"<<s1<<endl;
        break;
        case 4:
            cout<<"输入要插入的学生学号"<<endl;
            cin>>id;
            cout<<"输入要插入的学生姓名"<<endl;
            cin>>name;
            s.setIdName(id,name);
            Ls.Push_back(s);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 5:
            cout<<"输入要插入的位置"<<endl;
            cin>>i;
            cout<<"输入要插入的学生学号"<<endl;
            cin>>id;
            cout<<"输入要插入的学生姓名"<<endl;
            cin>>name;
            s1.setIdName(id,name);
            Ls.Insert(i,s1);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 6:
            cout<<"输入要删除的学生学号"<<endl;
            cin>>id;
            cout<<"输入要删除的学生姓名"<<endl;
            cin>>name;
            s.setIdName(id,name);
            Ls.Remove(s);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 7:
            cout<<"输入要删除的学生位置"<<endl;
            cin>>i;
            Ls.RemovePos(i);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 8:
            cout<<"全部学生数据"<<endl;
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 9:
            Ls.SaveFile("E:\\Qtprojects\\SeqList\\SeqListStudent.txt");
            break;
        case 0:
            exit(0);
    }
    }
    }
    else
    return 0;
}
