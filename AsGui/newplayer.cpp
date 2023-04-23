#include "newplayer.h"
#include "ui_newplayer.h"
#include <QLineEdit>

NewPlayer::NewPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewPlayer)
{
    ui->setupUi(this);
}

NewPlayer::~NewPlayer()
{
    delete ui;
}

void NewPlayer::on_enterButon_clicked()
{
    string firstName = ui->firstName_input->text().toStdString();
    string lastName = ui->lastName_input->text().toStdString();
    string address = ui->address_input->text().toStdString();
    player = new Player(firstName, lastName, address);
    gh = new GameHistory();
    ui->firstName_input->clear();
    ui->lastName_input->clear();
    ui->address_input->clear();
    emit toMainScreen2();
}

