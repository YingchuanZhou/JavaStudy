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
    Student()//���캯��
    {

    }
    Student (string i, string n)//���ι��캯��
    {
        id=i;name=n;
    }
//    Student( const Student& s);
    ~Student()
    {

    }
    Student operator=(Student s);//���ظ�ֵ����
    bool operator==(Student s);//����==
    friend ostream& operator<<(ostream &cout, Student s);//����<<
    friend istream& operator>>(istream &cin, Student &s);//����>>
    void setIdName(string i,string n);//�������ֺ�ѧ��
};

#endif // STUDENT_H
