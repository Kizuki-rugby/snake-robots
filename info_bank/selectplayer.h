#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H
#include <curses.h>
#include <iostream>
#include <string>
#include "playergamehistory.h"

class selectplayer
{
public:
    selectplayer(PlayerGameHistory* ph);
    ~selectplayer();

    Player* current;
};

#endif // SELECTPLAYER_H
