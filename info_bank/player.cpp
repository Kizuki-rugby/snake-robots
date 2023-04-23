#include "player.h"

using namespace std;

Player::Player(string playerNameFirst, string playerNameLast, string playerAddress) {
    this->playerNameFirst = playerNameFirst;
    this->playerNameLast = playerNameLast;
    this->playerAddress = playerAddress;
    gh = new GameHistory();
}







