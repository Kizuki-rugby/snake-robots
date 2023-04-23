#include "worm.h"
using namespace std;

/**
 * constructor. initialize the engine object, amd respwans the fruit.
 * and the worm is being created for the first time, there is only one 'o' after the head.
 * @brief worm::worm
 */
worm::worm()
{
    engine e;
    x = e.x;
    y = e.y;
    respawn(1,1,rand_num());
    grow(5,5);
    grow(4,5);
    start();
}
/**
 * destructor. free the object and variables at the end of the program.
 * @brief worm::~worm
 */
worm::~worm()
{
    e.~engine();
}
/**
 * overwrite to the gameboard about needed information based on the
 * variables stored into w object to prepare for the game to begin.
 * @brief worm::start
 */
void worm::start()
{

    for(int i = 0; i < bodyLength; i++)
    {
        e.board[body.at(i).x][body.at(i).y] = 'o';
    }
    e.board[x][y] = '@';

}
/**
 * this function should grow the bodyLength
 * This function should be only called when the head eats fruits.
 * it creates a Body object that contains x, y and that gets stored into
 * vector body.
 *
 * @brief worm::grow
 * @param x
 * @param y
 */
void worm::grow(int x, int y)
{
    Body b;
    b.x = x;
    b.y = y;
    body.push_back(b);
    bodyLength++;
}

/**
 * Code Runner function.
 * @brief worm
 */
void worm::run()
{

}

/**
 * randomly generate a number between 1-9 and returns to it as a character.
 * @brief worm::rand_num
 * @return character that is 1-9 that represents the fruit.
 */
char worm::rand_num()
{
    random_device rd;
    uniform_int_distribution<int> dist(1, 9);
    int num = dist(rd);
    char c = num + '0';
    fruitVal = num;
    return c;
}

/**
 * This function will print out the score of the player when s/he is game over.
 * and alternate the boolean varibale gameOver to true;
 *
 * @brief worm::game_over
 */
void worm::game_over()
{
    print_score();
    cout << "Sorry It's game over ... " << endl;
}


/**
 * This function controls the head of worm to move specified direction.
 * The possible directions are:
 * 1) 'n' -> goes to north(up)
 * 2) 'e' -> goes to east(right)
 * 3) 's' -> goes to south(down)
 * 4) 'w' -> goes to west(left)
 * this also checks the conditions to see if the head has eatens a fruits
 * or it has hit the wall.
 * It will also update the vector of body's coordinates according to the direction of choosing.
 * @brief worm::move
 * @param currX
 * @param currY
 * @param direction
 */
void worm::move(int currX, int currY, char direction)
{
    if(!gameOver)
    {
        if (direction == 'n' || direction == 'e' || direction == 's' || direction == 'w')
        {
            this->e.board[currX][currY] = ' ';
            e.movement2(currX, currY, direction);
            x = e.x;
            y = e.y;
            // checks the condition if the head moved towards body || wall
            if(e.board[x][y] == e.invalid || e.board[x][y] == 'o')
            {
                gameOver = true;
            }
            // checks if the head has reached for fruit
            else if(e.board[x][y] != ' ' && e.board[x][y] != e.invalid)
            {
                score_up();
                for(int i = 0; i < fruitVal;i++)
                {
                    grow(x,y);// increase the bodyLength.
                }
                respawn(x, y, rand_num());
            }
            prevX = x;
            prevY = y;
            for(int i = 0; i < (int)body.size(); i++)
            {
                tempX = body.at(i).x;
                tempY = body.at(i).y;
                e.board[body.at(i).x][body.at(i).y] = ' ';
                body.at(i).x = prevX;
                body.at(i).y = prevY;
                prevX = tempX;
                prevY = tempY;
            }
            for(int i = 1;i < (int)body.size();i++)
            {
                e.board[body.at(i).x][body.at(i).y] = 'o';
            }
            e.board[body.at(0).x][body.at(0).y] = '@';
        }
    }
}
/**
 * This function takes the current fruitVal and sums to the score variable
 * to keep track of the total score.
 * @brief worm::score_up
 */
void worm::score_up()
{
    score += fruitVal;
}

/**
 * prints out the total sore to the command line.
 * @brief worm::print_score
 */
void worm::print_score()
{
    cout << "The current score is : " << score << endl;
}

/**
 * it respawns the fruits to random coordinate that is not wall, or  part of worm(technically
 * the previous location of fruit but tat is where the head is)
 * @brief worm::respawn
 * @param x
 * @param y
 * @param num
 */
void worm::respawn(int x, int y, char num)
{
    e.spawn(x, y, num);
    fruitX = e.x;
    fruitY = e.y;
}

/**
 * prints out the board to the command line.
 * @brief worm::print_board
 */
void worm::print_board()
{
    for (int i = 0; i < e.getRow(); i++)
    {
        for (int j = 0; j < e.getCol(); j++)
        {
            cout << e.board[j][i];
        }
        cout << "\n";
    }
}
