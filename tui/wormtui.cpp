#include "wormtui.h"

WormTui::WormTui()
{
    Screen s;
    worm w;
}
WormTui::~WormTui()
{

}

void WormTui::run()
{
    bool loop = true;
    s.draw_screen(&w.e);
    print_score();
    while(loop){
        refresh();
        w.move(w.x,w.y,s.getDirection());
        s.draw_screen(&w.e);
        print_score();
        refresh();
        if (s.direction == '\0' || w.gameOver)
        {
            loop = false;
        }
    }
    done();
}

void WormTui::done()
{
    s.finished();
    string st = "Your final score was ";
    st += to_string(w.score);
    st += "\n";
    const char* str = st.c_str();
    mvprintw(2,1,str);
    mvprintw(5, 1, "would you like to play again? (Y/N)");
    refresh();
    int ch = getch();
    if(ch == 'y' || ch == 'Y')
    {
        Screen s;
        worm w;
        this->w = w;
        this->s = s;
        run();
    }
}
void WormTui::print_score()
{
    string st = "score: ";
    st += to_string(w.score);
    const char* str = st.c_str();
    mvprintw(5, w.e.getCol() + 3,str);
//    mvprintw(5,20,"test");
}
