#ifndef SELECTPLAYER_H
#define SELECTPLAYER_H
#include "../info_bank/player.h"
#include "../info_bank/playergamehistory.h"
#include <vector>

#include <QWidget>

namespace Ui {
class SelectPlayer;
}

class SelectPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit SelectPlayer(QWidget *parent = nullptr);   //might need to be changed back to explicits
    ~SelectPlayer();
    Player* player;
    void makeList(PlayerGameHistory* ph);
    vector<Player*>list;
    PlayerGameHistory* ph;

signals:
    void toMainScreen3();

private slots:
    void on_finishButton_clicked();

private:
    Ui::SelectPlayer *ui;
};

#endif // SELECTPLAYER_H
