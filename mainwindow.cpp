#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "eightquarterfinals.h"
#include "roundsix.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    EightQuarterfinals* scene8_1_4f = new EightQuarterfinals;
    RoundSix* round_six = new RoundSix;

    //view = ui->graphicsView;
    view = new ViewWindow(this);
    //view->setScene(scene8_1_4f);
    view->setScene(round_six);
    scene8_1_4f->setAge("12-13 лет");
    scene8_1_4f->setWeight("40 кг");
    scene8_1_4f->setCategory("юноши");

}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* e){
    qDebug()<<e;
    if(e->key() == Qt::Key_A){
        //scaleScene -= 0.1;
        //ui->graphicsView->setTransform(QTransform().scale(scaleScene, scaleScene));
    }
    if(e->key() == Qt::Key_D){
        //scaleScene += 0.1;
        //ui->graphicsView->setTransform(QTransform().scale(scaleScene, scaleScene));
    }

}

void MainWindow::resizeEvent(QResizeEvent*){
    view->setGeometry(0, 0, geometry().width(), geometry().height());
}

