#include "Member_block.h"
#include "Member_system.h"
#include <string>
#include <iostream>
using namespace std;
void find_somehelp(){
    cout<<"PLEASE INPUT YOUR COMMAND:\n"
          "ADD        NAME-SALARY-NUMBER \n"
          "KICK       NAME               \n"
          "ADJUST     NAME-SALARY        \n"
          "LIST                          \n"
          "CLEAR                         \n"
          "QUIT                          \n";
}
int main() {
    Member_system MY_SYSTEM;
    find_somehelp();
    while (true){
        string command ;
        int flag = 0;
        cin>>command;
        if (command == "ADD")flag = 1;
        if (command == "KICK")flag = 2;
        if (command == "ADJUST")flag = 3;
        if (command == "LIST")flag = 4;
        if (command == "CLEAR")flag = 5;
        if (command == "QUIT")flag = 6;
        switch (flag) {
            case 1:{
                char Mname;int Msalary;int Mnumber;
                cin>>Mname>>Msalary>>Mnumber;
                MY_SYSTEM.add_member(Mname,Msalary,Mnumber);
                break;
            }
            case 2:{
                char name;
                cin>>name;
                MY_SYSTEM.delete_member_byname(name);
                break;
            }
            case 3:{
                char name;
                int salary;
                cin>>name>>salary;
                MY_SYSTEM.adjust_salary(name,salary);
                break;
            }
            case 4:{
                Member_block *h = MY_SYSTEM.head;
                h = h->next;
                while (h != nullptr){
                    cout<<h->Member_message.name<<"'s salary is "<<h->Member_message.salary<<endl;
                    h = h->next;
                }
                break;
            }
            case 5:{
                MY_SYSTEM.clear();
                break;
            }
            case 6:{
                return 0;
            }
            default: {
                find_somehelp();break;
            }
        }
    }
}
