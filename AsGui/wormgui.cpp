#include "wormgui.h"
#include "ui_wormgui.h"

WormGui::WormGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WormGui)
{
    ui->setupUi(this);
    worm w;
    this->w = w;
    run();
}

WormGui::~WormGui()
{
    delete ui;
}

void WormGui::run()
{
    draw_board();
    print_score();
}


void WormGui::on_northButton_clicked()
{
    w.move(w.x,w.y,'n');
    run();
    if(w.gameOver) game_over();
}

void WormGui::on_eastButton_clicked()
{
    w.move(w.x,w.y,'e');
    run();
    if(w.gameOver) game_over();
}

void WormGui::on_southButton_clicked()
{
    w.move(w.x,w.y,'s');
    run();
    if(w.gameOver) game_over();
}

void WormGui::on_westButton_clicked()
{
    w.move(w.x,w.y,'w');
    run();
    if(w.gameOver) game_over();
}

void WormGui::on_quitButton_clicked()
{
    emit toMainScreen();
}

void WormGui::draw_board()
{

    QString temp_board = "";

    for(int row = 0; row < w.e.getRow(); row++) {
        for(int col = 0; col < w.e.getCol(); col++) {
            temp_board += w.e.board[row][col];
        }
        temp_board += '\n';
    }

    ui->board_display->clear();
    ui->board_display->setText(temp_board);
}

void WormGui::print_score()
{
    QString temp_score = "Score: ";
    temp_score += QString::number(w.score);
    ui->score_display->clear();
    ui->score_display->setText(temp_score);

}

void WormGui::game_over()
{
    QString str = "Final Score: ";
    str += QString::number(w.score);
    QString temp_gameover = "\nWould you like to play again?";
    str += temp_gameover;
    ui->board_display->clear();
    ui->score_display->clear();
    ui->board_display->setText(str);
}

void WormGui::on_playAgainButton_clicked()
{
    if(w.gameOver)
    {
        worm w;
        this->w = w;
        run();
    }

}

