#include <iostream>
#include <iomanip>
#include "seqlist.h"
#include "seqlist.cpp"
#include "student.h"
#include "student.cpp"
using namespace std;
void menu()
{
    cout<<"1�������ĳ���"<<endl;
    cout<<"2������ָ��Ԫ��"<<endl;
    cout<<"3������ָ��λ�õ�Ԫ��"<<endl;
    cout<<"4����β������Ԫ��"<<endl;
    cout<<"5����ָ��λ�ò���Ԫ��"<<endl;
    cout<<"6��ɾ��ָ��Ԫ��"<<endl;
    cout<<"7��ɾ��ָ��λ��Ԫ��"<<endl;
    cout<<"8������������"<<endl;
    cout<<"9�������ļ�"<<endl;
    cout<<"0���˳�"<<endl;
    cout<<"��ѡ��......"<<endl;
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
//    cout<<"3Ԫ���ǵ�"<<i<<"��Ԫ��"<<endl;
//    cout<<"β������Ԫ��"<<endl;
//    L.Push_back(5);
//    L.Display(0,L.Getnum()-1);
//    cout<<"ɾ����3��Ԫ��"<<endl;
//    L.RemovePos(3);
//    L.Display(0,L.Getnum()-1);
//    j=4;
//    L.Remove(j);
//    L.Display(0,L.Getnum()-1);
//    cout<<"�ڵ�3��Ԫ��λ�ò���6"<<endl;
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
//    cout<<"��Ԫ���ǵ�"<<i<<"��Ԫ��"<<endl;
//    cout<<"β������Ԫ��"<<endl;
//    Student s1("631907060555","zhangsan");
//    Ls.Push_back(s1);
//    Ls.Display(0,Ls.Getnum()-1);
//    cout<<"ɾ����3��Ԫ��"<<endl;
//    Ls.RemovePos(3);
//    Ls.Display(0,Ls.Getnum()-1);
//    Ls.Remove(s);
//    Ls.Display(0,Ls.Getnum()-1);
//    cout<<"�ڵ�3��Ԫ��λ�ò���s1"<<endl;
//    Ls.Insert(2,s1);
//    Ls.Display(0,Ls.Getnum()-1);
    SeqList<int> L(100);
    SeqList<Student> Ls(100);
    int i,j;string flag;
    Student s,s1;
    string id,name;
    L.ReadFile("E:\\Qtprojects\\SeqList\\SeqListdata.txt");
    Ls.ReadFile("E:\\Qtprojects\\SeqList\\SeqListStudent.txt");
    cout<<"������������int or Student"<<endl;
    cin>>flag;
    if(flag=="int")
    {
    while(1)
    {
    menu();
    int choice;//����ѡ��
    cin>>choice;
    switch(choice)
    {
        case 1:
            i=L.Length();
            cout<<"��ĳ���Ϊ��"<<i<<endl;
        break;
        case 2:
            cout<<"����һ��Ԫ��"<<endl;
            cin>>i;
            j=L.Search(i);
            if(j==-1)
                break;
            cout<<i<<"Ԫ���ǵ�"<<j<<"��Ԫ��"<<endl;
        break;
        case 3:
            cout<<"����һ��λ��"<<endl;
            cin>>i;
            j=L.Get(i);
            cout<<"��"<<i<<"��Ԫ����"<<j<<endl;
        break;
        case 4:
            cout<<"����Ҫ���������Ԫ��"<<endl;
            cin>>i;
            L.Push_back(i);
            L.Display(0,L.Getnum()-1);
        break;
        case 5:
            cout<<"����Ҫ�����λ��"<<endl;
            cin>>i;
            cout<<"����Ҫ�����Ԫ��"<<endl;
            cin>>j;
            L.Insert(i,j);
            L.Display(0,L.Getnum()-1);
        break;
        case 6:
            cout<<"����Ҫɾ����Ԫ��"<<endl;
            cin>>i;
            L.Remove(i);
            L.Display(0,L.Getnum()-1);
        break;
        case 7:
            cout<<"����Ҫɾ����Ԫ��λ��"<<endl;
            cin>>i;
            L.RemovePos(i);
            L.Display(0,L.Getnum()-1);
        break;
        case 8:
            cout<<"ȫ������"<<endl;
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
    int choice;//����ѡ��
    cin>>choice;
    switch(choice)
    {
        case 1:
            i=Ls.Length();
            cout<<"��ĳ���Ϊ��"<<i<<endl;
        break;
        case 2:
            cout<<"����һ��ѧ����ѧ��"<<endl;
            cin>>id;
            cout<<"����һ��ѧ��������"<<endl;
            cin>>name;
            s.setIdName(id,name);
            j=Ls.Search(s);
            cout<<s<<"ѧ���ǵ�"<<j<<"��ѧ��"<<endl;
        break;
        case 3:
            cout<<"����һ��λ��"<<endl;
            cin>>i;
            s1=Ls.Get(i);
            cout<<"��"<<i<<"��ѧ����"<<s1<<endl;
        break;
        case 4:
            cout<<"����Ҫ�����ѧ��ѧ��"<<endl;
            cin>>id;
            cout<<"����Ҫ�����ѧ������"<<endl;
            cin>>name;
            s.setIdName(id,name);
            Ls.Push_back(s);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 5:
            cout<<"����Ҫ�����λ��"<<endl;
            cin>>i;
            cout<<"����Ҫ�����ѧ��ѧ��"<<endl;
            cin>>id;
            cout<<"����Ҫ�����ѧ������"<<endl;
            cin>>name;
            s1.setIdName(id,name);
            Ls.Insert(i,s1);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 6:
            cout<<"����Ҫɾ����ѧ��ѧ��"<<endl;
            cin>>id;
            cout<<"����Ҫɾ����ѧ������"<<endl;
            cin>>name;
            s.setIdName(id,name);
            Ls.Remove(s);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 7:
            cout<<"����Ҫɾ����ѧ��λ��"<<endl;
            cin>>i;
            Ls.RemovePos(i);
            Ls.Display(0,Ls.Getnum()-1);
        break;
        case 8:
            cout<<"ȫ��ѧ������"<<endl;
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
