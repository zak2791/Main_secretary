#include "itemresult.h"

#include <QPainter>
#include <QDebug>
#include <QTextOption>

ItemResultStart::ItemResultStart(QString s){
    num = s;
}

QRectF ItemResultStart::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определяться нажатие точки
     * */
    return QRectF(0, 0, 40, 40);
}

void ItemResultStart::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(0, 0, 20, 40), num, QTextOption(Qt::AlignCenter));
    Q_UNUSED(option);
    Q_UNUSED(widget);
    qDebug()<<num;
}

void ItemResultStart::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"press";
}

ItemResult::ItemResult(){
    result = "5:0";
    num = "1";
    time = "3:57";
    vin = "НБП";

}

QRectF ItemResult::boundingRect() const
{
    /* возвращаем координаты расположения точки
     * по ним будет определяться нажатие точки
     * */
    return QRectF(0, 0, 60, 40);
}

void ItemResult::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Устанавливаем кисть в QPainter и отрисовываем круг, то есть ТОЧКУ
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(0, 0, 40, 20), num, QTextOption(Qt::AlignCenter));
    int size = painter->font().pointSize() * 0.75;
    QFont f = painter->font();
    f.setPointSize(size);
    painter->setFont(f);
    painter->drawText(QRect(0, 20, 20, 20), result, QTextOption(Qt::AlignCenter));
    painter->drawText(QRect(20, 20, 20, 20), time, QTextOption(Qt::AlignCenter));
    painter->drawText(QRect(0, 40, 20, 20), vin, QTextOption(Qt::AlignCenter));

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void ItemResult::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<"press";
}
