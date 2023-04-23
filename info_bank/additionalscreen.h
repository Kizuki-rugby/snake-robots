#ifndef ADDITIONALSCREEN_H
#define ADDITIONALSCREEN_H
#include "../tui/screen.h"
#include "../tui/wormtui.h"
#include "../tui/robottui.h"
#include "game.h"
#include "player.h"
#include "createplayer.h"
#include "playergamehistory.h"
#include "playworm.h"
#include "playrobot.h"
#include "selectplayer.h"
#include <curses.h>
#include <form.h>
#include <string>
#include <iostream>
#include "topscores.h"
#include "topplayers.h"
#include "stats.h"


class AdditionalScreen
{
public:
    AdditionalScreen();
    ~AdditionalScreen();
    WormTui wt;
    void main_screen();
    void new_player();
    void select_existing_player();
    void display_top_three_players();
    void display_top_three_games();
    void display_calculated_statistics();
    void play_robot();
    void play_worm();
    Player* player;
    Game* game;
    PlayerGameHistory* ph;
    PlayWorm* pw;
    PlayRobot* pr;
};

#endif // ADDITIONALSCREEN_H
