#include "game.h"

/**
 * Constructor that takes parameter of player pointer and string of gamename
 * within a constructor it will updates needed information.
 * @brief Game::Game
 * @param player
 * @param gameName
 */
Game::Game(Player* player, string gameName)
{
    this->player = player;
    this->gameName = gameName;
}


Game::~Game()
{

}

/**
  Contains information about the game that was played.
– References the Player that played it.
– Stores the following information:
1. Name of game
2. Final score
**/
