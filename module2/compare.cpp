//
// Created by 18163 on 2021/1/20.
//
#include "p_r_s.h"
outcome compare(p_r_s user_select , p_r_s program_select){
    if (user_select == program_select) {
        return tie;
    }
    if (user_select == scissor){
        if (program_select == rock){
            return lose;
        }
        else {
            return win;
        }
    }
    if (user_select == rock){
        if (program_select == paper){
            return lose;
        }
        else {
            return win;
        }
    }
    if (user_select == paper){
        if (program_select == scissor){
            return lose;
        }
        else {
            return win;
        }
    }
}


