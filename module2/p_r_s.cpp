//
// Created by 18163 on 2021/1/20.
//

#include "p_r_s.h"
int main(void ){
    outcome result;
    p_r_s user_choice, program_choice;
    srand(time(NULL));
    find_somehelp();
    while ((user_choice = user_select()) != quit){
        switch (user_choice) {
            case paper:
            case rock :
            case scissor:{
                program_choice = program_select();
                result = compare(user_choice,program_choice);
                report(result);
                break;
            }
            case help:  find_somehelp();break;
            case game:  game_status();break;
        }
    }
    bye();
    return 0;
}
