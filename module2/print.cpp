//
// Created by 18163 on 2021/1/20.
//
#include "p_r_s.h"
using namespace std;
static int game_time = 0, win_time = 0, lose_time = 0 , tie_time = 0;
void find_somehelp(){
    cout<<"please input what you want \n"
          "1    'p' means 'paper'\n"
          "2    'r' means 'rocks'\n"
          "3    's' means 'scissors'\n"
          "4    'q' means 'quit'\n"
          "5    'g' means 'game'\n"
          "6    any other input means 'help' (again)\n";
}

void report(outcome result){
    game_time++;
    if (result == win){
        win_time++;
        cout<<"YOU WIN! WIN AGAIN?\n";
        return;
    }
    if (result == lose){
        lose_time++;
        cout<<"YOU LOSE! TRY WIN?\n";
        return;
    }
    if (result == tie){
        tie_time++;
        cout<<"TIE! JUST A COINCIDENCE...\n";
        return;
    }
}
void game_status(){
    cout<<"WE HAVE PLAYED "<<game_time<<" TIMES\n";
    cout<<"YOU HAVE WON "<<win_time<<" TIMES\n";
    cout<<"YOU HAVE LOST "<<lose_time<<" TIMES\n";
    cout<<"WE HAVE TIED "<<tie_time<<"TIMES\n";
}
void bye(){
    cout<<"GOODBYE!\n";
}
