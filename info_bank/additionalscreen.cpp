#include "additionalscreen.h"

using namespace std;
AdditionalScreen::AdditionalScreen()
{
    Screen s;
    player = NULL;
    ph = new PlayerGameHistory();
}

AdditionalScreen::~AdditionalScreen()
{
    delete pw;
    delete pr;
}

void AdditionalScreen::main_screen()
{
    if (player == NULL)
    {
        mvprintw(1,1,"Current Player: No Player Selected");
    }
    else
    {
        string st = "Current Player:";
        st += player->playerNameFirst + player->playerNameLast;
        const char* str = st.c_str();
        mvprintw(1,1,str);
    }

    mvprintw(3,1,"a. Create a New Player");
    mvprintw(4,1, "b. Select an Existing Player");

    mvprintw(6,1, "c. Display Top Three Players");
    mvprintw(7,1,"d. Display Top Three Games Played");
    mvprintw(8,1,"e. Display Calculated Statistics");

    mvprintw(9,1,"f. Play Robots");
    mvprintw(10,1,"g. Play Worm");

    mvprintw(12, 1, "q. Exit Program");
    refresh();

    // taking user's input
    int ch = getch();
    if (ch == 'a') new_player();
    else if (ch == 'b') select_existing_player();
    else if (ch == 'c') display_top_three_players();
    else if (ch == 'd') display_top_three_games();
    else if (ch == 'e') display_calculated_statistics();
    else if (ch == 'f') play_robot();
    else if (ch == 'g') play_worm();
    else if (ch == 'q') endwin();
    else main_screen();
}

void AdditionalScreen::new_player()
{
    CreatePlayer newPlayer;
    player = new Player(newPlayer.firstName, newPlayer.lastName, newPlayer.address);
    ph->add_player(player);
    main_screen();
}

void AdditionalScreen::select_existing_player() {
    selectplayer select(ph);
    player = select.current;        //reassign current player
    main_screen();
}

void AdditionalScreen::display_top_three_players()
{
   TopPlayers topPlayer(ph);
    main_screen();
}

void AdditionalScreen::display_top_three_games()
{
    TopScores topScore(ph);
    main_screen();
}

void AdditionalScreen::display_calculated_statistics()
{
    Stats stat(ph, player);
    main_screen();
}

void AdditionalScreen::play_robot()
{
    PlayRobot* pr = new PlayRobot(player);
    this->pr = pr;
    delete pr;
    main_screen();
}

void AdditionalScreen::play_worm()
{
    PlayWorm* pw = new PlayWorm(player);
    this->pw = pw;
    delete pw;
    main_screen();
}

