#include "topgames.h"
#include "ui_topgames.h"

TopGames::TopGames(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TopGames)
{
    ui->setupUi(this);
}

TopGames::~TopGames()
{
    delete ui;
}

void TopGames::on_exitButton_clicked() {
    ui->number->clear();
    ui->score->clear();
    emit toMainScreen5();
}

void TopGames::writeList(PlayerGameHistory *ph) {
    for (unsigned long i=0; i<ph->playerHistory.size(); i++) {
        for (unsigned long j=0; j<ph->playerHistory.at(i)->gh->games.size(); j++) {
            inter.push_back(ph->playerHistory.at(i)->gh->games.at(j)->finalScore);
        }
    }
    int num1 = 0;
    QString num = QString::number(num1);
    QString score;
    sort(inter.begin(), inter.end(), greater());
    if (inter.size() < 3) {
            for(int i = 0; i < (int)inter.size();i++) {
                num = QString::number(num1 + 1);
                score = QString::number(inter.at(i));
            }
        }
        else {
            for (int i = 0; i < 3;i++) {
                num = QString::number(num1 + 1);
                score = QString::number(inter.at(i));
            }
        }
    QString numText = ui->number->text();
    QString scoreText = ui->number->text();
    numText += "\n" + num;
    scoreText += "\n" + score;
    ui->number->setText(numText);
    ui->score->setText(scoreText);
}

