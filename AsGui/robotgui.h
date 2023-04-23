#ifndef ROBOTGUI_H
#define ROBOTGUI_H

#include <QMainWindow>
#include "../engines/robots.h"
//#include "QtWidgets/qwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class robotgui; }
QT_END_NAMESPACE

class robotgui : public QMainWindow
{
    Q_OBJECT

public:
    robotgui(QWidget *parent = nullptr);
    ~robotgui();
    void runit();
    void check();
    void draw_board();
    void gameEnd();
    void scoring();

    robots r;

signals:
    void toMainScreen();
    void toMainScreen4();

private slots:

    void on_eastButton_clicked();
    void on_westButton_clicked();
    void on_northButton_clicked();
    void on_southButton_clicked();
    void on_northEastButton_clicked();
    void on_southEastButton_clicked() ;
    void on_southWestButton_clicked();
    void on_northWestButton_clicked();

    void on_waitButton_clicked();
    void on_teleportButton_clicked();

    void on_quitButton_clicked();
    void on_playAgainButton_clicked();

private:
    Ui::robotgui *ui;
};
#endif // ROBOTGUI_H
