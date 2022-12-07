#ifndef ITEMRESULT_H
#define ITEMRESULT_H

#include <QGraphicsItem>
#include <QFont>

/////////////////////////////////////////////////////////////
/// элемент с номером жеребьёвки спортсмена в первом кругу //
/////////////////////////////////////////////////////////////

class ItemResultStart : public QGraphicsItem{

public:
    ItemResultStart(QString s = "");
    QString num;


private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

};

////////////////////////////////////////////////////////////////
/// элемент с номером жеребьёвки спортсмена во втором кругу и //
///                         последующих                       //
////////////////////////////////////////////////////////////////

class ItemResult : public ItemResultStart{

public:
    ItemResult();
    QString num;
    QString result;
    QString time;
    QString vin;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

};


#endif // ITEMRESULT_H
