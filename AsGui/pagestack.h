#ifndef PAGESTACK_H
#define PAGESTACK_H
#include "asgui.h"
#include <QObject>
#include <QStackedWidget>


class PageStack : public QObject
{
    Q_OBJECT

public:
    PageStack();
    AsGui* as;
    WormGui* wg;
    robotgui* rg;
    NewPlayer* np;
    SelectPlayer* sp;
    TopGames* tg;
    topPlayers* tp;
    Statistics* stat;

public slots:
    void toWormGui();
    void torobotgui();
    void toMainScreen();
    void toNewPlayer();
    void toMainScreen2();
    void toMainScreen3();
    void toSelectPlayer();
    void toMainScreen4();
    void toTopGames();
    void toTopPlayers();
    void toStatistics();
    void toMainScreen5();   //mainScreen 5, 6 & 7 are not fully needed,
                            //but I thought could help organize whats going on
    void toMainScreen6();
    void toMainScreen7();

private:
    QStackedWidget s;
};

#endif // PAGESTACK_H
