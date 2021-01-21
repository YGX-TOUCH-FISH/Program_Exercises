//
// Created by 18163 on 2021/1/20.
//
#include <iostream>
#include "salary_management.h"
void add_employee(Employee* head){
    Employee* new_employee = new Employee;
    cout<<"please input new employee's name:\n";
    cin>>new_employee->name;
    cout<<"please input new employee's salary:\n";
    cin>>new_employee->salary;
    cout<<"please input new employee's number:\n";
    cin>>new_employee->number;
    new_employee->next = head->next;
    head->next = new_employee;
}
void delete_employee(Employee* head){
    string delete_name;
    cout<<"please input employee's name:\n";
    cin>>delete_name;
    Employee* point = head;
    if (point->next == nullptr){
        cout<<"cannot find this employee\n";
        return;
    }
    while (point->next != nullptr){
        if (point->next->name == delete_name){
            Employee* det = point->next;
            point->next = det->next;
            delete det;
            return;
        }
        point = point->next;
    }
    cout<<"cannot find this employee\n";
}
void adjust_salary(Employee* head){
    string adjust_name;
    cout<<"please input the employee's name:\n";
    cin>>adjust_name;
    Employee* point = head;
    if (point->next == nullptr){
        cout<<"cannot find this employee\n";
        return;
    }
    point = point->next;
    while (point != nullptr){
        if (point->name == adjust_name)break;
        point = point->next;
    }
    if (point == nullptr){
        cout<<"cannot find this employee\n";
        return;
    }
    cout<<"please input the employee's new salary:\n";
    cin>>point->salary;
    cout<<"now "<<point->name<<"'s salary is "<<point->salary<<'\n';
}
void show_list(Employee* head){
    if (head->next == nullptr){
        cout<<"the list is empty now;try to add some employee?\n";
        return;
    }
    Employee *point;
    for(point = head->next ; point ; point = point->next){
        cout<<point->name<<"'s salary is "<<point->salary<<endl;
    }
}
void find_somehelp(){
    cout<<"please input your command:\n"
          "add:add a employee\n"
          "delete:kick off a employee\n"
          "adjust:adjust one employee's salary\n"
          "show:show all employees' salary line by line\n"
          "quit:quit the program\n";
}