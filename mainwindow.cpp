#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    scene8_1_4f = new EightQuarterfinals;
    round_six = new RoundSix;

    btnSidePanel = new QPushButton(this);
    btnSidePanel->setIcon(QIcon(":/open.png"));

    //view = ui->graphicsView;
    view = new ViewWindow(this);
    cb = new QComboBox(view);
    cb->addItem("круговая 6 человек");
    cb->addItem("олимпийка на 68 человек с утешениями от четвертьфиналиста");
    //view->setScene(scene8_1_4f);
    view->setScene(round_six);
    scene8_1_4f->setAge("12-13 лет");
    scene8_1_4f->setWeight("40 кг");
    scene8_1_4f->setCategory("юноши");

    connect(cb, SIGNAL(currentIndexChanged(int)), this, SLOT(shoiceCategory(int)));
    connect(btnSidePanel, SIGNAL(clicked()), this, SLOT(sidePanel()));

    setMinimumWidth(600);

}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::shoiceCategory(int index){
    if(index == 0)
        view->setScene(round_six);
    else
        view->setScene(scene8_1_4f);
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
    if(isSidePanelOpened){
        btnSidePanel->setGeometry(geometry().width() - 300 - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 300 - 12, geometry().height());
    }else{
        btnSidePanel->setGeometry(geometry().width() - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 12, geometry().height());
    }
}

void MainWindow::sidePanel(){
    qDebug()<<"side";
    if(isSidePanelOpened){
        isSidePanelOpened = false;
        btnSidePanel->setIcon(QIcon(":/open.png"));
        btnSidePanel->setGeometry(geometry().width() - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 12, geometry().height());
    }else{
        isSidePanelOpened = true;
        btnSidePanel->setIcon(QIcon(":/close.png"));
        btnSidePanel->setGeometry(geometry().width() - 300 - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 300 - 12, geometry().height());
    }

}

