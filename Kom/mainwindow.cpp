#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      connect(ui->pushButton_ravno,SIGNAL(clicked()),this,SLOT(operation()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::operation()
{
       QPainter painter;
    QPushButton *button = (QPushButton *) sender();
    QLineEdit lineEdit_12,lineEdit_13,lineEdit_14,lineEdit_15,lineEdit_23,lineEdit_24,lineEdit_25,lineEdit_34,lineEdit_35,lineEdit_45;
    QString lal;
    int a12=-1,a13=-1,a14=-1,a15=-1,a23=-1,a24=-1,a25=-1,a34=-1,a35=-1,a45=-1;
     if(button->text() == "="){
     lal=ui->lineEdit_12->text();
     a12 = lal.toInt(0, 10);
     lal=ui->lineEdit_13->text();
     a13 = lal.toInt(0, 10);
     lal=ui->lineEdit_14->text();
     a14 = lal.toInt(0, 10);
     lal=ui->lineEdit_15->text();
     a15 = lal.toInt(0, 10);
     lal=ui->lineEdit_23->text();
     a23 = lal.toInt(0, 10);
     lal=ui->lineEdit_24->text();
     a24 = lal.toInt(0, 10);
     lal=ui->lineEdit_25->text();
     a25 = lal.toInt(0, 10);
     lal=ui->lineEdit_34->text();
     a34 = lal.toInt(0, 10);
     lal=ui->lineEdit_35->text();
     a35 = lal.toInt(0, 10);
     lal=ui->lineEdit_45->text();
     a45 = lal.toInt(0, 10);
     int m[6][6] = { {-1,a12,a13,a14,a15},
                    {a12,-1,a23,a24,a25},
                    {a13,a23,-1,a34,a35},
                    {a14,a24,a34,-1,a45},
                    {a15,a25,a35,a45,-1}
         };
     int all2 = 0;
         int m1[6][6];
         for (int i = 0; i < 6; i++)
         {
             for (int j = 0; j < 6; j++)
                 m1[i][j] = m[i][j];
         }
         for(int l=0;l<5;l++)
             {
                 int all = 0;
                 int x, y;
                 int f = 1;
             for (int i = 0; i < 5; i++)
             {
                 int stroka = 100;
                 for (int j = 0; j < 5; j++)
                 {
                     if (m[i][j] < stroka && m[i][j] != -1)
                     {
                         stroka = m[i][j];
                         m[i][5] = stroka;
                     }
                 }
             }

             for (int i = 0; i < 5; i++)
                 for (int j = 0; j < 5; j++)
                     if (m[i][j] != -1)
                         m[i][j] = m[i][j] - m[i][5];

             for (int j = 0; j < 5; j++)
             {
                 int stroka = 100;
                 for (int i = 0; i < 5; i++)
                 {
                     if (m[i][j] < stroka && m[i][j] != -1)
                     {
                         stroka = m[i][j];
                         m[5][j] = stroka;
                     }
                 }
             }

             for (int j = 0; j < 5; j++)
                 for (int i = 0; i < 5; i++)
                     if (m[i][j] != -1)
                         m[i][j] = m[i][j] - m[5][j];

             for (int i = 0; i < 5; i++)
             {
                 int stroka = 100;
                 int stolb = 100;
                 for (int j = 0; j < 5; j++)
                 {
                     if (m[i][j] == 0)
                     {
                         for (int a = 0; a < 5; a++)
                             if (m[a][j] < stroka && a != i && m[a][j] != -1)
                                 stroka = m[a][j];
                         for (int b = 0; b < 5; b++)
                             if (m[i][b] < stolb && b != j && m[i][b] != -1)
                                 stolb = m[i][b];
                         if (all <= stolb + stroka)
                         {
                             all = stolb + stroka;
                             x = i;
                             y = j;

                         }
                     }
                 }
             }
             m[y][x] = -1;
             for (int j = 0; j < 5; j++)
                 m[x][j] = -1;
             for (int i = 0; i < 5; i++)
                 m[i][y] = -1;

             all2 = all2 + m1[x][y];

             for (int i = 0; i < 6; i++)
             {
                 for (int j = 0; j < 6; j++)
                     if (m[i][j] > 0)
                         f = 0;
             }
             if (f == 1)
             {
                 for (int i = 0; i < 5; i++)
                 {
                     for (int j = 0; j < 5; j++)
                         if (m[i][j] == 0)
                             all2 = all2 + m1[x][y];
                 }
                 break;
             }
             }
         lal=QString::number(all2);
     ui->result_show->setText(lal);
     }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;

    painter.begin(this);
    painter.drawLine(70,130,110,250);
    painter.drawLine(110,250,210,250);
    painter.drawLine(210,250,250,130);
    painter.drawLine(250,130,160,70);
    painter.drawLine(250,130,160,70);
     painter.drawLine(160,70,70,130);
     painter.drawLine(160,70,110,250);
     painter.drawLine(160,70,210,250);
       painter.drawLine(250,130,70,130);
         painter.drawLine(250,130,110,250);
         painter.drawLine(210,250,70,130);
        painter.end();
}

