#ifndef NEWPLAYER_H
#define NEWPLAYER_H
#include "../info_bank/player.h"
#include "../info_bank/gamehistory.h"

#include <QWidget>

namespace Ui {
class NewPlayer;
}

class NewPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit NewPlayer(QWidget *parent = nullptr);
    ~NewPlayer();
    Player* player;
    GameHistory* gh;
signals:
    void toMainScreen2();

private slots:
    void on_enterButon_clicked();

private:
    Ui::NewPlayer *ui;
};

#endif // NEWPLAYER_H
