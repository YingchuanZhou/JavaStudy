#include"student.h"
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
ostream& operator<<(ostream &cout, Student s)
{
    //ÖØÔØÁ÷²Ù×÷
    cout<<setw(15)<<s.id;
    cout<<setw(20)<<s.name;
    return cout;
}
istream& operator>>(istream &cin, Student &s)
{
    cin>>s.id;
    cin>>s.name;
    return cin;
}
//Student::~Student()
//{

//}
//Student::Student()
//{

//}
//Student:: Student(string i, string n)
//{
//    this->id=i;this->name=n;
//}
Student Student::operator=(Student s)
{
    this->id=s.id;this->name=s.name;
    return *this;
}
bool Student::operator==(Student s)
{
    if(this->id==s.id&&this->name==s.name)
        return true;
    return false;
}
//Student::Student(const Student& s)
//{
//    id=s.id;name=s.name;
//}
void Student::setIdName(string i,string n)
{
    id=i;name=n;
}
