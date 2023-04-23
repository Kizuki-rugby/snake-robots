#ifndef robottui_H
#define robottui_H
#include "screen.h"

class robottui: public Screen
{
public:
    robottui();
    ~robottui();
    void runit();
    void gameEnd();
    void scoring();
    robots r;
};

#endif // robottui_H
