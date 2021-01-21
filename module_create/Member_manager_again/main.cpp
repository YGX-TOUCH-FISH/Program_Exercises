#include <iostream>
#include "salary_management.h"
int main() {
    Employee* head = new Employee;
    head->next = nullptr;//若无此句，程序异常终止（未定义的操作）
    string command;
    int flag = -1;
    find_somehelp();
    while (true){
        cin>>command;
        if (command == "add")flag = 0;
        if (command == "delete")flag = 1;
        if (command == "adjust")flag = 2;
        if (command == "show")flag = 3;
        if (command == "quit")flag = 4;
        switch (flag) {
            case 0: {
                add_employee(head);
                cout<<"your next command?\n";
                break;
            }
            case 1: {
                delete_employee(head);
                cout<<"your next command?\n";
                break;
            }
            case 2: {
                adjust_salary(head);
                cout<<"your next command?\n";
                break;
            }
            case 3: {
                show_list(head);
                cout<<"your next command?\n";
                break;
            }
            case 4: return 0;
            default: {
                find_somehelp();
                cout<<"your next command?\n";

            }
        }
    }
}
