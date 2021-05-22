#include "mainwindow.h"
#include <QTextStream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    QTextStream cout(stdout);
    cout<<"Gg"<<endl;
}
