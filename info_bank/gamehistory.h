#ifndef GAMEHISTORY_H
#define GAMEHISTORY_H
#include <queue>
#include <iostream>
using namespace std;
class Game;

/**
 * this object will be storing following information:
 * Stores the games played for a specific player in game played order.
 * References each game played by the specific player.
 * @brief The GameHistory class
 */
class GameHistory
{
public:
    GameHistory();
    vector<Game*> games;
    void add_game(Game*);
};

#endif // GAMEHISTORY_H
