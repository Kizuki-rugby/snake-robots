#ifndef PLAYWORM_H
#define PLAYWORM_H
#include "game.h"
#include "player.h"
#include "../tui/wormtui.h"

class PlayWorm
{
public:
    PlayWorm(Player* player);
    ~PlayWorm();
    WormTui* wt;
    Game* game;
};

#endif // PLAYWORM_H
