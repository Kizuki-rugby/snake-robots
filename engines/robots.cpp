#include "robots.h"

using namespace std;

/**
 * Constructor
 * @brief robots::robots
 */
robots::robots() {
    engine board;
};

robots::~robots() {

}

/**
 * This method will setup the board
 * @brief runtime
 */
void robots::setup() {
    //configure board initial state
    //spawn hero
    levelUpCount = 0;
    board.spawn(5, 5, '@');
    heroX = board.x;
    heroY = board.y;
    board.board[heroX][heroY] = '@';
    //board.board[5][5] = ' ';

    //spawn in robots
    for (int i=0; i<robotCount; i++) {
        for (int j=0;j<2;j++) {
            robotLocations[i][j] = 0;
        }
    }
    for (int i=0; i<robotCount;i++) {
        board.spawn(1, 1, '+');
        robotLocations[i][0] = board.x;
        robotLocations[i][1] = board.y;
    }
}

/**
 * These two methods will check for game events for losing or leveling up
 * @brief robots::checkGameEnd
 * @return
 */
int robots::checkGameEnd() {
    for (int i=0; i<robotCount;i++) {
        if ((robotLocations[i][0] == heroX) && (robotLocations[i][1] == heroY)) {
            return 1;
        }
    }
    return 0;
}

int robots::checkLevelUp() {
    if (levelUpCount == robotCount) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * This method will teleport the player to a new location
 * @brief teleport
 */
void robots::teleport() {
    board.board[heroX][heroY] = ' ';
    board.spawn(heroX, heroY, '@');
    heroX = board.x;
    heroY = board.y;
}

/**
 * This method will facilitate starting a new level
 * @brief resetBoard
 */
void robots::resetBoard() {
    board.board[heroX][heroY] = ' ';
    level++;
    levelUpCount = 0;
    levelUp = false;
    for (int i=1; i<board.getRow()-1; i++) {
        for (int j=1; j<board.getCol()-1; j++) {
            if ((board.board[i][j] == '*') || (board.board[i][j] == '+')) {
                board.board[i][j] = ' ';
            }
        }
    }
}

/**
 * This method will reset the board for a new game on the same object robots
 * @brief robots::newGame
 */
void robots::newGame() {
    board.board[heroX][heroY] = ' ';
    level = 1;
    for (int i=1; i<board.getRow()-1; i++) {
        for (int j=1; j<board.getCol()-1; j++) {
            if ((board.board[i][j] == '*') || (board.board[i][j] == '+')) {
                board.board[i][j] = ' ';
            }
        }
    }
}

/**
 * This method will move the player.
 * Will return 0 if move was not able to be made, 1 otherwise.
 * @brief move
 */
void robots::move(char input) {
    heroLocation h = board.movement(input, heroX, heroY);
    board.board[heroX][heroY] = ' ';
    heroX = h.x;
    heroY = h.y;
    board.board[heroX][heroY] = '@';
}

/**
 * This method will move the robots, track collisions, and count the score.
 * Uses (20, 20) (edge of board) to constitute robots that are out of the game.
 * @brief robots::moveRobots
 */
void robots::moveRobots() {
    for (int i=0; i<robotCount; i++) {

        int col = robotLocations[i][0];
        int row = robotLocations[i][1];

        if ((col < 20) && (row < 20)) {

            /*** for left / right ***/

            if (col < heroX) { // hero to the right
                if (board.board[col+1][row] == '*') {
                    board.board[col][row] = ' ';
                    col = 20;
                    row = 20;
                    levelUpCount++;
                    currScore += 10;
                } else {
                    board.board[col][row] = ' ';
                    col++;
                    board.board[col][row] = '+';
                }


            } else if (heroX < col) { // hero to the left
                if (board.board[col-1][row] == '*') {
                    board.board[col][row] = ' ';
                    col = 20;
                    row = 20;
                    levelUpCount++;
                    currScore += 10;
                } else {
                    board.board[col][row] = ' ';
                    col--;
                    board.board[col][row] = '+';
                }
            } else {
                // do nothing
            }

            /*** for above/below ***/
            if (row < heroY) {    // hero below

                if (board.board[col][row+1] == '*') {
                    board.board[col][row] = ' ';
                    col = 20;
                    row = 20;
                    levelUpCount++;
                    currScore += 10;
                } else {
                    board.board[col][row] = ' ';
                    row++;
                    board.board[col][row] = '+';
                }

            } else if (heroY < row) {  // hero above
                if (board.board[col][row-1] == '*') {
                    board.board[col][row] = ' ';
                    col = 20;
                    row = 20;
                    levelUpCount++;
                    currScore += 10;
                } else {
                    board.board[col][row] = ' ';
                    row--;
                    board.board[col][row] = '+';
                }
            } else {
                // do nothing
            }
        }

        robotLocations[i][0] = col;
        robotLocations[i][1] = row;
    }
}

/**
 * This function will check if two robots have collided, and execute the appropriate actions in such case
 * @brief robots::collisionCheck
 */
void robots::collisionCheck() {
    //robot collision checking -> improved 02.23.23 to not repeat checking pairs and reduce lines of code
    for (int i=0; i<robotCount; i++) {
        int col = robotLocations[i][0];
        int row = robotLocations[i][1];
        if ((col < 20) && (row < 20)) {
            for (int a = 0; a<robotCount; a++) {
                int cola = robotLocations[a][0];
                int rowa = robotLocations[a][1];
                if ((cola < 20) && (rowa < 20)) {
                    if (a != i) {
                        if ((col == cola) && (row == rowa)) {
                            board.board[col][row] = '*';
                            col = 20;
                            row = 20;
                            cola = 20;
                            rowa = 20;
                            currScore += 20;
                            levelUpCount += 2;
                        }
                    }
                }
                robotLocations[a][0] = cola;
                robotLocations[a][1] = rowa;
            }
        }
        robotLocations[i][0] = col;
        robotLocations[i][1] = row;
    }
}

/**
 * This method will perform the wait function.
 * @brief robots::wait
 */
void robots::waitFunction() {
    while (!gameEnd || !levelUp) {   //conditions for player caught by robots
        moveRobots();
        //printBoard();                //testing only
        if ((checkLevelUp() || checkGameEnd()) == 1) {
            break;
        }
    }
}

/**
 * Testing via print
 * @brief robots::printBoard
 */
void robots::printBoard() {
//    if (gameEnd) {
//        cout << "gameEnd = true" << endl;
//    } else {
//        cout << "gameEnd = false" << endl;
//    }
    cout << "Hero Positions:" << endl;
    cout << heroX << endl;
    cout << heroY << endl;
    cout << "Robot Locations" << endl;
    for (int i = 0; i < robotCount; i++) {
        cout << robotLocations[i][0];
        cout << ':';
        cout << robotLocations[i][1] << endl;
    }
    for (int i = 0; i < board.getCol(); i++)
    {
        for (int j = 0; j < board.getRow(); j++)
        {
            cout << board.board[j][i];
        }
        cout << "\n";
    }

}



