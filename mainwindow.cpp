#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "qcustomplot.h"
double result=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    double x1=0,x2=0,xx1=0,xx2=0,xxx1=0,xxx2=0,xxxx1,xxxx2=0;
    double y1=0,y2=0,yy1=0,yy2=0,yyy1=0,yyy2=0,yyyy1,yyyy2=0;

    //set 1

    x1=ui->lineEdit_2->text().toDouble(); //56
    x2=ui->lineEdit_3->text().toDouble(); //110
    y1=ui->lineEdit_7->text().toDouble(); //0.267
    y2=ui->lineEdit_8->text().toDouble(); //0.552

    //set 2

    xx1=ui->lineEdit_3->text().toDouble(); //110
    xx2=ui->lineEdit_4->text().toDouble(); //170
    yy1=ui->lineEdit_8->text().toDouble(); //0.552
    yy2=ui->lineEdit_9->text().toDouble(); //0.921

    //set 3

    xxx1=ui->lineEdit_4->text().toDouble(); //170
    xxx2=ui->lineEdit_5->text().toDouble(); //220
    yyy1=ui->lineEdit_9->text().toDouble(); //0.921
    yyy2=ui->lineEdit_10->text().toDouble(); //1.162

    //set 4

    xxxx1=ui->lineEdit_5->text().toDouble(); //220
    xxxx2=ui->lineEdit_6->text().toDouble(); //280
    yyyy1=ui->lineEdit_10->text().toDouble(); //1.162
    yyyy2=ui->lineEdit_11->text().toDouble(); //1.328

    double fact1=0,fact2=0,fact3=0,fact4=0,fact5=0;
    fact1=x1/y1;
    fact2=x2/y2;
    fact3=xx2/yy2;
    fact4=xxx2/yyy2;
    fact5=xxxx2/yyyy2;

    if(fact1>100)
        ui->label_20->setText(QString::number(fact1,'f',0));
    else if(fact1<100)
        ui->label_20->setText(QString::number(fact1,'f',2));

    if(fact2>100)
        ui->label_21->setText(QString::number(fact2,'f',0));
    else if(fact2<100)
        ui->label_21->setText(QString::number(fact2,'f',2));

    if(fact3>100)
        ui->label_22->setText(QString::number(fact3,'f',0));
    else if(fact3<100)
        ui->label_22->setText(QString::number(fact3,'f',2));

    if(fact4>100)
        ui->label_23->setText(QString::number(fact4,'f',0));
    else if(fact4<100)
        ui->label_23->setText(QString::number(fact4,'f',2));

    if(fact5>100)
        ui->label_24->setText(QString::number(fact5,'f',0));
    else if(fact5<100)
        ui->label_24->setText(QString::number(fact5,'f',2));

    double slope=0, intercept=0;
    double Data = ui->lineEdit->text().toDouble();

    if (Data >= y1 && Data < y2) // set 1 (56-110)
    {
        slope= (y2-y1)/(x2-x1);
        intercept = (slope*x1)-y1;
        result= (Data+intercept)/slope;
    }
    else if (Data >= yy1 && Data < yy2) // set 2 (110-170)
    {
        slope = (yy2-yy1)/(xx2-xx1);
        intercept = (slope*xx1)-yy1;
        result= (Data+intercept)/slope;
    }
    else if (Data >= yyy1 && Data < yyy2) //set 3 (170-220)
    {
        slope = (yyy2-yyy1)/(xxx2-xxx1);
        intercept = (slope*xxx1)-yyy1;
        result= (Data+intercept)/slope;
    }
    else if (Data >= yyyy1 && Data <= yyyy2) //set 4 (220-280)
    {
        slope = (yyyy2-yyyy1)/(xxxx2-xxxx1);
        intercept = (slope*xxxx1)-yyyy1;
        result= (Data+intercept)/slope;
    }
    qDebug()<<"slope : "<<slope;
    qDebug()<<"intercept : "<<intercept;
    qDebug()<<"Result : "<<result;
    ui->label_29->setText(QString::number(slope , 'f',4));
    ui->label_30->setText(QString::number(intercept, 'f',4));
    if(result>=100)
        ui->label_31->setText(QString::number(result,'f',0));
    else
        ui->label_31->setText(QString::number(result,'f',2));
    plot();
}

void MainWindow::plot()
{
    double x1=0,x2=0,x3=0,x4=0,x5=0;
    double y1=0,y2=0,y3=0,y4=0,y5=0;
    double Data =  ui->lineEdit->text().toDouble();
    x1=ui->lineEdit_2->text().toDouble(); //56
    x2=ui->lineEdit_3->text().toDouble(); //110
    x3=ui->lineEdit_4->text().toDouble(); //170
    x4=ui->lineEdit_5->text().toDouble(); //220
    x5=ui->lineEdit_6->text().toDouble(); //280

    y1=ui->lineEdit_7->text().toDouble(); //0.267
    y2=ui->lineEdit_8->text().toDouble(); //0.552
    y3=ui->lineEdit_9->text().toDouble(); //0.921
    y4=ui->lineEdit_10->text().toDouble(); //1.162
    y5=ui->lineEdit_11->text().toDouble(); //1.328


    QVector<double> qv_x = {x1,x2,x3,x4,x5};
    QVector<double> qv_y = {y1,y2,y3,y4,y5};
    QVector<double> xv1(1);
    QVector<double> yv1(1);
    QVector<double> xv2(1);
    QVector<double> yv2(1);
    QVector<double> xv3(1);
    QVector<double> yv3(1);
    QVector<double> xv4(1);
    QVector<double> yv4(1);

    xv1[0]=result;
    yv1[0]=Data;
    xv2[0]=result;
    yv2[0]=Data;
    xv3[0]=result;
    yv3[0]=Data;
    xv4[0]=result;
    yv4[0]=Data;

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setData(qv_x, qv_y);
    qDebug()<<qv_x<<""<<qv_y;

    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(1)->setPen(QPen(Qt::red,3));
    if (Data >= y1 && Data < y2)
        ui->customPlot->graph(1)->setData(xv1,yv1);
    else if (Data >= y2 && Data < y3)
        ui->customPlot->graph(1)->setData(xv2,yv2);
    else if (Data >= y3 && Data < y4)
        ui->customPlot->graph(1)->setData(xv3,yv3);
    else if (Data >= y4 && Data < y5)
        ui->customPlot->graph(1)->setData(xv4,yv4);

    ui->customPlot->xAxis->setLabel("Concentration");
    ui->customPlot->yAxis->setLabel("Absorbance");
    ui->customPlot->xAxis->setRange(0, x5+50);
    ui->customPlot->yAxis->setRange(-0.2, y5+0.2);
    ui->customPlot->update();
    ui->customPlot->replot();

}
