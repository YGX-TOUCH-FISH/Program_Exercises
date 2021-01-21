//
// Created by 18163 on 2021/1/20.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#ifndef MODULE2_P_R_S_H
#define MODULE2_P_R_S_H
enum p_r_s{paper,rock,scissor,game,help,quit};
enum outcome{win,lose,tie};
p_r_s user_select();
p_r_s program_select();
outcome compare(p_r_s user_choice, p_r_s program_choice);
void report(outcome result);
void game_status();
void find_somehelp();
void bye();

#endif //MODULE2_P_R_S_H
