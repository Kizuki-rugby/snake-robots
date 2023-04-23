#include "selectplayer.h"
#include "ui_selectplayer.h"

SelectPlayer::SelectPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectPlayer)
{
    ui->setupUi(this);
}

SelectPlayer::~SelectPlayer()
{
    delete ui;
}

void SelectPlayer::on_finishButton_clicked() {
    for (unsigned long i=0; i<list.size(); i++) {
        if (ui->numbaEdit->text().toStdString() == to_string(i+1)) {
            player = list.at(i);
        }
    }
    ui->numba->clear();
    ui->playa->clear();
    ui->numbaEdit->clear();
    emit toMainScreen3();
}

void SelectPlayer::makeList(PlayerGameHistory* ph) {
    for (unsigned long i=0; i<ph->playerHistory.size(); i++) {
        list.push_back(ph->playerHistory.at(i));
        QString first = "";
        QString last = "";
        first += QString::fromStdString(ph->playerHistory.at(i)->playerNameFirst);
        last += QString::fromStdString(ph->playerHistory.at(i)->playerNameLast);
        ui->numba->setText(ui->numba->text() + "\n" + QString::number(i+1));
        ui->playa->setText(ui->playa->text() + "\n" + first + " " + last);
    }
}
