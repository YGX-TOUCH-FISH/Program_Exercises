//
// Created by 18163 on 2021/1/20.
//

#ifndef MEMBER_MANAGER_MEMBER_SYSTEM_H
#define MEMBER_MANAGER_MEMBER_SYSTEM_H
#include "Member_block.h"
class Member_system{
public:
    Member_block *head;
public:
    Member_system();

    ~Member_system();

    void add_member(char a, int b, int c);

    void delete_member_byname(char name);

    Member_block *find(char name) const;//name的前一个

    void adjust_salary(char name, int salary);

    void salary_list();

    void clear();
};
#endif //MEMBER_MANAGER_MEMBER_SYSTEM_H
