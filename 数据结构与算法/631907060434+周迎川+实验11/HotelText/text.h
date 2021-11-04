#include"list.h"
//#include"infohotel.h"
#include<iomanip>
#include <QDebug>
void EmptyRoom(List<Room> *L)  //�շ�����Ϣ����
{
    LinkNode<Room> *p;
    p = L->getHead()->link;
    cout<<"�շ���"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<setw(6)<<"�����";
    cout<<setw(6)<<"��λ";
    cout<<setw(6)<<"����";
    cout<<setw(6)<<"�۸�"<<endl;
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

void NonEmptyRoom(List<Room> *L) //�ǿշ�����Ϣ����
{
    LinkNode<Room> *p;
    p=L->getHead()->link;
    cout<<"�ѿ����䣺"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<setw(6)<<"�����";
    cout<<setw(6)<<"��λ";
    cout<<setw(6)<<"����";
    cout<<setw(6)<<"�۸�";
    cout<<setw(20)<<"�����ͻ�����";
    cout<<setw(13)<<"���֤";
    cout<<setw(25)<<"�绰����"<<endl;
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
LinkNode<Room> *searchInRoomNum(List<Room> *L, string s) //���ݷ���Ų�ѯ
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

LinkNode<Room> *searchInName(List<Room> *L,string s) //���ݿ�����������ѯ
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

LinkNode<Room> *searchInId(List<Room> *L,string s) //���ݿ��������֤��ѯ
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
LinkNode<Room> *searchInTel(List<Room> *L,string s) //���ݿ����˵绰��ѯ
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

/*void Rent(List<Room> *L, string s) //���� ,sΪ�����
{
    LinkNode<Room> *p =searchInRoomNum(L,s);
    if(p==nullptr) cout<<"����ʧ�ܣ�������Ų����ڣ�"<<endl;
    else if(p->data.getDeal()==1) cout<<"����ʧ�ܣ��������ѳ��⣡"<<endl;
    else
    {

        customer c;
        cout<<"�Ǽǿͻ���Ϣ"<<endl;
        cout<<"������";cin>>s;
        c.setName(s);
        cout<<"���֤��";cin>>s;
        c.setId(s);
        cout<<"�绰��"; cin>>s;
        c.setTel(s);
        cout<<"�����ɹ���"<<endl;
        p->data.setCustomer(c);
        p->data.setDeal(1);
    }
}*/
void Rent(List<Room> *L, string s,string s2,string s3,string s4)
{
    LinkNode<Room> *p =searchInRoomNum(L,s);
    if(p==nullptr) qDebug()<<"����ʧ�ܣ�������Ų����ڣ�"<<endl;
    else if(p->data.getDeal()==1) qDebug()<<"����ʧ�ܣ��������ѳ��⣡"<<endl;
    else
    {

        customer c;
        //cout<<"�Ǽǿͻ���Ϣ"<<endl;
       // cout<<"������";cin>>s;
        c.setName(s2);
        //cout<<"���֤��";cin>>s;
        c.setId(s3);
        //cout<<"�绰��"; cin>>s;
        c.setTel(s4);
        //cout<<"�����ɹ���"<<endl;
        p->data.setCustomer(c);
        p->data.setDeal(1);
    }
}
void Checkout(List<Room> *L,string s,int n) //�˷������ݷ���š����������֤���绰��ѯ n�ֱ�Ϊ1��2��3��4
{
    LinkNode<Room> *p;
    if(n==1)//���ݷ����
    {
        p = searchInRoomNum(L,s);
        if(p==nullptr) cout<<"�˷�ʧ�ܣ�������Ų����ڣ�"<<endl;
        else if(p->data.getDeal()==0) cout<<"�˷�ʧ�ܣ�������δ����"<<endl;
        else p->data.setDeal(0);

    }
    else if(n==2)  //��������
    {
        p = searchInName(L,s);
        if(p==nullptr) cout<<"�˷�ʧ�ܣ�������Ų����ڣ�"<<endl;
        else if(p->data.getDeal()==0) cout<<"�˷�ʧ�ܣ�������δ����"<<endl;
        else p->data.setDeal(0);
    }
    else if(n==3)  //�������֤
    {
        p = searchInId(L,s);
        if(p==nullptr) cout<<"�˷�ʧ�ܣ�������Ų����ڣ�"<<endl;
        else if(p->data.getDeal()==0) cout<<"�˷�ʧ�ܣ�������δ����"<<endl;
        else p->data.setDeal(0);
    }
    else  //���ݵ绰
    {
        p = searchInTel(L,s);
        if(p==nullptr) cout<<"�˷�ʧ�ܣ�������Ų����ڣ�"<<endl;
        else if(p->data.getDeal()==0) cout<<"�˷�ʧ�ܣ�������δ����"<<endl;
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
