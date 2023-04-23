#ifndef STATISTICS_H
#define STATISTICS_H
#include "../info_bank/playergamehistory.h"
#include "../info_bank/player.h"

#include <QWidget>

namespace Ui {
class Statistics;
}

class files {
public:
    std::string name;
    int score;
};

class Statistics : public QWidget
{
    Q_OBJECT

public:
    explicit Statistics(QWidget *parent = nullptr);
    ~Statistics();
    void writeList(PlayerGameHistory* ph, Player* p);

    PlayerGameHistory* ph;
    Player* p;
    vector<files*> results;

signals:
    void toMainScreen7();

private slots:
    void on_exitButton_clicked();

private:
    Ui::Statistics *ui;
};

#endif // STATISTICS_H
