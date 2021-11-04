#include"list.h"
//#include"infohotel.h"
#include<iomanip>
#include <QDebug>
void EmptyRoom(List<Room> *L)  //空房间信息函数
{
    LinkNode<Room> *p;
    p = L->getHead()->link;
    cout<<"空房："<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<setw(6)<<"房间号";
    cout<<setw(6)<<"床位";
    cout<<setw(6)<<"人数";
    cout<<setw(6)<<"价格"<<endl;
    while(p!= nullptr)
    {
        if(p->data.getDeal() == 0)
        {
            cout<<setw(6)<<p->data.getroomNum();
            cout<<setw(6)<<p->data.getBed();
            cout<<setw(6)<<p->data.getPerson();
            cout<<setw(6)<<p->data.getPrice();
            cout<<endl;
        }

        p = p->link;
    }
}

void NonEmptyRoom(List<Room> *L) //非空房间信息函数
{
    LinkNode<Room> *p;
    p=L->getHead()->link;
    cout<<"已开房间："<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<setw(6)<<"房间号";
    cout<<setw(6)<<"床位";
    cout<<setw(6)<<"人数";
    cout<<setw(6)<<"价格";
    cout<<setw(20)<<"开房客户姓名";
    cout<<setw(13)<<"身份证";
    cout<<setw(25)<<"电话号码"<<endl;
    while(p!=nullptr)
    {
        if(p->data.getDeal() ==1)
        {
            cout<<setw(6)<<p->data.getroomNum();
            cout<<setw(6)<<p->data.getBed();
            cout<<setw(6)<<p->data.getPerson();
            cout<<setw(6)<<p->data.getPrice();
            cout<<setw(15)<<p->data.getCustomer().getName();
            cout<<setw(25)<<p->data.getCustomer().getId();
            cout<<setw(20)<<p->data.getCustomer().getTel()<<endl;
        }
        p = p->link;
    }
}
LinkNode<Room> *searchInRoomNum(List<Room> *L, string s) //根据房间号查询
{
    LinkNode<Room> *p = L->getHead()->link;
    while(p!=nullptr)
    {
        if(p->data.getroomNum() == s)
            return p;
        p = p->link;
    }
    return nullptr;
}

LinkNode<Room> *searchInName(List<Room> *L,string s) //根据开房人姓名查询
{
    LinkNode<Room> *p = L->getHead()->link;
    while(p!=nullptr)
    {
        if(p->data.getCustomer().getName() == s)
            return p;
        p = p->link;
    }
    return nullptr;
}

LinkNode<Room> *searchInId(List<Room> *L,string s) //根据开房人身份证查询
{
    LinkNode<Room> *p = L->getHead()->link;
    while(p!=nullptr)
    {
        if(p->data.getCustomer().getId() == s)
            return p;
        p = p->link;
    }
    return nullptr;
}
LinkNode<Room> *searchInTel(List<Room> *L,string s) //根据开房人电话查询
{
    LinkNode<Room> *p = L->getHead()->link;
    while(p!=nullptr)
    {
        if(p->data.getCustomer().getTel() == s)
            return p;
        p = p->link;
    }
    return nullptr;
}

/*void Rent(List<Room> *L, string s) //开房 ,s为房间号
{
    LinkNode<Room> *p =searchInRoomNum(L,s);
    if(p==nullptr) cout<<"开房失败！！房间号不存在！"<<endl;
    else if(p->data.getDeal()==1) cout<<"开房失败！！房间已出租！"<<endl;
    else
    {

        customer c;
        cout<<"登记客户信息"<<endl;
        cout<<"姓名：";cin>>s;
        c.setName(s);
        cout<<"身份证：";cin>>s;
        c.setId(s);
        cout<<"电话："; cin>>s;
        c.setTel(s);
        cout<<"开房成功！"<<endl;
        p->data.setCustomer(c);
        p->data.setDeal(1);
    }
}*/
void Rent(List<Room> *L, string s,string s2,string s3,string s4)
{
    LinkNode<Room> *p =searchInRoomNum(L,s);
    if(p==nullptr) qDebug()<<"开房失败！！房间号不存在！"<<endl;
    else if(p->data.getDeal()==1) qDebug()<<"开房失败！！房间已出租！"<<endl;
    else
    {

        customer c;
        //cout<<"登记客户信息"<<endl;
       // cout<<"姓名：";cin>>s;
        c.setName(s2);
        //cout<<"身份证：";cin>>s;
        c.setId(s3);
        //cout<<"电话："; cin>>s;
        c.setTel(s4);
        //cout<<"开房成功！"<<endl;
        p->data.setCustomer(c);
        p->data.setDeal(1);
    }
}
void Checkout(List<Room> *L,string s,int n) //退房，根据房间号、姓名、身份证、电话查询 n分别为1、2、3、4
{
    LinkNode<Room> *p;
    if(n==1)//根据房间号
    {
        p = searchInRoomNum(L,s);
        if(p==nullptr) cout<<"退房失败！！房间号不存在！"<<endl;
        else if(p->data.getDeal()==0) cout<<"退房失败！！房间未开！"<<endl;
        else p->data.setDeal(0);

    }
    else if(n==2)  //根据姓名
    {
        p = searchInName(L,s);
        if(p==nullptr) cout<<"退房失败！！房间号不存在！"<<endl;
        else if(p->data.getDeal()==0) cout<<"退房失败！！房间未开！"<<endl;
        else p->data.setDeal(0);
    }
    else if(n==3)  //根据身份证
    {
        p = searchInId(L,s);
        if(p==nullptr) cout<<"退房失败！！房间号不存在！"<<endl;
        else if(p->data.getDeal()==0) cout<<"退房失败！！房间未开！"<<endl;
        else p->data.setDeal(0);
    }
    else  //根据电话
    {
        p = searchInTel(L,s);
        if(p==nullptr) cout<<"退房失败！！房间号不存在！"<<endl;
        else if(p->data.getDeal()==0) cout<<"退房失败！！房间未开！"<<endl;
        else p->data.setDeal(0);
    }

}

//int main()
//{
//    List<Room> *L = new List<Room>();
//    L->ReadfromFile("save.txt");

//    EmptyRoom(L);
//    NonEmptyRoom(L);
//    Rent(L,"0412");
//    L->SavetoFile("save.txt");
//}
