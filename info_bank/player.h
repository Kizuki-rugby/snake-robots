#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>

using namespace std;

class Game; //forward declaration
#include "game.h"

class GameHistory;
#include "gamehistory.h"

class Player
{
public:
    Player(string playerNameFirst, string playerNameLast, string playerAddress);
    string playerNameFirst, playerNameLast, playerAddress;
    GameHistory* gh;
    Game* recent;
    Game* current;
};

#endif // PLAYER_H
