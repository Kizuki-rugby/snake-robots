#include "topplayers.h"

TopPlayers::TopPlayers(PlayerGameHistory* ph) {
    clear();
    initscr();
    cbreak();
    noecho();
    refresh();

    vector<int> scores;

    for (unsigned long i=0; i<ph->playerHistory.size(); i++) {
        int score = 0;
        int count = 0;
        int gameCount = 0;
        for (unsigned long j=0; j<ph->playerHistory.at(i)->gh->games.size(); j++) {
            gameCount++;
            count += ph->playerHistory.at(i)->gh->games.at(j)->finalScore;
            score = count/gameCount;
        }
        f->name = ph->playerHistory.at(i)->playerNameFirst;
        f->name += ": " + ph->playerHistory.at(i)->playerNameLast;
        f->score = score;
        scores.push_back(score);
        inter.push_back(f);
    }

    sort(scores.begin(), scores.end(), greater());

    if(scores.size() < 3)
    {
        for(int i = 0; i < (int)scores.size();i++)
        {
            for (int j=0; j<(int)inter.size(); j++) {
                if (inter.at(j)->score == scores.at(i)) {
                    string st = to_string(i + 1);
                    st += ": " + inter.at(j)->name + to_string(inter.at(j)->score);
                    const char* str = st.c_str();
                    mvprintw(i+1, 10, str);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 3;i++) {
            for (int j=0; j<(int)inter.size(); j++) {
                if (inter.at(j)->score == scores.at(i)) {
                    string st = to_string(i + 1);
                    st += ": " + inter.at(j)->name + to_string(inter.at(j)->score);
                    const char* str = st.c_str();
                    mvprintw(i+1, 10, str);
                }
            }
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

TopPlayers::~TopPlayers() {
    for (unsigned long i=0; i<inter.size(); i++) {
        delete inter.at(i);
        delete f;
    }
}
