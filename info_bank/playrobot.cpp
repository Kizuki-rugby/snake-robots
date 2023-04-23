#include "playrobot.h"



PlayRobot::PlayRobot(Player* player)
{
    if(player != NULL)
    {
        Game* game = new Game(player, "robot");
        robottui rt;
        rt.runit();
        game->finalScore = rt.r.currScore;
        player->gh->add_game(game);
        player->current = game;
        player->recent = game;
        clear();
    }
    else
    {
        // else where we have to go back to the main menu
        mvprintw(1,1,"Please select a player first!!");
        refresh();
    }
}

PlayRobot::~PlayRobot()
{
    delete game;
}
