#include "mainwindow.h"
#include<QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,480);

    pushButton = new QPushButton(this);

    pushButton->setText("按钮");

    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
    //connect(pushButton,SIGNAL(toggled()),this,SLOT(pushButtonClicked()));
    //connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));

    connect(this, SIGNAL(pushButtonTextChanged()), this, SLOT(changeButtonText()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::pushButtonClicked()
{
    emit pushButtonTextChanged();
}

void MainWindow::changeButtonText()
{
    pushButton->setText("按钮被按下了");
}
