#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include <string.h>
using namespace std;
class Student
{
private:
    string id;
    string name;
public:
    Student()//构造函数
    {

    }
    Student (string i, string n)//含参构造函数
    {
        id=i;name=n;
    }
//    Student( const Student& s);
    ~Student()
    {

    }
    Student operator=(Student s);//重载赋值运算
    bool operator==(Student s);//重载==
    friend ostream& operator<<(ostream &cout, Student s);//重载<<
    friend istream& operator>>(istream &cin, Student &s);//重载>>
    void setIdName(string i,string n);//设置名字和学号
};

#endif // STUDENT_H
