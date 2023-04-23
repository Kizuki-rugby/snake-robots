#include <iostream>
#include "worm.h"
#include "robots.h"
#include <engine.h>
#include "gtest/gtest.h"
using namespace std;
using namespace testing;
class FooTest : public ::testing::Test
{
    protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    FooTest()
    {
        worm w;
        robots r;
    }
    virtual ~FooTest()
    {
        // You can do clean-up work that doesn’t throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp()
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }
    virtual void TearDown()
    {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }
    // Objects declared here can be used by all tests in the test case for Foo.
    /** replace with your own **/
    worm w;
    robots r;
    };

    TEST_F(FooTest, movementNorth)
    {
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 5);
        w.move(w.x, w.y, 'n');
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 4);

        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('n');
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 4);
    }

    TEST_F(FooTest, movementEast)
    {
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 5);
        w.move(w.x, w.y, 'e');
        EXPECT_EQ(w.x, 6);
        EXPECT_EQ(w.y, 5);

        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('e');
        EXPECT_EQ(w.x, 6);
        EXPECT_EQ(w.y, 5);
    }

    TEST_F(FooTest, movementSouth)
    {
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 5);
        w.move(w.x, w.y, 's');
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 6);

        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('s');
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 6);
    }

    TEST_F(FooTest, movementWest)
    {
        EXPECT_EQ(w.x, 5);
        EXPECT_EQ(w.y, 5);
        w.move(w.x, w.y, 's');
        w.move(w.x, w.y, 'w');
        EXPECT_EQ(w.x, 4);
        EXPECT_EQ(w.y, 6);

        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('w');
        EXPECT_EQ(w.x, 4);
        EXPECT_EQ(w.y, 5);
    }

    TEST_F(FooTest, movementIntermediate) {
        //northwest
        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('u');
        EXPECT_EQ(w.x, 4);
        EXPECT_EQ(w.y, 4);

        //northeast
        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('i');
        EXPECT_EQ(w.x, 6);
        EXPECT_EQ(w.y, 4);

        //southeast
        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('k');
        EXPECT_EQ(w.x, 6);
        EXPECT_EQ(w.y, 6);

        //southwest
        EXPECT_EQ(r.heroX, 5);
        EXPECT_EQ(r.heroY, 5);
        r.move('j');
        EXPECT_EQ(w.x, 4);
        EXPECT_EQ(w.y, 6);
    }

    TEST_F(FooTest, teleport) {
        ASSERT_EQ(r.board.board[r.heroX][r.heroY], '@');
        int x = r.heroX;
        int y = r.heroY;
        r.teleport();
        ASSERT_NE(r.board.board[x][y], '@');
    }

    TEST_F(FooTest, collision) {
        r.robotLocations[0][0] = 5;
        r.robotLocations[0][1] = 5;
        r.robotLocations[1][0] = 5;
        r.robotLocations[1][1] = 5;
        r.move('n');
        ASSERT_EQ(r.board.board[5][5], '*');
    }

    TEST_F(FooTest, robotTrack) {
        r.robotLocations[0][0] = 1;
        r.robotLocations[0][1] = 1;
        r.robotLocations[1][0] = 1;
        r.robotLocations[1][1] = 11;
        r.robotLocations[2][0] = 11;
        r.robotLocations[2][1] = 11;
        r.robotLocations[3][0] = 11;
        r.robotLocations[3][1] = 1;
        r.heroX = 6;
        r.heroY = 6;
        r.move('n');
        ASSERT_EQ(r.robotLocations[0][0], 2);
        ASSERT_EQ(r.robotLocations[0][1], 2);
        ASSERT_EQ(r.robotLocations[1][0], 2);
        ASSERT_EQ(r.robotLocations[1][1], 10);
        ASSERT_EQ(r.robotLocations[2][0], 10);
        ASSERT_EQ(r.robotLocations[2][1], 10);
        ASSERT_EQ(r.robotLocations[3][0], 10);
        ASSERT_EQ(r.robotLocations[3][1], 2);
    }

    TEST_F(FooTest, bodyGrowth)
    {
        w.fruitVal = 1;
        w.fruitX = 6;
        w.fruitY = 5;
        w.e.board[w.fruitX][w.fruitY] = '1';
        w.move(w.x, w.y, 'e');
        EXPECT_EQ(w.bodyLength, 3);
    }
    TEST_F(FooTest, gameOverBody)
    {
        w.move(w.x,w.y, 'w');
        EXPECT_TRUE(w.gameOver);
    }
    TEST_F(FooTest, gameOverWall)
    {
        w.move(w.x,w.y,'e');
        w.move(w.x,w.y,'e');
        w.move(w.x,w.y,'e');
        w.move(w.x,w.y,'e');
        EXPECT_TRUE(w.gameOver);
    }
    TEST_F(FooTest, scoreUP)
    {
        w.fruitVal = 5;
        w.score_up();
        EXPECT_EQ(w.score,5);
    }
    TEST_F(FooTest,bodyFollows)
    {
    w.move(w.x,w.y,'e');
    EXPECT_EQ(w.e.board[5][5],'o');
    }


int main()
{


}
