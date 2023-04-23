#ifndef ASGUI_H
#define ASGUI_H

#include <QMainWindow>
#include "robotgui.h"
#include "wormgui.h"
#include "newplayer.h"
#include "selectplayer.h"
#include "../info_bank/playergamehistory.h"
#include "../info_bank/game.h"
#include "../info_bank/gamehistory.h"
#include "topgames.h"
#include "topplayers.h"
#include "statistics.h"


QT_BEGIN_NAMESPACE
namespace Ui { class AsGui; }
QT_END_NAMESPACE

class AsGui : public QMainWindow
{
    Q_OBJECT

public:
    AsGui(QWidget *parent = nullptr);
    ~AsGui();
    Player* player;
    Game* game;
    PlayerGameHistory* ph;
    NewPlayer* np;
    WormGui* wg;
    robotgui* rg;   //sorry for the lowercase kizuki!

    void playerDisplay();

signals:
    void toWormGui();
    void torobotgui();
    void toNewPlayer();
    void toSelectPlayer();
    void toStatistics();
    void toTopGames();
    void toTopPlayers();

private slots:
    void on_wormButton_clicked();

    void on_robotButton_clicked();

    void on_actionExit_triggered();

    void on_actionNew_Player_triggered();

    void on_actionSelect_Existing_Player_triggered();

    void on_actionTop_3_Games_triggered();

    void on_actionTop_3_Players_triggered();

    void on_actionCalculated_Statistics_triggered();

private:
    Ui::AsGui *ui;
};
#endif // ASGUI_H
