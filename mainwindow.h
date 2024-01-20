#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<qcustomplot.h>
extern double result;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void plot();

private:
    Ui::MainWindow *ui;

     QVector<double> qv_x, qv_y;
};

#endif // MAINWINDOW_H
