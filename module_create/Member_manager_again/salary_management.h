//
// Created by 18163 on 2021/1/20.
//

#ifndef MEMBER_MANAGER_AGAIN_SALARY_MANAGEMENT_H
#define MEMBER_MANAGER_AGAIN_SALARY_MANAGEMENT_H
using namespace std;
#include <string>
struct Employee{
    string name;
    int salary;
    string number;
    Employee *next;


};
void add_employee(Employee* head);
void delete_employee(Employee* head);
void adjust_salary(Employee* head);
void show_list(Employee* head);
void find_somehelp();
#endif //MEMBER_MANAGER_AGAIN_SALARY_MANAGEMENT_H

