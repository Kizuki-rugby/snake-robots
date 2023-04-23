#include "topplayers.h"
#include "ui_topplayers.h"

topPlayers::topPlayers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::topPlayers)
{
    ui->setupUi(this);
}

topPlayers::~topPlayers()
{
    delete ui;
}

void topPlayers::writeList(PlayerGameHistory* ph) {
    for (unsigned long i=0; i<ph->playerHistory.size(); i++) {
        int score = 0;
        int count = 0;
        int gameCount = 0;
        for (unsigned long j=0; j<ph->playerHistory.at(i)->gh->games.size(); j++) {
            gameCount++;
            count += ph->playerHistory.at(i)->gh->games.at(j)->finalScore;
            score = count/gameCount;
        }
        f = new file;
        f->name = ph->playerHistory.at(i)->playerNameFirst;
        f->name += ": " + ph->playerHistory.at(i)->playerNameLast;
        f->score = score;
        scores.push_back(score);
        inter.push_back(f);
    }

    sort(scores.begin(), scores.end(), greater());
    int num1 = 0;
    QString num = QString::number(num1);
    QString player;

    if(scores.size() < 3)
    {
        for(unsigned long i = 0; i < scores.size();i++)
        {
            for (unsigned long j=0; j<inter.size(); j++) {
                if (inter.at(j)->score == scores.at(i)) {
                    num = QString::number(num1 + 1);
                    player = QString::fromStdString(inter.at(j)->name);
                }
            }
        }
    }
    else
    {
        for (unsigned long i = 0; i < 3;i++) {
            for (unsigned long j=0; j<inter.size(); j++) {
                if (inter.at(j)->score == scores.at(i)) {
                    num = QString::number(num1 + 1);
                    player = QString::fromStdString(inter.at(j)->name);
                }
            }
        }
    }
    QString numText = ui->number->text();
    QString playerText = ui->player->text();
    numText += "\n" + num;
    playerText += "\n" + player;
    ui->number->setText(numText);
    ui->player->setText(playerText);
}

void topPlayers::on_exitButton_clicked() {
    ui->number->clear();
    ui->player->clear();
    emit toMainScreen6();
}

