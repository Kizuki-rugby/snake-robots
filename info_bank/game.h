#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
using namespace std;

class Player; //forward declaration when game.h is included.
#include "player.h"
/**
 * This object will contain following:
 *
 * information about the game that was played,
 * which includes name of game and inal score.
 *
 * References the Player that played it.
 * @brief The Game class
 */
class Game
{
public:
    Player* player;
    Game();
    Game(Player*, string);
    ~Game();
    //information to store.
    int finalScore;
    string gameName;
};

#endif // GAME_H
