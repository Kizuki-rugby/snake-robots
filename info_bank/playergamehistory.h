#ifndef PLAYERGAMEHISTORY_H
#define PLAYERGAMEHISTORY_H
#include "player.h"
#include <iostream>
#include <vector>
using namespace std ;

class PlayerGameHistory
{
public:
    PlayerGameHistory();
    void add_player(Player*);
    void add_game(Game*);
    int totalGames();
    int players();
    int averageGames();
    int topScore();
    int averageScore();
    int averagePlayerScore(Player*);
    vector<Player*> playerHistory;
};

#endif // PLAYERGAMEHISTORY_H
