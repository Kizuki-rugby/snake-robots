#ifndef WORM_H
#include "engine.h"
#define WORM_H
using namespace std;

/**
 * contains the coordinates of body each body part.
 * @brief The Body class
 */

class Body{
public:
    int x;
    int y;
};

class worm: public engine
{
public:
    engine e;
    worm();
    ~worm();
    void run();
    void move(int, int, char);
    void score_up();
    void print_score();
    void game_over();
    void print_board();
    void respawn(int, int, char);
    char rand_num();
    void grow( int, int);
    void start();

    //fruits
    int fruitX;
    int fruitY;
    int fruitVal;

    //the status of worm
    int x;
    int y;
    int bodyLength = 0;
    vector<Body> body;
    // these variables are being used for updating the body coordinates.
    int prevX;
    int prevY;
    int tempX;
    int tempY;

    // the status of the game
    bool gameOver = false;
    int score = 0;
};
#endif // WORM_H
