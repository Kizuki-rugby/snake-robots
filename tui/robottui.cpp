#include "robottui.h"

robottui::robottui() {

}
robottui::~robottui() {

}

/**
 * This method will run the text-user-interface for the robots game, utilizing the engine.
 * @brief RobotTui::runit
 */
void robottui::runit() {
    r.setup();                          //display score
    while(true) {
        draw_screen(&r.board);
        scoring();
        refresh();
        getDirection();

        if (direction == 't') {
            r.teleport();
        } else if (direction == 'p') {
            r.waitFunction();
            draw_screen(&r.board);
            refresh();
        } else if (direction == '\0') {
            break;
        } else {
            r.move(direction);
            r.moveRobots();
            r.collisionCheck();
        }

        if (r.checkLevelUp() == 1) {
            draw_screen(&r.board);
            refresh();                  //display level
            r.resetBoard();
            r.setup();
        }

        if (r.checkGameEnd() == 1) {
            gameEnd();
            break;
        }
    }
}

/**
 * This method will run the game ending events; asking the user if they would
 * like to play againn or quit.
 * @brief RobotTui::gameEnd
 */
void robottui::gameEnd() {
    draw_screen(&r.board);
    mvprintw(5, r.board.getCol() + 5, "Game Over!");
    mvprintw(6, r.board.getCol() + 5, "Would you like to play again?");
    mvprintw(7, r.board.getCol() + 5, "Press 'q' to quit, 'p' to play again.");
    refresh();
    getDirection();           //ask user if they want to play again
    if (direction == '\0') {
        //game quits at this point
    } else {
        r.~robots();
        r.newGame();
        runit();
    }
}

/**
 * This method will display the score.
 * @brief RobotTui::scoring
 */
void robottui::scoring() {

    string level = "Current Level: ";
    string score = "Current Score: ";

    level += to_string(r.level);
    const char* level1 = level.c_str();
    mvprintw(13, r.board.getCol() + 5, level1);

    score += to_string(r.currScore);
    const char* score1 = score.c_str();
    mvprintw(15, r.board.getCol() + 5, score1);
}


