/**
    @author Emre ARSLAN
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

// This is the equivalent of Qt Application Class code of Pytoh in C++
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
