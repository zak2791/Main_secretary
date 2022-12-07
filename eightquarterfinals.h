/*///////////////////////////////////////////////////////////
// протокол на 8 человек с утешением от четвертьфиналистов //
///////////////////////////////////////////////////////////*/
#ifndef EIGHTQUARTERFINALS_H
#define EIGHTQUARTERFINALS_H

#include <QGraphicsScene>
//#include <QGraphicsSceneWheelEvent>
//#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include "mainwindow.h"
#include "itemresult.h"
#include "itemname.h"

class EightQuarterfinals : public QGraphicsScene{

   QGraphicsTextItem* category;
   QGraphicsTextItem* age;
   QGraphicsTextItem* weight;
   //QList<QGraphicsTextItem*> final2;
   //QList<QGraphicsTextItem*> final;
   QGraphicsItemGroup* final4;
   QGraphicsItemGroup* final2;
   QGraphicsItemGroup* consolation1;
   QGraphicsItemGroup* consolation2;
   ItemName* name1;
   ItemName* name2;
   ItemName* name3;
   ItemName* name4;
   ItemName* name5;
   ItemName* name6;
   ItemName* name7;
   ItemName* name8;

public:
    EightQuarterfinals();
    void setWeight(QString);
    void setCategory(QString);
    void setAge(QString);
};

#endif // EIGHTQUARTERFINALS_H
