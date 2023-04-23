#ifndef WORMTUI_H
#define WORMTUI_H
#include "screen.h"


class WormTui:public Screen
{
public:
    WormTui();
    ~WormTui();
    Screen s;
    worm w;
    void run();
    void done();
    void print_score();
};

#endif // WORMTUI_H
