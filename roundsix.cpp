#include "roundsix.h"

RoundSix::RoundSix(QString sGender, QString sAge, QString sWeight){
    int x = 0;
    int y = 0;

    QPen widePen;
    QPen narrowPen;
    widePen.setWidthF(1.5);
    narrowPen.setWidthF(0.5);

    addLine(x + 0, y + 0, x + 630, y + 0, widePen);
    addLine(x + 0, y + 40, x + 630, y + 40, widePen);
    addLine(x + 0, y + 0, x + 0, y + 280, widePen);
    addLine(x + 20, y + 0, x + 20, y + 280, widePen);
    addLine(x + 140, y + 0, x + 140, y + 280, widePen);
    addLine(x + 250, y + 0, x + 250, y + 280, widePen);
    addLine(x + 290, y + 0, x + 290, y + 280, widePen);
    addLine(x + 510, y + 0, x + 510, y + 280, widePen);
    addLine(x + 550, y + 0, x + 550, y + 280, widePen);
    addLine(x + 590, y + 0, x + 590, y + 280, widePen);
    addLine(x + 630, y + 0, x + 630, y + 280, widePen);

    addLine(x + 0, y + 80, x + 630, y + 80, widePen);
    addLine(x + 0, y + 120, x + 630, y + 120, widePen);
    addLine(x + 0, y + 160, x + 630, y + 160, widePen);
    addLine(x + 0, y + 200, x + 630, y + 200, widePen);
    addLine(x + 0, y + 240, x + 630, y + 240, widePen);
    addLine(x + 0, y + 280, x + 630, y + 280, widePen);

    QGraphicsTextItem* i1 = addText("1");
    i1->setPos(3, 50);
    QGraphicsTextItem* i2 = addText("2");
    i2->setPos(3, 90);
    QGraphicsTextItem* i3 = addText("3");
    i3->setPos(3, 130);
    QGraphicsTextItem* i4 = addText("4");
    i4->setPos(3, 170);
    QGraphicsTextItem* i5 = addText("5");
    i5->setPos(3, 210);
    QGraphicsTextItem* i6 = addText("6");
    i6->setPos(3, 250);

    ItemNameRound* name1 = new ItemNameRound("Иванов Иван", "КМС", "Брянская обл.");
    addItem(name1);
    name1->setPos(20, 40);
    ItemNameRound* name2 = new ItemNameRound("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name2);
    name2->setPos(20, 80);
    ItemNameRound* name3 = new ItemNameRound("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name3);
    name3->setPos(20, 120);
    ItemNameRound* name4 = new ItemNameRound("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name4);
    name4->setPos(20, 160);
    ItemNameRound* name5 = new ItemNameRound("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name5);
    name5->setPos(20, 200);
    ItemNameRound* name6 = new ItemNameRound("Фамилия Имя", "КМС", "Брянская обл.");
    addItem(name6);
    name6->setPos(20, 240);

    QFont f; //= font()
    f.setPointSize(font().pointSize() * 1.5);

    QGraphicsTextItem* category = new QGraphicsTextItem;
    addItem(category);
    category->setPos(150, -70);
    category->setFont(f);
    category->setPlainText(sGender);

    QGraphicsTextItem* age = new QGraphicsTextItem;
    addItem(age);
    age->setPos(270, -70);
    age->setFont(f);
    age->setPlainText(sAge);

    QGraphicsTextItem* weight = new QGraphicsTextItem;
    addItem(weight);
    weight->setPos(400, -70);
    weight->setFont(f);
    weight->setPlainText(sWeight);

}
