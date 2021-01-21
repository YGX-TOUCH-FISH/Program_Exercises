//
// Created by 18163 on 2021/1/20.
//

#ifndef MEMBER_MANAGER_MEMBER_BLOCK_H
#define MEMBER_MANAGER_MEMBER_BLOCK_H
#include "Member_message.h"
#include "stdio.h"
class Member_block{
public:
    Member_msg Member_message;
    Member_block *next;
public:
    Member_block();

    Member_block(const Member_msg& msg, Member_block *next_block);

    ~Member_block();

    void adjust_member_salary(int x);

    void output_member_salary();

    Member_block *&get_next();

    char get_name();
};
#endif //MEMBER_MANAGER_MEMBER_BLOCK_H
