#include "mainwindow.h"

#include <QApplication>

// There is the equivalent of main func in python Qt code
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
