#include "viewwindow.h"

#include <QDebug>

ViewWindow::ViewWindow(QWidget *parent) : QGraphicsView(parent){
    scaleScene = 1.0;

}

void ViewWindow::mouseMoveEvent(QMouseEvent* e){
    if(e->buttons() == Qt::LeftButton)
        centerOn(e->pos().x(), e->pos().y());
        //centerOn(width() - e->pos().x(), height() - e->pos().y());
}

void ViewWindow::wheelEvent(QWheelEvent* e){
    if(e->delta() > 0)
        scaleScene += 0.1;
    else
        scaleScene -= 0.1;
    setTransform(QTransform().scale(scaleScene, scaleScene));
}
