#ifndef TOPPLAYERS_H
#define TOPPLAYERS_H
#include "playergamehistory.h"
#include <curses.h>
#include <iostream>
#include <vector>
#include <string>

class file {
public:
    string name;
    int score;
};

class TopPlayers
{
public:
    TopPlayers(PlayerGameHistory* ph);
    ~TopPlayers();
    vector<file*> inter;
    file* f;
};

#endif // TOPPLAYERS_H
