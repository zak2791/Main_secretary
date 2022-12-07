#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QGraphicsView>
#include <QMouseEvent>

class ViewWindow : public QGraphicsView{
    float scaleScene;

public:
    ViewWindow(QWidget *parent = nullptr);
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void wheelEvent(QWheelEvent*);
};

#endif // VIEWWINDOW_H
