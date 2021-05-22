#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_14,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_15,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_ravno,SIGNAL(clicked()),this,SLOT(operation()));
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digits_numbers()
{
   QPushButton *button = (QPushButton *) sender();
   QString new_label;
   new_label = (ui->result_show->text()+button->text());
   ui->result_show->setText(new_label);
}
void MainWindow::operation()
{

   QPushButton *button = (QPushButton *) sender();
   int all_numbers_10СС=0;
   int all_numbers_2СС=0;
   QString all_numbers_begin;
   QString all_numbers_2;
   QString new_label;
   QString all_numbers;
    QString all_numbers_2mantisa;
   int all_numbers_mantisa=0;
   int CC,CC1,m=0,b = 1,k= 4,h=0,p= 1000;
;
   bool f=true;
   if(button->text() == "="){
         if(!(ui->result_show->text().contains('-')))
         {f=false;}
       if (ui->radioButton_2CC->isChecked())
       {CC=2;}
       if (ui->radioButton_3CC->isChecked())
       {CC=3;}
       if (ui->radioButton_8CC->isChecked())
       {CC=8;}
       if (ui->radioButton_9CC->isChecked())
       {CC=9;}
       if (ui->radioButton_10CC->isChecked())
       {CC=10;}
       if (ui->radioButton_16CC->isChecked())
       {CC=16;}
       if (ui->radioButton_2->isChecked())
       {CC1=2;}
       if (ui->radioButton_3->isChecked())
       {CC1=3;}
       if (ui->radioButton_8->isChecked())
       {CC1=8;}
       if (ui->radioButton_9->isChecked())
       {CC1=9;}
       if (ui->radioButton_10->isChecked())
       {CC1=10;}
       if (ui->radioButton_16->isChecked())
       {CC1=16;}


       if(CC==16)
       { all_numbers_begin = (ui->result_show->text());
            all_numbers_begin.remove('-');
             all_numbers_begin.indexOf('.');
             if(all_numbers_begin.indexOf('.')==-1)
             {  all_numbers_10СС = all_numbers_begin.toInt(0, 16);}
             else
            { all_numbers = all_numbers_begin.mid(all_numbers_begin.indexOf('.')+1);
            new_label=all_numbers_begin.mid(0,all_numbers_begin.indexOf('.'));
            reverse(all_numbers.begin(),all_numbers.end());
           all_numbers_10СС = new_label.toInt(0, 16);
           all_numbers_2СС = all_numbers.toInt(0,16);
         for(int chet=1;chet<5;chet++)
           {if(all_numbers_2СС%16>0)
           {all_numbers_mantisa=all_numbers_mantisa+all_numbers_2СС%16*(10000/CC);
              all_numbers_2СС= all_numbers_2СС/16;
              CC=CC*16;
               }
               else
                  { all_numbers_2СС= all_numbers_2СС/16;
                     CC=CC*16;}}}}


       if(CC==10)
       { all_numbers_begin = (ui->result_show->text());
           all_numbers_begin.remove('-');
           all_numbers_begin.indexOf('.');
           if(all_numbers_begin.indexOf('.')==-1)
           {  all_numbers_10СС = all_numbers_begin.toInt(0, 10);}
           else
          {all_numbers = all_numbers_begin.mid(all_numbers_begin.indexOf('.')+1);
          new_label=all_numbers_begin.mid(0,all_numbers_begin.indexOf('.'));
          all_numbers_10СС = new_label.toInt(0, 10);
          all_numbers_mantisa=all_numbers.toInt(0,10);}


       }if(CC==9)
       { all_numbers_begin = (ui->result_show->text());
            all_numbers_begin.remove('-');
             all_numbers_begin.indexOf('.');
             if(all_numbers_begin.indexOf('.')==-1)
             {  all_numbers_10СС = all_numbers_begin.toInt(0, 9);}
             else
            { all_numbers = all_numbers_begin.mid(all_numbers_begin.indexOf('.')+1);
            new_label=all_numbers_begin.mid(0,all_numbers_begin.indexOf('.'));
            reverse(all_numbers.begin(),all_numbers.end());
           all_numbers_10СС = new_label.toInt(0, 9);
           all_numbers_2СС = all_numbers.toInt(0,9);
         for(int chet=1;chet<5;chet++)
           {if(all_numbers_2СС%9>0)
           {all_numbers_mantisa=all_numbers_mantisa+all_numbers_2СС%9*(10000/CC);
              all_numbers_2СС= all_numbers_2СС/9;
              CC=CC*9;
               }
               else
                  { all_numbers_2СС= all_numbers_2СС/9;
                     CC=CC*9;}}}}
       if(CC==8)
       { all_numbers_begin = (ui->result_show->text());
            all_numbers_begin.remove('-');
             all_numbers_begin.indexOf('.');
             if(all_numbers_begin.indexOf('.')==-1)
             {  all_numbers_10СС = all_numbers_begin.toInt(0, 8);}
             else
            { all_numbers = all_numbers_begin.mid(all_numbers_begin.indexOf('.')+1);
            new_label=all_numbers_begin.mid(0,all_numbers_begin.indexOf('.'));
            reverse(all_numbers.begin(),all_numbers.end());
           all_numbers_10СС = new_label.toInt(0, 8);
           all_numbers_2СС = all_numbers.toInt(0,8);
         for(int chet=1;chet<5;chet++)
           {if(all_numbers_2СС%8>0)
           {all_numbers_mantisa=all_numbers_mantisa+all_numbers_2СС%8*(10000/CC);
              all_numbers_2СС= all_numbers_2СС/8;
              CC=CC*8;
               }
               else
                  { all_numbers_2СС= all_numbers_2СС/8;
                     CC=CC*8;}}}}
       if(CC==3)
      { all_numbers_begin = (ui->result_show->text());
           all_numbers_begin.remove('-');
            all_numbers_begin.indexOf('.');
            if(all_numbers_begin.indexOf('.')==-1)
            {  all_numbers_10СС = all_numbers_begin.toInt(0, 3);}
            else
           { all_numbers = all_numbers_begin.mid(all_numbers_begin.indexOf('.')+1);
           new_label=all_numbers_begin.mid(0,all_numbers_begin.indexOf('.'));
           reverse(all_numbers.begin(),all_numbers.end());
          all_numbers_10СС = new_label.toInt(0, 3);
          all_numbers_2СС = all_numbers.toInt(0,3);
        for(int chet=1;chet<5;chet++)
          {if(all_numbers_2СС%3>0)
          {all_numbers_mantisa=all_numbers_mantisa+all_numbers_2СС%3*(10000/CC);
             all_numbers_2СС= all_numbers_2СС/3;
             CC=CC*3;
              }
              else
                 { all_numbers_2СС= all_numbers_2СС/3;
                    CC=CC*3;}}}}
       if(CC==2)
       { all_numbers_begin = (ui->result_show->text());
           all_numbers_begin.remove('-');
            all_numbers_begin.indexOf('.');
            if(all_numbers_begin.indexOf('.')==-1)
            {  all_numbers_10СС = all_numbers_begin.toInt(0, 2);}
            else
           { all_numbers = all_numbers_begin.mid(all_numbers_begin.indexOf('.')+1);
           new_label=all_numbers_begin.mid(0,all_numbers_begin.indexOf('.'));
           reverse(all_numbers.begin(),all_numbers.end());
          all_numbers_10СС = new_label.toInt(0, 2);
          all_numbers_2СС = all_numbers.toInt(0,2);
        for(int chet=1;chet<5;chet++)
          {if(all_numbers_2СС%2==1)
          {all_numbers_mantisa=all_numbers_mantisa+(10000/CC);
             all_numbers_2СС= all_numbers_2СС/2;
             CC=CC*2;}
              else
                 { all_numbers_2СС= all_numbers_2СС/2;
                    CC=CC*2;}}}}


       if(CC1==16)
       { all_numbers_2=QString::number(all_numbers_10СС, 16);
           m=all_numbers_mantisa;
           do
              {
                  m=m/10;
                  b = b * 10;
              } while (m != 0);
              do
              {
                  all_numbers_mantisa = all_numbers_mantisa * CC1;
                  h = h + (all_numbers_mantisa / b)* p;
                  p = p / 10;
                  all_numbers_mantisa = all_numbers_mantisa % b;
                  k = k - 1;
              } while (k != 0);
       all_numbers_mantisa=h;
       all_numbers_2mantisa=QString::number(all_numbers_mantisa,10);}


       if(CC1==10)
       { all_numbers_2=QString::number(all_numbers_10СС);
       all_numbers_2mantisa=QString::number(all_numbers_mantisa);}



       if(CC1==9)
       { all_numbers_2=QString::number(all_numbers_10СС,9);
           m=all_numbers_mantisa;
           do
              {
                  m=m/10;
                  b = b * 10;
              } while (m != 0);
              do
              {
                  all_numbers_mantisa = all_numbers_mantisa * CC1;
                  h = h + (all_numbers_mantisa / b)* p;
                  p = p / 10;
                  all_numbers_mantisa = all_numbers_mantisa % b;
                  k = k - 1;

              } while (k != 0);
       all_numbers_mantisa=h;
       all_numbers_2mantisa=QString::number(all_numbers_mantisa,10);}
       if(CC1==8)
       { all_numbers_2=QString::number(all_numbers_10СС,8);
           m=all_numbers_mantisa;
           do
              {
                  m=m/10;
                  b = b * 10;
              } while (m != 0);
              do
              {
                  all_numbers_mantisa = all_numbers_mantisa * CC1;
                  h = h + (all_numbers_mantisa / b)* p;
                  p = p / 10;
                  all_numbers_mantisa = all_numbers_mantisa % b;
                  k = k - 1;

              } while (k != 0);
       all_numbers_mantisa=h;
       all_numbers_2mantisa=QString::number(all_numbers_mantisa,10);}
       if(CC1==3)
       { all_numbers_2=QString::number(all_numbers_10СС,3);
           m=all_numbers_mantisa;
           do
              {
                  m=m/10;
                  b = b * 10;
              } while (m != 0);
              do
              {
                  all_numbers_mantisa = all_numbers_mantisa * CC1;
                  h = h + (all_numbers_mantisa / b)* p;
                  p = p / 10;
                  all_numbers_mantisa = all_numbers_mantisa % b;
                  k = k - 1;

              } while (k != 0);
       all_numbers_mantisa=h;
       all_numbers_2mantisa=QString::number(all_numbers_mantisa,10);}
       if(CC1==2)
       {all_numbers_2=QString::number(all_numbers_10СС,2);
            m=all_numbers_mantisa;
            do
               {
                   m=m/10;
                   b = b * 10;
               } while (m != 0);
               do
               {
                   all_numbers_mantisa = all_numbers_mantisa * CC1;
                   h = h + (all_numbers_mantisa / b)* p;
                   p = p / 10;
                   all_numbers_mantisa = all_numbers_mantisa % b;
                   k = k - 1;

               } while (k != 0);
        all_numbers_mantisa=h;
        all_numbers_2mantisa=QString::number(all_numbers_mantisa,10);}
    if(f==true)
    {
    { if(all_numbers_begin.indexOf('.')==-1)
          ui->result_show->setText('-'+all_numbers_2);
        else{if(all_numbers_2mantisa.length()==4)
     ui->result_show->setText('-'+all_numbers_2+'.'+all_numbers_2mantisa);
        if(all_numbers_2mantisa.length()==3)
             ui->result_show->setText('-'+all_numbers_2+'.'+'0'+all_numbers_2mantisa);
         if(all_numbers_2mantisa.length()==2)
  ui->result_show->setText('-'+all_numbers_2+'.'+'0'+'0'+all_numbers_2mantisa);
         if(all_numbers_2mantisa.length()==1)
  ui->result_show->setText('-'+all_numbers_2+'.'+'0'+'0'+'0'+all_numbers_2mantisa);}}}
    else
    { if(all_numbers_begin.indexOf('.')==-1)
          ui->result_show->setText(all_numbers_2);
        else{if(all_numbers_2mantisa.length()==4)
     ui->result_show->setText(all_numbers_2+'.'+all_numbers_2mantisa);
        if(all_numbers_2mantisa.length()==3)
             ui->result_show->setText(all_numbers_2+'.'+'0'+all_numbers_2mantisa);
         if(all_numbers_2mantisa.length()==2)
  ui->result_show->setText(all_numbers_2+'.'+'0'+'0'+all_numbers_2mantisa);
         if(all_numbers_2mantisa.length()==1)
  ui->result_show->setText(all_numbers_2+'.'+'0'+'0'+'0'+all_numbers_2mantisa);}}}}
void MainWindow::on_pushButton_16_clicked()
{
    if(!(ui->result_show->text().contains('.')))
        ui->result_show->setText(ui->result_show->text()+".");
}
void MainWindow::on_pushButton_plusminus_clicked()
{
    if(!(ui->result_show->text().contains('-')))
        ui->result_show->setText(("-")+ui->result_show->text());
    else
     ui->result_show->setText(ui->result_show->text().remove('-'));
}


void MainWindow::on_pushButton_clicked()
{
    ui->result_show->setText(" ");
}
