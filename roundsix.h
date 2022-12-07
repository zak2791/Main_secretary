#ifndef ROUNDSIX_H
#define ROUNDSIX_H

#include <QGraphicsScene>
#include "itemname.h"

class RoundSix : public QGraphicsScene{

    ItemNameRound* name1;
    ItemNameRound* name2;
    ItemNameRound* name3;
    ItemNameRound* name4;
    ItemNameRound* name5;
    ItemNameRound* name6;

public:
    RoundSix();
};

#endif // ROUNDSIX_H
