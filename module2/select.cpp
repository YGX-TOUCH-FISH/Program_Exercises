//
// Created by 18163 on 2021/1/20.
//
#include "p_r_s.h"
using namespace std;
p_r_s user_select(){
    char choice;
    cin>>choice;
    switch (choice) {
        case 'p': return paper;
        case 'r': return rock;
        case 's': return scissor;
        case 'q': return quit;
        case 'g': return game;
        default: return help;
    }
}
p_r_s program_select(){
    int num = rand() % 3;
    switch (num) {
        case 0: return paper;
        case 1: return rock;
        case 2: return scissor;
    }
}
