#ifndef STATS_H
#define STATS_H
#include "playergamehistory.h"
#include <curses.h>
#include <iostream>
#include <vector>
#include <string>

class files {
public:
    string name;
    int score;
};
class Stats
{
public:
    Stats(PlayerGameHistory* ph, Player* p);
    ~Stats();
    vector<files*> results;
};

#endif // STATS_H
