//
// Created by 18163 on 2021/1/20.
//
#include "Member_message.h"
Member_msg::Member_msg(char a, int b, int c) {
    name = a;
    salary = b;
    number = c;
}
void Member_msg::adjust_salary(int x) {
    salary = x;
    if (x <= 500) cout<<"YOU ARE SO COLD!SHAME ON YOU!\n";
}
void Member_msg::output_salary() {
    cout<<name<<"'s salary is "<<salary<<"."<<endl;
}

Member_msg::~Member_msg(){
    name = '\0';
    salary = 0;
    number = -1;
}

Member_msg::Member_msg(const Member_msg &some) {
    name = some.name;
    salary = some.salary;
    number = some.number;
}

Member_msg &Member_msg::operator =(const Member_msg &right){
    if (this == &right)return *this;
    name = right.name;
    salary = right.salary;
    number = right.number;
    return *this;
}

char Member_msg::get_name() {
    return name;
}
