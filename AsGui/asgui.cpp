#include "asgui.h"
#include "ui_asgui.h"

AsGui::AsGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AsGui)
{
    ui->setupUi(this);
//    player = new Player(" ", " ", " ");
    player = NULL;
    ph = new PlayerGameHistory();
}

AsGui::~AsGui()
{
    delete ui;
}

void AsGui::on_wormButton_clicked()
{
    if(player != NULL)
    {
        emit toWormGui();
        wg = new WormGui();
        game = new Game(player, "worm");
        game->finalScore = wg->w.score;
        player->gh->add_game(game);
        player->current = game;
        player->recent = game;
    }
}


void AsGui::on_robotButton_clicked()
{
    if (player != NULL) {
        rg = new robotgui();
        game = new Game(player, "robots");
        game->finalScore = rg->r.currScore;
        player->gh->add_game(game);
        player->current = game;
        player->recent = game;
        emit torobotgui();
    }
}


void AsGui::on_actionExit_triggered()
{
    close();
}


void AsGui::on_actionNew_Player_triggered()
{
    emit toNewPlayer();
}

void AsGui::playerDisplay() {
    QString currPlayer = "Current Player Selected: ";
    if (player != NULL) {
        currPlayer += QString::fromStdString(player->playerNameFirst);

    } else {
        currPlayer += "No loaded player... select an existing player or create a new one!";
    }
    ui->display_Player->clear();
    ui->display_Player->setText(currPlayer);
}

void AsGui::on_actionSelect_Existing_Player_triggered() {
    emit toSelectPlayer();
}

void AsGui::on_actionTop_3_Games_triggered() {
    emit toTopGames();
}

void AsGui::on_actionTop_3_Players_triggered() {
    emit toTopPlayers();
}

void AsGui::on_actionCalculated_Statistics_triggered() {
    emit toStatistics();
}
