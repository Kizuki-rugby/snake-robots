#include "pagestack.h"

PageStack::PageStack()
{
    as = new AsGui();
    wg = new WormGui();
    rg = new robotgui();
    np = new NewPlayer();
    sp = new SelectPlayer();
    tg = new TopGames();
    tp = new topPlayers();  //again, sorry about the undercase!
    stat = new Statistics();

    s.addWidget(as);
    s.addWidget(wg);
    s.addWidget(rg);
    s.addWidget(np);
    s.addWidget(sp);
    s.addWidget(tg);
    s.addWidget(tp);
    s.addWidget(stat);
    s.setCurrentWidget(as);
    s.showMaximized();

    connect(as, SIGNAL(toWormGui()), this, SLOT(toWormGui()));
    connect(wg, SIGNAL(toMainScreen()), this, SLOT(toMainScreen()));
    connect(as, SIGNAL(toNewPlayer()), this, SLOT(toNewPlayer()));
    connect(np, SIGNAL(toMainScreen2()), this, SLOT(toMainScreen2()));
    connect(as, SIGNAL(torobotgui()), this, SLOT(torobotgui()));
    connect(as, SIGNAL(toSelectPlayer()), this, SLOT(toSelectPlayer()));
    connect(sp, SIGNAL(toMainScreen3()), this, SLOT(toMainScreen3()));
    connect(rg, SIGNAL(toMainScreen4()), this, SLOT(toMainScreen4()));
    connect(tg, SIGNAL(toMainScreen5()), this, SLOT(toMainScreen5()));
    connect(as, SIGNAL(toTopGames()), this, SLOT(toTopGames()));
    connect(tp, SIGNAL(toMainScreen6()), this, SLOT(toMainScreen6()));
    connect(as, SIGNAL(toTopPlayers()), this, SLOT(toTopPlayers()));
    connect(stat, SIGNAL(toMainScreen7()), this, SLOT(toMainScreen7()));
    connect(as, SIGNAL(toStatistics()), this, SLOT(toStatistics()));
}

//mainScreen -> wormGUI
void PageStack::toWormGui()
{
    s.setCurrentWidget(wg);
}

//mainScreen -> robotGUI
void PageStack::torobotgui() {
    s.setCurrentWidget(rg);
}

//wormGUI ->mainScreen
void PageStack::toMainScreen()
{
    as->player->current->finalScore = wg->w.score;
    as->player->recent->finalScore = wg->w.score;
    s.setCurrentWidget(as);
    s.removeWidget(wg);
    s.addWidget(wg = new WormGui());
    connect(as, SIGNAL(toWormGui()), this, SLOT(toWormGui()));
    connect(wg, SIGNAL(toMainScreen()), this, SLOT(toMainScreen()));

}

//mainScreen ->newPlayer
void PageStack::toNewPlayer()
{
    s.setCurrentWidget(np);
}

//mainScreen -> selectPlayer
void PageStack::toSelectPlayer() {
    sp->ph = as->ph;
    sp->makeList(sp->ph);
    s.setCurrentWidget(sp);
}

//newPlayer -> mainScreen
void PageStack::toMainScreen2()
{
    as->player = np->player;
    as->ph->add_player(as->player);
    s.setCurrentWidget(as);
    as->playerDisplay();
}

// select player -> mainScreen
void PageStack::toMainScreen3() {
    as->player = sp->player;
    as->ph = sp->ph;
    as->playerDisplay();
    s.setCurrentWidget(as);
}

//robotGUI -> mainScreen
void PageStack::toMainScreen4()
{
    as->player->current->finalScore = rg->r.currScore;
    as->player->recent->finalScore = rg->r.currScore;
    s.setCurrentWidget(as);
    s.removeWidget(rg);
    s.addWidget(rg = new robotgui());
    connect(as, SIGNAL(toWormGui()), this, SLOT(toWormGui()));
    connect(rg, SIGNAL(toMainScreen()), this, SLOT(toMainScreen()));
}

//topGames -> mainScreen
void PageStack::toMainScreen5() {

    s.setCurrentWidget(as);
}

//mainscreen -> topGames
void PageStack::toTopGames() {
    tg->ph = as->ph;
    tg->writeList(tg->ph);
    s.setCurrentWidget(tg);
}

// mainScreen -> topPlayers
void PageStack::toTopPlayers() {
    tp->ph = as->ph;
    tp->writeList(tp->ph);
    s.setCurrentWidget(tp);
}

//mainScreen -> stats
void PageStack::toStatistics() {
    stat->ph = as->ph;
    stat->p = as->player;
    stat->writeList(stat->ph, stat->p);
    s.setCurrentWidget(stat);
}

//topPlayers ->mainScreen
void PageStack::toMainScreen6() {
    s.setCurrentWidget(as);
}

//stats -> mainScreen
void PageStack::toMainScreen7() {
    s.setCurrentWidget(as);
}











