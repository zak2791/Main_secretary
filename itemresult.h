#ifndef ITEMRESULT_H
#define ITEMRESULT_H

#include <QGraphicsItem>
#include <QFont>

/////////////////////////////////////////////////////////////
/// элемент с номером жеребьёвки спортсмена в первом кругу //
/////////////////////////////////////////////////////////////

class ItemResultStart : public QGraphicsItem{

public:
    ItemResultStart(int, QString s = "");
    QString num;


private:
    QColor background_color;
    //int id_round;   //идентификатор круга (круг 1, 2, ... или 1/8, 1/4, ...  финала и т. п.)
    int id_pair;    //идентификатор пары спортсменов
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

////////////////////////////////////////////////////////////////
/// элемент с номером жеребьёвки спортсмена во втором кругу и //
///                         последующих                       //
////////////////////////////////////////////////////////////////

class ItemResult : public ItemResultStart{

public:
    ItemResult(int);
    QString num;
    QString result;
    QString time;
    QString vin;
    int id_pair;

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

};


#endif // ITEMRESULT_H
