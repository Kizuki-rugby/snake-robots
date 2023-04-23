#include "createplayer.h"

CreatePlayer::CreatePlayer()
{
    clear();
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    field[0] = new_field(1, 10, 4, 30, 0, 0);
    field[1] = new_field(1,10,6,30,0,0);
    field[2] = new_field(1,10,8,30,0,0);;
    bool loop = true;
    // set the first field underline.
    set_field_back(field[0], A_UNDERLINE);
    set_field_back(field[1], A_UNDERLINE);
    set_field_back(field[2], A_UNDERLINE);
    field_opts_off(field[0], O_AUTOSKIP);
    field_opts_off(field[1], O_AUTOSKIP);
    field_opts_off(field[2], O_AUTOSKIP);

    // Don’t go to next field when this field is filled up.
//    set_field_opts(field[0],O_AUTOSKIP);

    newPlayer = new_form(field);
    post_form(newPlayer);
    refresh();

    mvprintw(4, 10, "Player first  Name: ");
    mvprintw(6,10,"Player last name: ");
    mvprintw(8,10,"player address: ");

    mvprintw(11, 5, "Arrow left - Enter");

    // place the cursor at the appropriate position
    move(4, 30);
    refresh();

   do{
        int ch = getch();
        switch(ch)
        {
        case KEY_DOWN:
            form_driver(newPlayer, REQ_NEXT_FIELD);
            form_driver(newPlayer, REQ_END_LINE);
            break;
        case KEY_UP:
            form_driver(newPlayer, REQ_PREV_FIELD);
            form_driver(newPlayer, REQ_END_LINE);
            break;
        case KEY_LEFT:
            loop = false;
            form_driver(newPlayer, REQ_END_LINE);
            break;
        default:
            form_driver(newPlayer, ch);
            break;
        }
    } while(loop);

    unpost_form(newPlayer);
    free_form(newPlayer);

    // store contents of fields before they are +++freed
    firstName = field_buffer(field[0],0);
    lastName = field_buffer(field[1],0);
    address = field_buffer(field[2],0);
    free_field(field[0]);
    free_field(field[1]);
    free_field(field[2]);

    endwin();
}
