#include <iostream>
#include <string>
#include <curses.h>
#include "screen.h"
#include "robottui.h"
using namespace std;
void draw_screen(Screen *s, worm *w);

int main()
{
    robottui rt;
    rt.runit();
}
