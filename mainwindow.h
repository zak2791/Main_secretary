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
    //btnSidePanel->setI

    RoundSix* round_six;
    EightQuarterfinals* scene8_1_4f;

    virtual void keyPressEvent(QKeyEvent*);
    virtual void resizeEvent(QResizeEvent*);

    bool isSidePanelOpened = false;

private slots:
    void shoiceCategory(int);
    void sidePanel(void);

};
#endif // MAINWINDOW_H
