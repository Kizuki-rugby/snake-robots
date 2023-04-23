#include <iostream>
#include "../info_bank/game.h"
#include "../info_bank/gamehistory.h"
#include "../info_bank/additionalscreen.h"
#include "../info_bank/player.h"
#include "../info_bank/playergamehistory.h"
#include "../info_bank/selectplayer.h"
#include "gtest/gtest.h"

using namespace std;
using namespace testing;

class InfoTest : public ::testing::Test
{
protected:
    AdditionalScreen as;
    InfoTest()
    {
    }
    virtual ~InfoTest()
    {

    }
    virtual void SetUp()
    {

    }
    virtual void TearDown()
    {

    }
};

TEST_F(InfoTest, startScreen)
{
    as.main_screen();
    Player player("Jack", "horowitz", "test");
    as.player = &player;
}

int main()
{
//    ::testing::InitGoogleTest();
//    return RUN_ALL_TESTS();

    AdditionalScreen as;
    as.main_screen();
    return 0;
}
