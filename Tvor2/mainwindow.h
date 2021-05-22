#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digits_numbers();
    void operation();
    void on_pushButton_16_clicked();
    void on_pushButton_plusminus_clicked();
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H