#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon(":/resurce/img/calculator_3534.png"));
    w.setWindowTitle("CC translation calculator");
    w.show();
    return a.exec();
}
