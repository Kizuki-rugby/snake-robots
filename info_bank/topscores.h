#ifndef TOPSCORES_H
#define TOPSCORES_H
#include "playergamehistory.h"
#include <curses.h>
#include <iostream>
#include <vector>
#include <string>

class TopScores
{
public:
    TopScores(PlayerGameHistory *ph);
    ~TopScores();
};

#endif // TOPSCORES_H
