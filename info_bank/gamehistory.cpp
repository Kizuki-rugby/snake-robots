#include "gamehistory.h"

GameHistory::GameHistory()
{
}
/**
 * This function will add the game into the vector by chronological order.
 * @brief GameHistory::add_game
 * @param game
 */
void GameHistory::add_game(Game* game)
{
    games.push_back(game);
}


/**
– Stores the games played for a specific player in game played order.
– References each game played by the specific player.
*/
