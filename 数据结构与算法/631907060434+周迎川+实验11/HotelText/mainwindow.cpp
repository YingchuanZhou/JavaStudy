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
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));//设置编码，防止乱码
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("酒店管理系统"));
    ui->tableWidget_2->setColumnWidth(5,200);//设置tablewidget_2的身份证和电话号码行的宽度
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
void MainWindow::writetableWidget()//每次写入先清理，再从文件中读入L，再写入tablewidget
{
    ui->tableWidget->clear();
    QStringList head;
    head<<QString::fromLocal8Bit("房间号")<<QString::fromLocal8Bit("床位")\
       <<QString::fromLocal8Bit("人数")<<QString::fromLocal8Bit("价格");//
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
void MainWindow::writetableWidget_2()//每次写入先清理，再从文件中读入L，再写入tablewidget_2
{
    ui->tableWidget_2->clear();
    QStringList head;
    head<<QString::fromLocal8Bit("房间号")<<QString::fromLocal8Bit("床位")\
       <<QString::fromLocal8Bit("人数")<<QString::fromLocal8Bit("价格")\
         <<QString::fromLocal8Bit("客户姓名")<<QString::fromLocal8Bit("身份证号码")\
           <<QString::fromLocal8Bit("电话号码");//
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


void MainWindow::on_pushButton_clicked()//开房的确认按钮
{
    QString cnt=ui->lineEdit->text()+" "+ui->lineEdit_2->text()+" "+ui->lineEdit_3->text()\
            +" "+ui->lineEdit_4->text();
    QStringList str=cnt.split(" ");//获取内容并且分解成list
    if(str[0]==nullptr||str[1]==nullptr||str[2]==nullptr||str[3]==nullptr){
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("请输入完整信息！！！"));

    }
    else
    {
        Rent(L,str[3].toStdString(),str[0].toStdString(),str[1].toStdString(),str[2].toStdString());
        L->SavetoFile("save.txt");
        L->makeEmpty();
        writetableWidget();
        writetableWidget_2();
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("开房成功！！！"));
        ui->lineEdit->clear();//将lineedit内容清空
        ui->lineEdit_2->clear();
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
    }
}


void MainWindow::on_pushButton_2_clicked()//退房确认按钮
{
    if(ui->radioButton->isChecked())//如果单选框没有勾选提示，
    {
            QString str=ui->lineEdit_8->text();
        if(str==nullptr)//没有输入提示
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
        Checkout(L,str.toStdString(),1);
        L->SavetoFile("save.txt");
        L->makeEmpty();
        writetableWidget();
        writetableWidget_2();
        QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("退房成功！！！"));
        ui->lineEdit_8->clear();
        hideall();
        return ;
    }
    else if(ui->radioButton_2->isChecked())
        {
            QString str=ui->lineEdit_5->text();
            if(str==nullptr)
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
            Checkout(L,str.toStdString(),2);
            L->SavetoFile("save.txt");
            L->makeEmpty();
            writetableWidget();
            writetableWidget_2();
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("退房成功！！！"));
            ui->lineEdit_5->clear();
            hideall();
            return ;
        }
    else if(ui->radioButton_3->isChecked())
        {
            QString str=ui->lineEdit_6->text();
            if(str==nullptr)
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
            Checkout(L,str.toStdString(),3);
            L->SavetoFile("save.txt");
            L->makeEmpty();
            writetableWidget();
            writetableWidget_2();
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("退房成功！！！"));
            ui->lineEdit_6->clear();
            hideall();
            return ;
        }
    else if(ui->radioButton_4->isChecked())
        {
            QString str=ui->lineEdit_7->text();
            if(str==nullptr)
                QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
            Checkout(L,str.toStdString(),4);
            L->SavetoFile("save.txt");
            L->makeEmpty();
            writetableWidget();
            writetableWidget_2();
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("退房成功！！！"));
            ui->lineEdit_7->clear();
            hideall();
            return ;
        }
     else
        {
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("请选择！！！"));
        }
}

void MainWindow::on_radioButton_clicked()//选一个单选框，对应得label和lineedit标签显示
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
    if(ui->radioButton_5->isChecked())//如果单选框没有勾选提示，
    {
            QString str=ui->lineEdit_9->text();
        if(str==nullptr)//没有输入提示
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
        LinkNode<Room> *p=searchInName(L,str.toStdString());
        if(p==nullptr){
             QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("没有该顾客！！！"));
             return;
        }
        QString line=QString::fromLocal8Bit("房间号:")+QString::fromStdString(p->data.getroomNum())\
                +"\n"+QString::fromLocal8Bit("床位：")+QString::number(p->data.getBed())\
                +"\n"+QString::fromLocal8Bit("人数：")+QString::number(p->data.getPerson())+"\n"+\
                QString::fromLocal8Bit("价格：")+QString::number(p->data.getPrice())
                +"\n"+QString::fromLocal8Bit("名字：")+QString::fromStdString(p->data.getCustomer().getName())+"\n"+\
                QString::fromLocal8Bit("身份证；")+QString::fromStdString(p->data.getCustomer().getId())+"\n"+\
                QString::fromLocal8Bit("电话：")+QString::fromStdString(p->data.getCustomer().getTel());
        ui->label_9->setText(line);
        ui->label_9->show();
    }
    else if(ui->radioButton_6->isChecked())//如果单选框没有勾选提示，
    {
            QString str=ui->lineEdit_10->text();
        if(str==nullptr)//没有输入提示
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
        LinkNode<Room> *p=searchInId(L,str.toStdString());
        if(p==nullptr){
             QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("没有该顾客！！！"));
             return;
        }
        QString line=QString::fromLocal8Bit("房间号:")+QString::fromStdString(p->data.getroomNum())\
                +"\n"+QString::fromLocal8Bit("床位：")+QString::number(p->data.getBed())\
                +"\n"+QString::fromLocal8Bit("人数：")+QString::number(p->data.getPerson())+"\n"+\
                QString::fromLocal8Bit("价格：")+QString::number(p->data.getPrice())
                +"\n"+QString::fromLocal8Bit("名字：")+QString::fromStdString(p->data.getCustomer().getName())+"\n"+\
                QString::fromLocal8Bit("身份证；")+QString::fromStdString(p->data.getCustomer().getId())+"\n"+\
                QString::fromLocal8Bit("电话：")+QString::fromStdString(p->data.getCustomer().getTel());
        ui->label_9->setText(line);
        ui->label_9->show();
    }
    else if(ui->radioButton_7->isChecked())//如果单选框没有勾选提示，
    {
         QString str=ui->lineEdit_11->text();
        if(str==nullptr)//没有输入提示
            QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("输入完整数据！！！"));
        LinkNode<Room> *p=searchInTel(L,str.toStdString());
        if(p==nullptr){
             QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("没有该顾客！！！"));
             return;
        }
        QString line=QString::fromLocal8Bit("房间号:")+QString::fromStdString(p->data.getroomNum())\
                +"\n"+QString::fromLocal8Bit("床位：")+QString::number(p->data.getBed())\
                +"\n"+QString::fromLocal8Bit("人数：")+QString::number(p->data.getPerson())+"\n"+\
                QString::fromLocal8Bit("价格：")+QString::number(p->data.getPrice())
                +"\n"+QString::fromLocal8Bit("名字：")+QString::fromStdString(p->data.getCustomer().getName())+"\n"+\
                QString::fromLocal8Bit("身份证；")+QString::fromStdString(p->data.getCustomer().getId())+"\n"+\
                QString::fromLocal8Bit("电话：")+QString::fromStdString(p->data.getCustomer().getTel());
        ui->label_9->setText(line);
        ui->label_9->show();
    }
}
