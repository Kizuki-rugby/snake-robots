#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <stdlib.h>
#include <random>
#include <cstdlib>

class heroLocation {
public:
    int x;
    int y;
};
class engine
{
public:
    engine();
    ~engine();
    char checker(char b);
    heroLocation movement(char a, int heroX, int heroY);
    void movement2(int, int, char);
    int getRow();
    int getCol();

    heroLocation loc;

    //movement variables
    char n = 'n';
    char ne = 'i';
    char e = 'e';
    char se = 'k';
    char s = 's';
    char sw = 'j';
    char w = 'w';
    char nw = 'u';

    //current position variables
    int x,y;    //use as i and j for indexes in children classes

    void spawn(int, int, char);

    char** board;

    // indicates that the specified array is invalid for user to spawn.
    char invalid = '*';
    char invalid2 = '+';    //do not spawn me on robots please!
    char object = 'o';

protected:          //made larger for testing
    int row = 20;
    int col = 20;

};

#endif // ENGINE_H
