#include "screen.h"


Screen::Screen()
{
    // initializing the screen.
    initscr();
    // hide the cursor from a view
    curs_set(0);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

Screen::~Screen() {
     //endwin();
}

void Screen::draw_screen(engine *e) // may have to pass as a pointer(FYI)
{
    clear();
    for(int i = 0; i < e->getRow();i++)
    {
        for(int j = 0; j < e->getCol();j++)
        {
            mvprintw(i,j,&e->board[i][j]);
        }
    }
}

void Screen::finished()
{
    clear();
    mvprintw(1,1,"Game Over :((");
}

char Screen::getDirection() {
    int ch = getch();
    switch(ch)
    {
    case KEY_DOWN:
        direction = 's';
        break;
    case KEY_UP:
        direction = 'n';
        break;
    case KEY_LEFT:
        direction = 'w';
        break;
    case KEY_RIGHT:
        direction = 'e';
        break;
    case 'u':
        direction = 'u';
        break;
    case 'i':
        direction = 'i';
        break;
    case 'k':
        direction = 'k';
        break;
    case 'j':
        direction = 'j';
        break;
    case 't':   //teleport
        direction = 't';
        break;
    case 'p':   //wait
        direction = 'p';
        break;
    case 'q':   //quit
        direction = '\0';
        break;
    }
    return direction;
}


