#ifndef ROBOTS_H
#define ROBOTS_H
#include "engine.h"

//inherit from parent class

class robots: public engine
{
public:
    robots();
    ~robots();
    engine board;

    void setup();
    int checkGameEnd();
    int checkLevelUp();
    void teleport();
    void move(char input);
    void moveRobots();
    void collisionCheck();
    void waitFunction();
    void resetBoard();
    void newGame();
    void printBoard();

    int currScore = 0;
    int level = 1;
    int levelUpCount = 0;
    char hero = '@';
    char robot = '+';
    char wreck = '*';

    int robotCount = 8;             //parameterized (will be number of robots - 1)
    int robotLocations[8][2];       //change robot count here too
    int heroX, heroY;

    bool gameEnd = false;
    bool levelUp = false;

    //inputs
    char input;
    char tp = 't';
    char wait = 'p';
    char quit = 'q';

};

#endif // ROBOTS_H
