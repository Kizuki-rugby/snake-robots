#ifndef TOPGAMES_H
#define TOPGAMES_H
#include "../info_bank/playergamehistory.h"
#include "../info_bank/game.h"
#include "../info_bank/gamehistory.h"

#include <QWidget>

namespace Ui {
class TopGames;
}

class TopGames : public QWidget
{
    Q_OBJECT

public:
    explicit TopGames(QWidget *parent = nullptr);
    ~TopGames();
    void writeList(PlayerGameHistory* ph);

    vector<int> inter;
    PlayerGameHistory* ph;

signals:
    void toMainScreen5();

private slots:
    void on_exitButton_clicked();

private:
    Ui::TopGames *ui;
};

#endif // TOPGAMES_H
