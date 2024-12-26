#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , count(20)
    , row(0)
    , column(0)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::ticketFunction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ticketFunction()
{
    QString name=ui->lineEdit->text();
    QString id=ui->lineEdit_2->text();

    QString row_string=QString::number(row);
    QString column_string=QString::number(column);
    QString count_string=QString::number(count);

    if(count > 0){
        if(column < 10){
            column++;
            QMessageBox::information(this,"Success","You have reserved Seat No " + column_string +
                                                          " in row " + row_string + " for " + name +
                                                          "\n" + "With ID " + id + "\n" "Remaining Seats " +
                                                          count_string);
        }else{
            row++;
            column = 0;
        }
        count--;
    }else{QMessageBox::information(this,"ERROR","All Seats Reserved");}
}

