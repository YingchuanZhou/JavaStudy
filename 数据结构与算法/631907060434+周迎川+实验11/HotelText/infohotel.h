#ifndef INFOHOTEL_H
#define INFOHOTEL_H

#include<iostream>
using namespace std;
#endif // INFOHOTEL_H

class customer{
private:
    string name; //姓名
    string id;  //身份证
    string tel; //电话
public:
    customer(string s1, string s2, string s3):name(s1),id(s2),tel(s3){}
    customer(){}
    string getName(){return name;}
    string getId() {return id;}
    string getTel(){return tel;}

    void setName(string s){name=s;}
    void setId(string s) {id= s;}
    void setTel(string s){tel =s;}
    friend ostream& operator<<(ostream& out , customer& c)
    {
        out<<c.getName()<<" ";
        out<<c.getId()<<" ";
        out<<c.getTel()<<" ";
        return out;
    }
    friend istream& operator>>(istream& in, customer& c)
    {
        in>>c.name;
        in>>c.id;
        in>>c.tel;
        return in;
    }
};


class Room{

private:
    customer C;//开房人信息
    string roomNum; //房间号
    int person; //可住人数
    int bed; //床数
    int price; //价格
    int  deal; //房间状态，是否已登记,01表示

public:
    Room(customer c, string r, int pe, int b, int pr):C(c),roomNum(r),person(pe),bed(b),price(pr),deal(0){}
    Room(){}
    void setCustomer(customer c){ C=c;}
    void setroomNum(string r) {roomNum = r;}
    void setPerson(int n){person = n;}
    void setBed(int n){bed=n;}
    void setPrice(int n){price = n;}
    void setDeal(int n){deal=n;}
    customer getCustomer(){return C;}
    string getroomNum(){return roomNum;}
    int getPerson(){return person;}
    int getBed(){return bed;}
    int getPrice(){return price;}
    int getDeal(){return deal;}


    friend ostream& operator<<(ostream& out, Room &r)
    {
        out<<r.getDeal()<<" ";
        out<<r.getroomNum()<<" ";
        out<<r.getPerson()<<" ";
        out<<r.getBed()<<" ";
        out<<r.getPrice()<<" ";
        if(r.getDeal()== 1)
        {
            out<<r.getCustomer().getName()<<" ";
            out<<r.getCustomer().getId()<<" ";
            out<<r.getCustomer().getTel()<<" ";
        }


        return out;
    }

    friend istream& operator>>(istream& in, Room &r)
    {
        in>>r.deal;
        in>>r.roomNum;
        in>>r.person;
        in>>r.bed;
        in>>r.price;
        if(r.deal == 0) return in; //房间未登记，则无住户信息录入
        string s;
        in>>s;
        r.C.setName(s);
        in>>s;
        r.C.setId(s);
        in>>s;
        r.C.setTel(s);
        return in;
    }
};
