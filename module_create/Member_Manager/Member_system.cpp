//
// Created by 18163 on 2021/1/20.
//
#include "Member_system.h"
Member_system::Member_system() {
    head = new Member_block;
}

Member_system::~Member_system() {
    clear();
    delete head;
    head = nullptr;
}


void Member_system::add_member(char a, int b, int c) {

    Member_msg anewmsg(a,b,c);
    Member_block anewblk(anewmsg, nullptr);

    Member_block *point = head;
    //cout<<(void *)head<<endl;
    while (point->get_next() != nullptr){
        point = point->get_next();
    }
    point->get_next() = &anewblk;
    //cout<<(void *)&anewblk<<endl;
    cout<<point->get_next()->get_name();
}

Member_block *Member_system::find(char name) const {
    Member_block *point = head;
    if (head->get_next() == nullptr)return nullptr;
    while (point->next->next != nullptr){
        if (point->next->Member_message.name == name){
            return point;
        }
    }
    if (point->next->Member_message.name == name)return point;
    return nullptr;
}

void Member_system::delete_member_byname(char name) {
    Member_block *point = find(name);
    if (point == nullptr){
        cout<<"CANNOT FIND THIS MEMBER"<<endl;
    } else{
        Member_block *tmp = point->get_next();
        tmp->get_next() = point->get_next();
        delete tmp;
    }
}

void Member_system::adjust_salary(char name,int salary) {
    Member_block *point = find(name);
    if (point == nullptr){
        cout<<"CANNOT FIND THIS MEMBER"<<endl;
    } else{
        point = point->get_next();
        point->Member_message.salary = salary;
        if (salary < 50)cout<<"shame on you!";
    }

}

void Member_system::salary_list() {
    Member_block *point = head;
    point = point->get_next();
    cout<<point->Member_message.name;
}

void Member_system::clear() {
    Member_block *p,*q;
    if (head == nullptr) return;
    p = head->get_next();
    while (p != nullptr){
        q = p->get_next();
        free(p);
        p = q;
    }
    head->get_next() = nullptr;

}