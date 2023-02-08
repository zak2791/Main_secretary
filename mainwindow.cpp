#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QClipboard>

#include "createnewcategory.h"
#include <QLabel>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    //scene8_1_4f = new EightQuarterfinals("", "", "");
    //round_six = new RoundSix;

    btnSidePanel = new QPushButton(this);
    btnSidePanel->setIcon(QIcon(":/open.png"));

    btnAddCategory = new QPushButton("Новая категория", this);
    connect(btnAddCategory, SIGNAL(clicked()), this, SLOT(addCategory()));

    QLabel* lblNumber = new QLabel("№ по\nжеребьёвке");
    QComboBox* cmbNumber = new QComboBox;
    cmbNumber->setObjectName("cmbNumber");
    cmbNumber->addItems({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    QVBoxLayout* vBoxNumber = new QVBoxLayout;
    vBoxNumber->addWidget(lblNumber);
    vBoxNumber->addWidget(cmbNumber);

    QLabel* lblName= new QLabel("Фамилия,\nимя");
    QComboBox* cmbName = new QComboBox;
    cmbName->setObjectName("cmbName");
    cmbName->addItems({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    QVBoxLayout* vBoxName = new QVBoxLayout;
    vBoxName->addWidget(lblName);
    vBoxName->addWidget(cmbName);

    QLabel* lblRate= new QLabel("Разряд,\nзвание");
    QComboBox* cmbRate = new QComboBox;
    cmbRate->setObjectName("cmbRate");
    cmbRate->addItems({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    QVBoxLayout* vBoxRate = new QVBoxLayout;
    vBoxRate->addWidget(lblRate);
    vBoxRate->addWidget(cmbRate);

    QLabel* lblRegion = new QLabel("Команда,\nрегион");
    QComboBox* cmbRegion = new QComboBox;
    cmbRegion->setObjectName("cmbRegion");
    cmbRegion->addItems({"1", "2", "3", "4", "5", "6", "7", "8", "9"});
    QVBoxLayout* vBoxRegion = new QVBoxLayout;
    vBoxRegion->addWidget(lblRegion);
    vBoxRegion->addWidget(cmbRegion);

    QHBoxLayout* hBoxLabelCombo = new QHBoxLayout;
    hBoxLabelCombo->addLayout(vBoxNumber);
    hBoxLabelCombo->addLayout(vBoxName);
    hBoxLabelCombo->addLayout(vBoxRate);
    hBoxLabelCombo->addLayout(vBoxRegion);

    QLabel* lblSettings = new QLabel("Настройка расположения столбцов в файле Excel");
    QVBoxLayout* vBox = new QVBoxLayout;
    vBox->addWidget(lblSettings);
    vBox->addLayout(hBoxLabelCombo);

    frmSettings = new QFrame(this);
    frmSettings->setFrameShape(QFrame::Box);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(btnAddCategory);

    layout->addLayout(vBox);

    frmSettings->setLayout(layout);

    QFile file("settings.txt");
    if(!file.exists()){
        file.open(QIODevice::WriteOnly);
        file.write("1\n2\n3\n4\n");
        file.close();
    }

    file.open(QIODevice::ReadOnly);
    columnNumber = file.readLine().toInt();
    cmbNumber->setCurrentText(QString::number(columnNumber));
    columnName = file.readLine().toInt();
    cmbName->setCurrentText(QString::number(columnName));
    columnRate = file.readLine().toInt();
    cmbRate->setCurrentText(QString::number(columnRate));
    columnRegion = file.readLine().toInt();
    cmbRegion->setCurrentText(QString::number(columnRegion));
    file.close();

    connect(cmbNumber,  SIGNAL(currentTextChanged(QString)), this, SLOT(changeSettings(QString)));
    connect(cmbName,    SIGNAL(currentTextChanged(QString)), this, SLOT(changeSettings(QString)));
    connect(cmbRate,    SIGNAL(currentTextChanged(QString)), this, SLOT(changeSettings(QString)));
    connect(cmbRegion,  SIGNAL(currentTextChanged(QString)), this, SLOT(changeSettings(QString)));



    twMats = new QTabWidget(this);
    gvMat1 = new QGraphicsView();
    gvMat2 = new QGraphicsView();
    gvMat3 = new QGraphicsView();
    gvMat4 = new QGraphicsView();
    twMats->addTab(gvMat1, "Ковёр 1");
    twMats->addTab(gvMat2, "Ковёр 2");
    twMats->addTab(gvMat3, "Ковёр 3");
    twMats->addTab(gvMat4, "Ковёр 4");

    //view = ui->graphicsView;
    view = new ViewWindow(this);
    cb = new QComboBox(view);
    cb->setMaximumWidth(300);
    //cb->addItem("");
    //cb->addItem("круговая 6 человек");
    //cb->addItem("олимпийка на 68 человек с утешениями от четвертьфиналиста");
    //view->setScene(scene8_1_4f);
    //view->setScene(round_six);
    //scene8_1_4f->setAge("12-13 лет");
    //scene8_1_4f->setWeight("40 кг");
    //scene8_1_4f->setCategory("юноши");


    connect(cb, SIGNAL(currentIndexChanged(int)), this, SLOT(shoiceCategory(int)));
    connect(btnSidePanel, SIGNAL(clicked()), this, SLOT(sidePanel()));

    setMinimumWidth(600);
    setMinimumHeight(300);

}

MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::shoiceCategory(int index){
    /*
    if(index == 0)
        view->setScene(round_six);
    else
        view->setScene(scene8_1_4f);
        */
    qDebug()<<"index = "<<index;
    view->setScene(lScene.at(index));
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
        btnSidePanel->setGeometry(geometry().width() - 400 - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 400 - 12, geometry().height());
    }else{
        btnSidePanel->setGeometry(geometry().width() - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 12, geometry().height());
    }
    //btnAddCategory->setGeometry(geometry().width() - 400 + 100, 20, 400 - 200, 30);
    frmSettings->setGeometry(geometry().width() - 400, 0, 400, 100);
    twMats->setGeometry(geometry().width() - 400 + 10, 100, 380, geometry().height() - 105);
    //cb->setGeometry(0, 0, view->width() - 50, cb->height());
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
        btnSidePanel->setGeometry(geometry().width() - 400 - 12, 0, 12, geometry().height());
        view->setGeometry(0, 0, geometry().width() - 400 - 12, geometry().height());
    }
    cb->setGeometry(0, 0, view->width() - 50, cb->height());
    qDebug()<<cb->height();
}

///////////////////////////////////////////////////////////
/* Добавление новой категории с данными из буфера обмена */
///////////////////////////////////////////////////////////

void MainWindow::addCategory(){
    QClipboard* pcb = QApplication::clipboard();
    //qDebug()<<pcb->text().split("\n");
    QList<QString> rowsFromExcel = pcb->text().split("\n");
    QString str;

    int maxColumn = columnNumber;
    if(maxColumn < columnName)
        maxColumn = columnName;
    if(maxColumn < columnRate)
        maxColumn = columnRate;
    if(maxColumn < columnRegion)
        maxColumn = columnRegion;

    foreach (str, rowsFromExcel){
        QList<QString> row = str.split("\t");
        int i = row.at(0).toInt();

        if(i > 0){
            if(row.length() < maxColumn){
                qDebug()<<"неправильные данные в буфере обмена";
                return;
            }
            qDebug()<<"number "<<i;
        }else
        {
            break;
            qDebug()<<"not number"<<i;
        }
    }

    //QList<int> l;
    CreateNewCategory* dialog = new CreateNewCategory(pcb->text(), QList<int>({columnNumber,
                                                                               columnName,
                                                                               columnRate,
                                                                               columnRegion}));
    //dialog->setModal(true);
    dialog->setWindowModality(Qt::ApplicationModal);
    connect(dialog, SIGNAL(ageSet(QString)), this, SLOT(setAge(QString)));
    connect(dialog, SIGNAL(weightSet(QString)), this, SLOT(setWeight(QString)));
    connect(dialog, SIGNAL(categorySet(QString)), this, SLOT(setCategory(QString)));
    connect(dialog, SIGNAL(kindSet(QString)), this, SLOT(setMethod(QString)));

    connect(dialog, SIGNAL(accepted()), this, SLOT(newCategoryOk()));
    //connect(dialog, SIGNAL(rejected()), this, SLOT(newCategoryCancel()));

    //dialog->open();
    //dialog->hide();
    dialog->show();

    name = "";
    age = "";
    weight = "";
    gender = "";
    methodCompetition = "";

}

void MainWindow::setAge(QString s){
    age = s;
}

void MainWindow::setWeight(QString s){
    weight = s;
}

void MainWindow::setCategory(QString s){
    gender = s;
}

void MainWindow::setMethod(QString s){
    methodCompetition = s;
}

void MainWindow::newCategoryOk(){
    qDebug()<<age<<weight<<gender<<methodCompetition;
    QString item = "";
    if(methodCompetition == "утешения от полуфиналиста на 8 человек"){
        lScene.append(new EightQuarterfinals(gender, age, weight));
        item = gender + " " + age + " " + weight;
    }else if(methodCompetition == "круговая на 6 человек"){
        lScene.append(new RoundSix(gender, age, weight));
        item = gender + " " + age + " " + weight;
    }
    cb->addItem(item);
    cb->setCurrentText(item);
}

void MainWindow::changeSettings(QString s){
    if(sender()->objectName() == "cmbNumber")
        columnNumber = s.toInt();
    else if(sender()->objectName() == "cmbName")
        columnName = s.toInt();
    else if(sender()->objectName() == "cmbRate")
        columnRate = s.toInt();
    else
        columnRegion = s.toInt();

    QFile file("settings.txt");

    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    out << QString::number(columnNumber) << "\n" << QString::number(columnName) << "\n"
        << QString::number(columnRate) << "\n" << QString::number(columnRegion) << "\n";
    file.close();
}
