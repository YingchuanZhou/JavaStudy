#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void  writetableWidget();//–¥»Îtablewidget
    void  writetableWidget_2();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();


    void on_radioButton_4_clicked();

    void on_radioButton_3_clicked();

    void hideall();
    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
