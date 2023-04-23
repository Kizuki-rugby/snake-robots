#include "robotgui.h"
#include "ui_robotgui.h"

robotgui::robotgui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::robotgui)
{
    ui->setupUi(this);
    r.setup();
    runit();
}

robotgui::~robotgui()
{
    delete ui;
}

void robotgui::runit() {
    draw_board();
    scoring();
    check();
}

void robotgui::check() {
    if (r.checkLevelUp() == 1) {
        draw_board();
        r.resetBoard();
        r.setup();
        runit();
    }
    if (r.checkGameEnd() == 1) {
        gameEnd();
    }
}

void robotgui::on_northButton_clicked() {
    r.move('n');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_southButton_clicked() {
    r.move('s');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_eastButton_clicked() {
    r.move('e');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_westButton_clicked() {
    r.move('w');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_northEastButton_clicked() {
    r.move('i');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_northWestButton_clicked() {
    r.move('u');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_southEastButton_clicked() {
    r.move('k');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_southWestButton_clicked() {
    r.move('j');
    r.moveRobots();
    r.collisionCheck();
    runit();
}

void robotgui::on_teleportButton_clicked() {
    r.teleport();
    draw_board();
    runit();
}

void robotgui::on_waitButton_clicked() {
    r.waitFunction();
    check();
}

void robotgui::on_playAgainButton_clicked() {
    if (r.checkGameEnd() == 1) {
        r.newGame();
        r.currScore = 0;
        r.setup();
        runit();
    }
}

void robotgui::on_quitButton_clicked() {
    emit toMainScreen4();
}

void robotgui::draw_board() {
    QString temp_board = "";

    for(int row = 0; row < r.board.getRow(); row++) {
        for(int col = 0; col < r.board.getCol(); col++) {
            temp_board += r.board.board[row][col];
        }
        temp_board += '\n';
    }

    ui->board_draw->clear();
    ui->board_draw->setText(temp_board);
}

void robotgui::gameEnd() {
    ui->board_draw->clear();
    QString level = "";
    level += "Press Play Again for another try, or quit to return to the menu.";
    ui->score_display->clear();
    ui->level_display->clear();
    ui->level_display->setText(level);
}

void robotgui::scoring() {
    QString level = "Level: ";
    QString score = "Score: ";
    level += QString::number(r.level);
    score += QString::number(r.currScore);
    ui->score_display->clear();
    ui->level_display->clear();
    ui->score_display->setText(score);
    ui->level_display->setText(level);
}



























