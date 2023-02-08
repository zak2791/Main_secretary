#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "viewwindow.h"
#include <QComboBox>
#include "eightquarterfinals.h"
#include "roundsix.h"
#include <QPushButton>

/*
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ViewWindow* view;

private:
    //Ui::MainWindow *ui;
    QComboBox* cb;
    QPushButton* btnSidePanel;
    QPushButton* btnAddCategory;
    QFrame* frmSettings;
    QTabWidget* twMats;
    QGraphicsView* gvMat1;
    QGraphicsView* gvMat2;
    QGraphicsView* gvMat3;
    QGraphicsView* gvMat4;

    RoundSix* round_six;
    EightQuarterfinals* scene8_1_4f;
    QList<QGraphicsScene*> lScene;

    virtual void keyPressEvent(QKeyEvent*);
    virtual void resizeEvent(QResizeEvent*);

    bool isSidePanelOpened = false;

    QString name;
    QString age;
    QString weight;
    QString gender;
    QString methodCompetition;

    /*----------------- В выделении файла excel -------------------*/
    int columnNumber;       //колонка номера по жжеребьёвке
    int columnName;         //колонка фамилии, имени спортсмена
    int columnRate;         //колонка разряда, звания
    int columnRegion;       //колонка региона, команды

private slots:
    void shoiceCategory(int);
    void sidePanel(void);
    void addCategory(void);
    void setAge(QString);
    void setWeight(QString);
    void setCategory(QString);
    void setMethod(QString);
    void newCategoryOk(void);
    void changeSettings(QString);
    //void newCategoryCancel(void);

};
#endif // MAINWINDOW_H
