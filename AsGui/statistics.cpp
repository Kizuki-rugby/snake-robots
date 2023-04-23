#include "statistics.h"
#include "ui_statistics.h"

Statistics::Statistics(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistics)
{
    ui->setupUi(this);
}

Statistics::~Statistics()
{
    delete ui;
}

void Statistics::on_exitButton_clicked() {
    emit toMainScreen7();
}

void Statistics::writeList(PlayerGameHistory* ph, Player* p) {

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

    QString gamesPlayed = QString::number(1);
    gamesPlayed += ". " + QString::fromStdString(results.at(0)->name) + QString::number(results.at(0)->score);
    ui->gamesPlayed->setText(gamesPlayed);

    QString playersPlayingGames = QString::number(2);
    playersPlayingGames += ". " + QString::fromStdString(results.at(1)->name) + QString::number(results.at(1)->score);
    ui->playersPlayingGames->setText(playersPlayingGames);

    QString averageGamesPerPlayer = QString::number(3);
    averageGamesPerPlayer += ". " + QString::fromStdString(results.at(2)->name) + QString::number(results.at(2)->score);
    ui->averageGamesPerPlayer->setText(averageGamesPerPlayer);

    QString topScore = QString::number(4);
    topScore += ". " + QString::fromStdString(results.at(3)->name) + QString::number(results.at(3)->score);
    ui->topScore->setText(topScore);

    QString averageGameAll = QString::number(5);
    averageGameAll += ". " + QString::fromStdString(results.at(4)->name) + QString::number(results.at(4)->score);
    ui->averageGameAll->setText(averageGameAll);

    QString averageGamePlayer = QString::number(6);
    averageGamePlayer += ". " + QString::fromStdString(results.at(5)->name) + QString::number(results.at(5)->score);
    ui->averageGamePlayer->setText(averageGamePlayer);
}
