#include "playergamehistory.h"


PlayerGameHistory::PlayerGameHistory()
{

}

// TODO: have to think of existed case(unique player)

void PlayerGameHistory::add_player(Player* player)
{
    playerHistory.push_back(player);
}

\
/**
 * Will return the total number of games played
 * @brief PlayerGameHistory::totalGames
 * @param gh
 * @return
 */
int PlayerGameHistory::totalGames() {
    int count = 0;
    for (unsigned long i=0; i<playerHistory.size(); i++) {
        count += playerHistory.at(i)->gh->games.size();
    }
    return count;
}

/**
 * Will return the number of players that have played games
 * @brief PlayerGameHistory::averageGames
 * @return
 */
int PlayerGameHistory::players() {
    int count = 0;
    for (unsigned long i=0; i<playerHistory.size(); i++) {
        if (playerHistory.at(i)->gh->games.size() != 0) {
            count++;
        }
    }
    return count;
}

/**
 * Will return the average number of games played per player
 * @brief PlayerGameHistory::averageGames
 * @return
 */
int PlayerGameHistory::averageGames() {
    int count = 0;
    for (unsigned long i=0; i<playerHistory.size(); i++) {
        count += playerHistory.at(i)->gh->games.size();
    }
    return (int)(count/playerHistory.size());
}

/**
 * Will return the highest game score, regardless of game type
 * @brief PlayerGameHistory::topScore
 * @return
 */
int PlayerGameHistory::topScore() {     //probably should have leveraged sorting functionality in vector class...
    int top = 0;
    for (unsigned long i=0; i<playerHistory.size(); i++) {
        for (unsigned long j=0; j<playerHistory.at(i)->gh->games.size(); j++) {
            if (playerHistory.at(i)->gh->games.at(j)->finalScore > top) {
                top = playerHistory.at(i)->gh->games.at(j)->finalScore;
            }
        }
    }
    return top;
}

/**
 * Will return the average game score
 * @brief PlayerGameHistory::averageScore
 * @return
 */
int PlayerGameHistory::averageScore() {
    int count = 0;
    int score = 0;
    int gameCount = 0;
    for (unsigned long i=0; i<playerHistory.size(); i++) {
        for (unsigned long j=0; j<playerHistory.at(i)->gh->games.size(); j++) {
            gameCount++;
            count += playerHistory.at(i)->gh->games.at(j)->finalScore;
            if (gameCount == 1) score = count;
            score = count/gameCount;
        }
    }
    return score;
}

/**
 * Will return the average score for a player
 * @brief PlayerGameHistory::averagePlayerScore
 * @return
 */
int PlayerGameHistory::averagePlayerScore(Player* p) {
    int count = 0;
    for (unsigned long i=0; i<p->gh->games.size(); i++) {
        count += p->gh->games.at(i)->finalScore;
    }
    return (int)(count/p->gh->games.size());
}

