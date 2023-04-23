#include "topscores.h"

TopScores::TopScores(PlayerGameHistory* ph) {
    clear();
    initscr();
    cbreak();
    noecho();
    refresh();

    vector<int> inter;

    for (unsigned long i=0; i<ph->playerHistory.size(); i++) {
        for (unsigned long j=0; j<ph->playerHistory.at(i)->gh->games.size(); j++) {
            inter.push_back(ph->playerHistory.at(i)->gh->games.at(j)->finalScore);
        }
    }
    sort(inter.begin(), inter.end(), greater());
    if (inter.size() < 3) {
            for(int i = 0; i < (int)inter.size();i++) {
                string st = to_string(i + 1);
                st += ": " + to_string(inter.at(i));
                const char* str = st.c_str();
                mvprintw(i+1, 10, str);
            }
        }
        else {
            for (int i = 0; i < 3;i++) {
                string st = to_string(i + 1);
                st += ": " + to_string(inter.at(i));
                const char* str = st.c_str();
                mvprintw(i+1, 10, str);
            }
        }
    int ch = getch();
    mvprintw(6, 10, "Press q to exit.");
    refresh();
    if (ch == 'q') {
        clear();
        endwin();
    }
}

TopScores::~TopScores() {

}
