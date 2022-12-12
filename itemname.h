#ifndef ITEMNAME_H
#define ITEMNAME_H

#include <QGraphicsItem>

class ItemName : public QGraphicsItem{

public:
    ItemName(QString, QString, QString);
    QString name;       //Фамилия, Имя
    QString category;   //Категория (мужчины, женщины ...)
    QString region;     //Регион
    int number;         //Номер по жеребьёвке


private:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);



};

class ItemNameRound : public ItemName{

public:
    ItemNameRound(QString, QString, QString);

private:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // ITEMNAME_H
