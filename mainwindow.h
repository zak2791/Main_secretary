#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "viewwindow.h"
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

    virtual void keyPressEvent(QKeyEvent*);
    virtual void resizeEvent(QResizeEvent*);

};
#endif // MAINWINDOW_H
