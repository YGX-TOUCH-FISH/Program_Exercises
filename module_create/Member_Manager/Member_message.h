//
// Created by 18163 on 2021/1/20.
//

#ifndef MEMBER_MANAGER_MEMBER_MESSAGE_H
#define MEMBER_MANAGER_MEMBER_MESSAGE_H
using namespace std;
#include <string>
#include <iostream>
class Member_msg{
public:
    char name;
    int salary;
    int number;
public:
    Member_msg() = default;

    Member_msg(char a , int b ,int c);

    void adjust_salary(int x);

    void output_salary();

    ~Member_msg();

    Member_msg(const Member_msg & some);

    Member_msg &operator =(const Member_msg & right);

    char get_name();
};
#endif //MEMBER_MANAGER_MEMBER_MESSAGE_H
