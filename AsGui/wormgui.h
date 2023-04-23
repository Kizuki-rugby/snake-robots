#ifndef WORMGUI_H
#define WORMGUI_H

#include <QMainWindow>
#include "../engines/worm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WormGui; }
QT_END_NAMESPACE

class WormGui : public QMainWindow
{
    Q_OBJECT

public:
    WormGui(QWidget *parent = nullptr);
    ~WormGui();
    worm w;
    void run();
    void draw_board();
    void print_score();
    void game_over();
signals:
    void toMainScreen();

private slots:
    void on_eastButton_clicked();
    void on_westButton_clicked();
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_quitButton_clicked();
    void on_playAgainButton_clicked();

private:
    Ui::WormGui *ui;
};
#endif // WORMGUI_H
