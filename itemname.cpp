#include "itemname.h"

#include <QPainter>

ItemName::ItemName(QString n, QString c, QString r){
    name = n;
    category = c;
    region = r;

}

QRectF ItemName::boundingRect() const{
    return QRectF(0, 0, 240, 40);
}

void ItemName::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(5, 0, 95, 40), name, QTextOption(Qt::AlignLeft | Qt::AlignVCenter));
    painter->drawText(QRectF(100, 0, 40, 40), category, QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(145, 0, 95, 40), region, QTextOption(Qt::AlignLeft | Qt::AlignVCenter));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

ItemNameRound::ItemNameRound(QString n, QString c, QString r):ItemName(n, c, r){


}

QRectF ItemNameRound::boundingRect() const{
    return QRectF(0, 0, 270, 40);
}

void ItemNameRound::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::black);
    painter->drawText(QRectF(0, 0, 120, 40), name, QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(120, 0, 110, 40), region, QTextOption(Qt::AlignCenter));
    painter->drawText(QRectF(230, 0, 40, 40), category, QTextOption(Qt::AlignCenter));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
