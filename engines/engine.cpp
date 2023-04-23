#include "engine.h"

using namespace  std;

engine::engine()
{
    // assigning border
    x = 5;
    y = 5;
    // initializing

    board = new char*[row];
    for(int i = 0; i < row; i++)
    {
        board[i] = new char[col];
    }

    //assigning
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col;j++)
        {
            board[i][j] = ' ';
        }
    }

    for(int i = 0; i < row;i++)
    {
        board[i][0] = invalid;//left vertical wall
        board[i][col - 1] = invalid; // the right vertical wall
    }

    for(int i = 0; i < col;i++)
    {
        board[0][i] = invalid;
        board[row - 1][i] = invalid;
    }

    //board[5][5] = '@';
}

/**
 * destructor to destroy the gameBoard.
 *
 * @brief engine::~engine
 */
engine::~engine() {
//    for (int i=0; i<row; i++) {
//        for (int j=0; j<row; j++) {
//            delete(&board[i][j]);
//        }
//    }
}

/**
 * This is a randomized spawn function. with given coordinates, the function assign random x,y coordinates that can be safely teleported to within a
 * given size of gameboard.
 * @brief gameboard::spawn
 */
void engine::spawn(int currX, int currY, char character) {
    random_device rd;
    uniform_int_distribution<int> dist(0,row - 1);
    uniform_int_distribution<int> dist_(0,col - 1);
    int newX = dist(rd);
    int newY = dist_(rd);

    //The conditions that allocates new X, Y positions:
    // 1) when randomly generated value is where the wall/invalid object.
    // 2) when randomly generated values are the same exact location as where you started.
    while((currX == newX && currY == newY) || board[newX][newY] == invalid || board[newX][newY] == invalid2 || board[newX][newY] == object)
    {
        newX = dist(rd);
        newY = dist(rd);
    }

    board[newX][newY] = character;
    x = newX;
    y = newY; 
}

/**
 * Will check for what type of character the destination of movement will be.
 * Used to determine game-specific events for both engines respectively.
 * char b: destination character
 * @brief pieces::checker
 * @return
 */
char engine::checker(char b) {
    if ((b == invalid) || (b == invalid2)) {
        return '0';
    } else {
        return b;
    }
}

/**
 * Will execute the movement of player characters in each game engine, given that the destination is a movable location.
 * 02.18.23 - edited to improve functionality.
 * char a: movement character
 * @brief pieces::movement
 */
heroLocation engine::movement(char a, int x, int y) {
    if ((a == w) && (checker(board[x][y-1]) != '0')) {
        y = y - 1;
    } else if ((a == sw) && (checker(board[x+1][y-1]) != '0')) {
        x = x + 1;
        y = y - 1;
    } else if ((a == s) && (checker(board[x+1][y]) != '0')) {
        x = x + 1;
    } else if ((a == se) && (checker(board[x+1][y+1]) != '0')) {
        x = x + 1;
        y = y + 1;
    } else if ((a == e) && (checker(board[x][y+1]) != '0')) {
        y = y + 1;
    } else if ((a == ne) && (checker(board[x-1][y+1]) != '0')) {
        x = x - 1;
        y = y + 1;
    } else if ((a == n) && (checker(board[x-1][y]) != '0')) {
        x = x - 1;
    } else if ((a == nw) && (checker(board[x-1][y-1]) != '0')) {
        x = x - 1;
        y = y - 1;
    }
    loc.x = x;
    loc.y = y;
    return loc;
}

//************************************************************************//
void engine::movement2(int currX, int currY, char direction)
{
    if(direction == w)
    {
        y = currY - 1;
        x = currX;
    }
    else if(direction == s)
    {
        x = currX + 1;
        y = currY;
    }
    else if(direction == n)
    {
        x = currX - 1;
        y = currY;
    }
    else if(direction == e)
    {
        y = currY + 1;
        x = currX;
    }

}

int engine::getRow()
{
    return row;
}
int engine::getCol()
{
    return col;
}


