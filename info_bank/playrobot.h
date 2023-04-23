#ifndef PLAYROBOT_H
#define PLAYROBOT_H
#include "game.h"
#include "player.h"
#include "../tui/robottui.h"


class PlayRobot
{
public:
    PlayRobot(Player*);
    ~PlayRobot();
    robottui* rt;
    Game* game;
    Player* player;
};

#endif // PLAYROBOT_H
