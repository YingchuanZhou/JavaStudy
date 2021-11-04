#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "text.h"
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
List<Room> *L=new List<Room>();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));//���ñ��룬��ֹ����
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("�Ƶ����ϵͳ"));
    ui->tableWidget_2->setColumnWidth(5,200);//����tablewidget_2�����֤�͵绰�����еĿ��
    ui->tableWidget_2->setColumnWidth(6,200);
    MainWindow::writetableWidget();
    MainWindow::writetableWidget_2();
    hideall();
    ui->label_9->hide();ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();ui->lineEdit_11->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hideall()
{
    ui->label_8->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();
}
void MainWindow::writetableWidget()//ÿ��д���������ٴ��ļ��ж���L����д��tablewidget
{
    ui->tableWidget->clear();
    QStringList head;
    head<<QString::fromLocal8Bit("�����")<<QString::fromLocal8Bit("��λ")\
       <<QString::fromLocal8Bit("����")<<QString::fromLocal8Bit("�۸�");//
    ui->tableWidget->setHorizontalHeaderLabels(head);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    L->ReadfromFile("save.txt");
    int n=L->Length();
    qDebug()<<n;
    ui->tableWidget->setRowCount(n);
    LinkNode<Room> *p;
    p = L->getHead()->link;
    QString line;
    int j=0;
    while(p!= nullptr)
    {
        if(p->data.getDeal() == 0)
        {
            line=QString::fromStdString(p->data.getroomNum())+" "+QString::number(p->data.getBed())\
                    +" "+QString::number(p->data.getPerson())+" "+QString::number(p->data.getPrice());

        QStringList str=line.split(" ");
        for(int i=0;i<str.length();i++){

         ui->tableWidget->setItem(j,i,new QTableWidgetItem(str[i]));
        }

        j=j+1;
        }
        p=p->link;
    }
}
void MainWindow::writetableWidget_2()//ÿ��д���������ٴ��ļ��ж���L����д��tablewidget_2
{
    ui->tableWidget_2->clear();
    QStringList head;
    head<<QString::fromLocal8Bit("�����")<<QString::fromLocal8Bit("��λ")\
       <<QString::fromLocal8Bit("����")<<QString::fromLocal8Bit("�۸�")\
         <<QString::fromLocal8Bit("�ͻ�����")<<QString::fromLocal8Bit("���֤����")\
           <<QString::fromLocal8Bit("�绰����");//
    ui->tableWidget_2->setHorizontalHeaderLabels(head);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    int n=L->Length();
    qDebug()<<n;
    ui->tableWidget_2->setRowCount(n);
    LinkNode<Room> *p;
    p = L->getHead()->link;
    QString line;
    int j=0;
    while(p!= nullptr)
    {
        if(p->data.getDeal() == 1)
        {
            line=QString::fromStdString(p->data.getroomNum())+" "+QString::number(p->data.getBed())\
                    +" "+QString::number(p->data.getPerson())+" "+QString::number(p->data.getPrice())
                    +" "+QString::fromStdString(p->data.getCustomer().getName())+" "+\
                    QString::fromStdString(p->data.getCustomer().getId())+" "+\
                    QString::fromStdString(p->data.getCustomer().getTel());

        QStringList str=line.split(" ");
        for(int i=0;i<str.length();i++){

         ui->tableWidget_2->setItem(j,i,new QTableWidgetItem(str[i]));
        }

        j=j+1;
        }
        p=p->link;
    }
}


void MainWindow::on_pushButton_clicked()//������ȷ�ϰ�ť
{
    QString cnt=ui->lineEdit->text()+" "+ui->lineEdit_2->text()+" "+ui->lineEdit_3->text()\
            +" "+ui->lineEdit_4->text();
    QStringList str=cnt.split(" ");//��ȡ���ݲ��ҷֽ��list
    if(str[0]==nullptr||str[1]==nullptr||str[2]==nullptr||str[3]==nullptr){
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("������������Ϣ������"));

    }
    else
    {
        Rent(L,str[3].toStdString(),str[0].toStdString(),str[1].toStdString(),str[2].toStdString());
        L->SavetoFile("save.txt");
        L->makeEmpty();
        writetableWidget();
        writetableWidget_2();
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����ɹ�������"));
        ui->lineEdit->clear();//��lineedit�������
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
    }
}


void MainWindow::on_pushButton_2_clicked()//�˷�ȷ�ϰ�ť
{
    if(ui->radioButton->isChecked())//�����ѡ��û�й�ѡ��ʾ��
    {
            QString str=ui->lineEdit_8->text();
        if(str==nullptr)//û��������ʾ
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
        Checkout(L,str.toStdString(),1);
        L->SavetoFile("save.txt");
        L->makeEmpty();
        writetableWidget();
        writetableWidget_2();
        QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�˷��ɹ�������"));
        ui->lineEdit_8->clear();
        hideall();
        return ;
    }
    else if(ui->radioButton_2->isChecked())
        {
            QString str=ui->lineEdit_5->text();
            if(str==nullptr)
                QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
            Checkout(L,str.toStdString(),2);
            L->SavetoFile("save.txt");
            L->makeEmpty();
            writetableWidget();
            writetableWidget_2();
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�˷��ɹ�������"));
            ui->lineEdit_5->clear();
            hideall();
            return ;
        }
    else if(ui->radioButton_3->isChecked())
        {
            QString str=ui->lineEdit_6->text();
            if(str==nullptr)
                QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
            Checkout(L,str.toStdString(),3);
            L->SavetoFile("save.txt");
            L->makeEmpty();
            writetableWidget();
            writetableWidget_2();
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�˷��ɹ�������"));
            ui->lineEdit_6->clear();
            hideall();
            return ;
        }
    else if(ui->radioButton_4->isChecked())
        {
            QString str=ui->lineEdit_7->text();
            if(str==nullptr)
                QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
            Checkout(L,str.toStdString(),4);
            L->SavetoFile("save.txt");
            L->makeEmpty();
            writetableWidget();
            writetableWidget_2();
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�˷��ɹ�������"));
            ui->lineEdit_7->clear();
            hideall();
            return ;
        }
     else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("��ѡ�񣡣���"));
        }
}

void MainWindow::on_radioButton_clicked()//ѡһ����ѡ�򣬶�Ӧ��label��lineedit��ǩ��ʾ
{
    hideall();
    if(ui->radioButton->isChecked())
       ui->label_8->show();ui->lineEdit_8->show();

}

void MainWindow::on_radioButton_2_clicked()
{
    hideall();
    if(ui->radioButton_2->isChecked())
        ui->label_5->show();ui->lineEdit_5->show();

}

void MainWindow::on_radioButton_3_clicked()
{
    hideall();
    if(ui->radioButton_3->isChecked())
        ui->label_6->show();ui->lineEdit_6->show();
}
void MainWindow::on_radioButton_4_clicked()
{
    hideall();
    if(ui->radioButton_4->isChecked())
        ui->label_7->show();ui->lineEdit_7->show();
}


void MainWindow::on_radioButton_5_clicked()
{
    ui->label_9->clear();
    ui->label_9->hide();ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();ui->lineEdit_11->hide();
    if(ui->radioButton_5->isChecked())
        ui->lineEdit_9->show();
}

void MainWindow::on_radioButton_6_clicked()
{
    ui->label_9->clear();
    ui->label_9->hide();ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();ui->lineEdit_11->hide();
    if(ui->radioButton_6->isChecked())
        ui->lineEdit_10->show();
}

void MainWindow::on_radioButton_7_clicked()
{
    ui->label_9->clear();
    ui->label_9->hide();ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();ui->lineEdit_11->hide();
    if(ui->radioButton_7->isChecked())
        ui->lineEdit_11->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->radioButton_5->isChecked())//�����ѡ��û�й�ѡ��ʾ��
    {
            QString str=ui->lineEdit_9->text();
        if(str==nullptr)//û��������ʾ
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
        LinkNode<Room> *p=searchInName(L,str.toStdString());
        if(p==nullptr){
             QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("û�иù˿ͣ�����"));
             return;
        }
        QString line=QString::fromLocal8Bit("�����:")+QString::fromStdString(p->data.getroomNum())\
                +"\n"+QString::fromLocal8Bit("��λ��")+QString::number(p->data.getBed())\
                +"\n"+QString::fromLocal8Bit("������")+QString::number(p->data.getPerson())+"\n"+\
                QString::fromLocal8Bit("�۸�")+QString::number(p->data.getPrice())
                +"\n"+QString::fromLocal8Bit("���֣�")+QString::fromStdString(p->data.getCustomer().getName())+"\n"+\
                QString::fromLocal8Bit("���֤��")+QString::fromStdString(p->data.getCustomer().getId())+"\n"+\
                QString::fromLocal8Bit("�绰��")+QString::fromStdString(p->data.getCustomer().getTel());
        ui->label_9->setText(line);
        ui->label_9->show();
    }
    else if(ui->radioButton_6->isChecked())//�����ѡ��û�й�ѡ��ʾ��
    {
            QString str=ui->lineEdit_10->text();
        if(str==nullptr)//û��������ʾ
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
        LinkNode<Room> *p=searchInId(L,str.toStdString());
        if(p==nullptr){
             QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("û�иù˿ͣ�����"));
             return;
        }
        QString line=QString::fromLocal8Bit("�����:")+QString::fromStdString(p->data.getroomNum())\
                +"\n"+QString::fromLocal8Bit("��λ��")+QString::number(p->data.getBed())\
                +"\n"+QString::fromLocal8Bit("������")+QString::number(p->data.getPerson())+"\n"+\
                QString::fromLocal8Bit("�۸�")+QString::number(p->data.getPrice())
                +"\n"+QString::fromLocal8Bit("���֣�")+QString::fromStdString(p->data.getCustomer().getName())+"\n"+\
                QString::fromLocal8Bit("���֤��")+QString::fromStdString(p->data.getCustomer().getId())+"\n"+\
                QString::fromLocal8Bit("�绰��")+QString::fromStdString(p->data.getCustomer().getTel());
        ui->label_9->setText(line);
        ui->label_9->show();
    }
    else if(ui->radioButton_7->isChecked())//�����ѡ��û�й�ѡ��ʾ��
    {
         QString str=ui->lineEdit_11->text();
        if(str==nullptr)//û��������ʾ
            QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("�����������ݣ�����"));
        LinkNode<Room> *p=searchInTel(L,str.toStdString());
        if(p==nullptr){
             QMessageBox::information(this,QString::fromLocal8Bit("��ʾ"),QString::fromLocal8Bit("û�иù˿ͣ�����"));
             return;
        }
        QString line=QString::fromLocal8Bit("�����:")+QString::fromStdString(p->data.getroomNum())\
                +"\n"+QString::fromLocal8Bit("��λ��")+QString::number(p->data.getBed())\
                +"\n"+QString::fromLocal8Bit("������")+QString::number(p->data.getPerson())+"\n"+\
                QString::fromLocal8Bit("�۸�")+QString::number(p->data.getPrice())
                +"\n"+QString::fromLocal8Bit("���֣�")+QString::fromStdString(p->data.getCustomer().getName())+"\n"+\
                QString::fromLocal8Bit("���֤��")+QString::fromStdString(p->data.getCustomer().getId())+"\n"+\
                QString::fromLocal8Bit("�绰��")+QString::fromStdString(p->data.getCustomer().getTel());
        ui->label_9->setText(line);
        ui->label_9->show();
    }
}
