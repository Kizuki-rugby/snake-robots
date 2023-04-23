#ifndef CREATEPLAYER_H
#define CREATEPLAYER_H
#include "../tui/screen.h"
#include "form.h"
#include <string>
#include <iostream>
#include <curses.h>
#include "player.h"



class CreatePlayer
{
public:
    CreatePlayer();
    FIELD *field[3];
    FORM *newPlayer;
    string firstName;
    string lastName;
    string address;
};

#endif // CREATEPLAYER_H
