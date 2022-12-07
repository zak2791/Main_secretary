#ifndef ITEMNAME_H
#define ITEMNAME_H

#include <QGraphicsItem>

class ItemName : public QGraphicsItem{

public:
    ItemName(QString, QString, QString);


private:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    QString name;
    QString category;
    QString region;

};

class ItemNameRound : public ItemName{

public:
    ItemNameRound(QString, QString, QString);

private:
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // ITEMNAME_H
