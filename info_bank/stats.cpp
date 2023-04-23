#include "stats.h"

Stats::Stats(PlayerGameHistory* ph, Player* p) {
    clear();
    initscr();
    cbreak();
    noecho();
    refresh();

    //totalGames:
    files* tg = new files;
    tg->name = "Total games played: ";
    tg->score = ph->totalGames();
    results.push_back(tg);

    //players:
    files* pl = new files;
    pl->name = "Number of players who have played a game: ";
    pl->score = ph->players();
    results.push_back(pl);

    //averageGames:
    files* ag = new files;
    ag->name = "Average games played per player: ";
    ag->score = ph->averageGames();
    results.push_back(ag);

    //topScore:
    files* ts = new files;
    ts->name = "Top game score: ";
    ts->score = ph->topScore();
    results.push_back(ts);

    //averageScore:
    files* asc = new files;
    asc->name = "Average game score of all games: ";
    asc->score = ph->averageScore();
    results.push_back(asc);

    //averagePlayerScore:
    files* aps = new files;
    aps->name = "Average score of selected player: ";
    aps->score = ph->averagePlayerScore(p);
    results.push_back(aps);

    for (unsigned long i=0; i<results.size(); i++) {
        string label = to_string(i+1);
        label += ". " + results.at(i)->name + to_string(results.at(i)->score);
        const char* label1 = label.c_str();
        mvprintw(i+1, 10, label1);
    }

    refresh();
    int ch = getch();
    mvprintw(6, 10, "Press q to exit.");
    if (ch == 'q') {
        clear();
        endwin();
    }
}

Stats::~Stats() {
    for (unsigned long i=0; i<results.size(); i++) {
        delete results.at(i);
    }
}
