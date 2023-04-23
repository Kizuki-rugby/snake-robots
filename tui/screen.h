#ifndef SCREEN_H
#define SCREEN_H
#include <curses.h>
#include "../engines/worm.h"
#include "../engines/robots.h"


class Screen
{
public:
    Screen();
    ~Screen();
    worm w;
    robots r;
    char getDirection();
    char direction;
    void draw_screen(engine*);
    void finished();
};

#endif // SCREEN_H
