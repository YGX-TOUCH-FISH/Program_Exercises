//
// Created by 18163 on 2021/1/20.
//
#include "Member_block.h"
Member_block::Member_block() {
    next = nullptr;
}

Member_block::Member_block(const Member_msg& msg, Member_block *next_block) {
    Member_message = msg;
    next = next_block;
}

Member_block::~Member_block(){
    delete next;
    next = nullptr;
}

void Member_block::adjust_member_salary(int x) {
    Member_message.adjust_salary(x);
}

void Member_block::output_member_salary() {
    Member_message.output_salary();
}

Member_block *&Member_block::get_next() {
    return next;
}

char Member_block::get_name() {
    return Member_message.get_name();
}