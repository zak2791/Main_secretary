#include "eightquarterfinals.h"

#include <QGraphicsView>
#include <QtDebug>
#include <QScrollBar>

EightQuarterfinals::EightQuarterfinals(){
    int x = 0;
    int y = 0;
    //p = (MainWindow*)parent;

    //scaleScene = 1.0;

    QPen widePen;
    QPen narrowPen;
    widePen.setWidthF(1.5);
    narrowPen.setWidthF(0.5);

    addLine(x + 0, y + 0, x + 280, y + 0, widePen);
    addLine(x + 0, y + 40, x + 280, y + 40, narrowPen);
    addLine(x + 0, y + 80, x + 280, y + 80, widePen);
    addLine(x + 0, y + 120, x + 280, y + 120, narrowPen);
    addLine(x + 0, y + 160, x + 280, y + 160, widePen);
    addLine(x + 0, y + 200, x + 280, y + 200, narrowPen);
    addLine(x + 0, y + 240, x + 280, y + 240, widePen);
    addLine(x + 0, y + 280, x + 280, y + 280, narrowPen);
    addLine(x + 0, y + 320, x + 280, y + 320, widePen);

    addLine(x + 0, y + 0, x + 0, y + 320, narrowPen);
    addLine(x + 20, y + 0, x + 20, y + 320, narrowPen);
    addLine(x + 140, y + 0, x + 140, y + 320, narrowPen);
    addLine(x + 180, y + 0, x + 180, y + 320, narrowPen);
    addLine(x + 280, y + 0, x + 280, y + 320, widePen);

    addLine(x + 280, y + 20, x + 320, y + 20, widePen);
    addLine(x + 280, y + 60, x + 360, y + 60, widePen);
    addLine(x + 280, y + 100, x + 360, y + 100, widePen);
    addLine(x + 280, y + 140, x + 320, y + 140, widePen);

    addLine(x + 280, y + 180, x + 320, y + 180, widePen);
    addLine(x + 280, y + 220, x + 360, y + 220, widePen);
    addLine(x + 280, y + 260, x + 360, y + 260, widePen);
    addLine(x + 280, y + 300, x + 320, y + 300, widePen);

    addLine(x + 320, y + 20, x + 320, y + 140, widePen);
    addLine(x + 320, y + 180, x + 320, y + 300, widePen);

    addLine(x + 360, y + 60, x + 360, y + 100, widePen);
    addLine(x + 360, y + 100, x + 360, y + 110, narrowPen);
    addLine(x + 360, y + 110, x + 360, y + 150, widePen);
    addLine(x + 360, y + 150, x + 360, y + 170, narrowPen);
    addLine(x + 360, y + 170, x + 360, y + 210, widePen);
    addLine(x + 360, y + 210, x + 360, y + 220, narrowPen);
    addLine(x + 360, y + 220, x + 360, y + 260, widePen);

    addLine(x + 360, y + 110, x + 400, y + 110, widePen);
    addLine(x + 360, y + 150, x + 400, y + 150, widePen);
    addLine(x + 360, y + 170, x + 400, y + 170, widePen);
    addLine(x + 360, y + 210, x + 400, y + 210, widePen);

    addLine(x + 400, y + 110, x + 400, y + 150, widePen);
    addLine(x + 400, y + 170, x + 400, y + 210, widePen);

    addLine(x + 380, y + 0, x + 380, y + 80, widePen);
    addLine(x + 420, y + 0, x + 420, y + 100, widePen);
    addLine(x + 460, y + 20, x + 460, y + 100, widePen);
    addLine(x + 500, y + 40, x + 500, y + 80, widePen);

    addLine(x + 380, y + 0, x + 420, y + 0, widePen);
    addLine(x + 420, y + 20, x + 460, y + 20, widePen);
    addLine(x + 460, y + 40, x + 500, y + 40, widePen);
    addLine(x + 380, y + 0, x + 420, y + 0, widePen);
    addLine(x + 380, y + 40, x + 420, y + 40, widePen);
    addLine(x + 380, y + 80, x + 420, y + 80, widePen);
    addLine(x + 420, y + 60, x + 460, y + 60, widePen);
    addLine(x + 420, y + 100, x + 460, y + 100, widePen);
    addLine(x + 460, y + 80, x + 500, y + 80, widePen);

    addLine(x + 380, y + 220, x + 380, y + 300, widePen);
    addLine(x + 420, y + 220, x + 420, y + 320, widePen);
    addLine(x + 460, y + 240, x + 460, y + 320, widePen);
    addLine(x + 500, y + 260, x + 500, y + 300, widePen);

    addLine(x + 380, y + 220, x + 420, y + 220, widePen);
    addLine(x + 420, y + 240, x + 460, y + 240, widePen);
    addLine(x + 460, y + 260, x + 500, y + 260, widePen);
    addLine(x + 380, y + 220, x + 420, y + 220, widePen);
    addLine(x + 380, y + 260, x + 420, y + 260, widePen);
    addLine(x + 380, y + 300, x + 420, y + 300, widePen);
    addLine(x + 420, y + 280, x + 460, y + 280, widePen);
    addLine(x + 420, y + 320, x + 460, y + 320, widePen);
    addLine(x + 460, y + 300, x + 500, y + 300, widePen);

    //ui->graphicsView->setTransform(QTransform().scale(2, 2));
    ItemName* name1 = new ItemName("Абдурахман ибн Хоттаб", "КМС", "Брянская обл.");
    addItem(name1);
    name1->setPos(20, 0);
    ItemName* name2 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name2);
    name2->setPos(20, 40);
    ItemName* name3 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name3);
    name3->setPos(20, 80);
    ItemName* name4 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name4);
    name4->setPos(20, 120);
    ItemName* name5 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name5);
    name5->setPos(20, 160);
    ItemName* name6 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name6);
    name6->setPos(20, 200);
    ItemName* name7 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name7);
    name7->setPos(20, 240);
    ItemName* name8 = new ItemName("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name8);
    name8->setPos(20, 280);


    QFont f; //= font()
    f.setPointSize(font().pointSize() * 1.5);

    QGraphicsTextItem* place_3_A = addText("3 место");
    place_3_A->setPos(500, 50);
    place_3_A->setFont(f);

    QGraphicsTextItem* place_3_B = addText("3 место");
    place_3_B->setPos(500, 270);
    place_3_B->setFont(f);

    QGraphicsTextItem* place_1 = addText("1 место");
    place_1->setPos(400, 120);
    place_1->setFont(f);

    QGraphicsTextItem* place_2 = addText("2 место");
    place_2->setPos(400, 180);
    place_2->setFont(f);

    QGraphicsTextItem* groupA = addText("Подгруппа А");
    groupA->setPos(0, -30);
    groupA->setFont(f);

    QGraphicsTextItem* groupB = addText("Подгруппа Б");
    groupB->setPos(0, 320);
    groupB->setFont(f);

    QGraphicsTextItem* groupA2 = addText("Утешительная подгруппа А");
    groupA2->setPos(380, -30);
    groupA2->setFont(f);

    QGraphicsTextItem* groupB2 = addText("Утешительная подгруппа Б");
    groupB2->setPos(380, 320);
    groupB2->setFont(f);

    ItemResultStart* num1 = new ItemResultStart("1");
    addItem(num1);
    num1->setPos(0, 0);
    ItemResultStart* num2 = new ItemResultStart("2");
    addItem(num2);
    num2->setPos(0, 160);
    ItemResultStart* num3 =new ItemResultStart("3");
    addItem(num3);
    num3->setPos(0, 80);
    ItemResultStart* num4 = new ItemResultStart("4");
    addItem(num4);
    num4->setPos(0, 240);
    ItemResultStart* num5 = new ItemResultStart("5");
    addItem(num5);
    num5->setPos(0, 40);
    ItemResultStart* num6 =new ItemResultStart("6");
    addItem(num6);
    num6->setPos(0, 200);
    ItemResultStart* num7 = new ItemResultStart("7");
    addItem(num7);
    num7->setPos(0, 120);
    ItemResultStart* num8 = new ItemResultStart("8");
    addItem(num8);
    num8->setPos(0, 280);

    category = new QGraphicsTextItem;
    addItem(category);
    category->setPos(150, -70);
    category->setFont(f);
    age = new QGraphicsTextItem;
    addItem(age);
    age->setPos(270, -70);
    age->setFont(f);
    weight = new QGraphicsTextItem;
    addItem(weight);
    weight->setPos(400, -70);
    weight->setFont(f);

    ItemResult* i = new ItemResult();
    i->setPos(280, 20);
    addItem(i);

}

void EightQuarterfinals::setCategory(QString s){
    category->setPlainText(s);
}

void EightQuarterfinals::setWeight(QString s){
    weight->setPlainText(s);
}

void EightQuarterfinals::setAge(QString s){
    age->setPlainText(s);
}

/*
void EightQuarterfinals::wheelEvent(QGraphicsSceneWheelEvent* e){
    if(e->delta() > 0)
        scaleScene += 0.1;
    else
        scaleScene -= 0.1;
    qDebug()<<scaleScene;
    p->view->setTransform(QTransform().scale(scaleScene, scaleScene));
}
*/

//void EightQuarterfinals::mouseMoveEvent(QGraphicsSceneMouseEvent* e){
    //qDebug()<<e->pos().x()<<e->pos().y();
    //if(e->buttons() == Qt::LeftButton){
        //p->view->centerOn(280, 100);// ensureVisible(QRectF(100, 100, 0, 0));
        //QScrollBar* hBar = p->view->horizontalScrollBar();
        //qDebug()<<"hBar->value()"<<hBar->value();
        //hBar->setValue(hBar->value() - 1);
    //}
//}
