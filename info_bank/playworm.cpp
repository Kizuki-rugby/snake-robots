#include "playworm.h"


PlayWorm::PlayWorm(Player* player)
{
    if(player != NULL)
    {
        Game* game = new Game(player, "worm");
        WormTui wt;
        wt.run();
        game->finalScore = wt.w.score;
        player->current = game;
        player->gh->add_game(game);
        player->current = game;
        player->recent = game;
        clear();
    }
    else
    {
        mvprintw(1,1,"Please select a player first!!");
        refresh();
    }
}
PlayWorm::~PlayWorm()
{
    delete game;
}
