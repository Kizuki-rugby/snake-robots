#ifndef TOPPLAYERS_H
#define TOPPLAYERS_H
#include "../info_bank/playergamehistory.h"
#include "../info_bank/player.h"

#include <QWidget>

namespace Ui {
class topPlayers;
}

class file {
public:
    string name;
    int score;
};

class topPlayers : public QWidget
{
    Q_OBJECT

public:
    explicit topPlayers(QWidget *parent = nullptr);
    ~topPlayers();
    void writeList(PlayerGameHistory* ph);

    vector<int> scores;
    vector<file*> inter;
    PlayerGameHistory* ph;
    file* f;

signals:
    void toMainScreen6();

private slots:
    void on_exitButton_clicked();

private:
    Ui::topPlayers *ui;
};

#endif // TOPPLAYERS_H
