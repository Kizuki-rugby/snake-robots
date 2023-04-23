#include "selectplayer.h"

selectplayer::selectplayer(PlayerGameHistory* ph) {
    current = NULL;
    clear();
    initscr();
    cbreak();
    noecho();
    refresh();

    unsigned long i = 0;
    while (i < ph->playerHistory.size()) {      //stay within size limits of screen!
        string name = to_string(i+1) + ": ";
        name += ph->playerHistory.at(i)->playerNameFirst;
        name += ' ';
        name += ph->playerHistory.at(i)->playerNameLast;
        const char* name1 = name.c_str();
        mvprintw(i+1, 10, name1);
        i++;
    }
    refresh();
    int ch = getch();
    if (ch == 'q') {
        endwin();
    } else {
        for (i = 1; i<ph->playerHistory.size()+1; i++) {
            if (ch - 48 == (int)i) {
                current = ph->playerHistory.at(i-1);
                clear();
                endwin();
            }
        }
    }
    clear();
    endwin();
}

selectplayer::~selectplayer() {
   // delete current;
}

