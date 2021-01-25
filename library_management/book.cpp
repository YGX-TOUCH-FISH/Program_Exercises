//
// Created by 18163 on 2021/1/25.
//
#include "book.h"
err::err(const string &ex) {
    message = ex;
}

void err::explain() {
    cout<<message<<'\n';
}

book::book(const string &s, int total_number) {
    if (s.length() > 20)throw err("name overflow");
    name = s ;
    number = total_number;
    borrow_sign = 0;
}

void book::borrow_book(const int &index) {
    if (borrow_sign != 0)
        throw err("this book has been lent out");
    borrow_sign = index;
}

void book::return_book(const int &index) {
    if (index <= 0)
        throw err("invalid input");
    if (borrow_sign == 0)
        throw err("this book hasn't been lent out");
    if (borrow_sign != index)
        throw err("you are not the borrower");
    borrow_sign = 0;
}

void book::display_msg() {
    cout<<setw(10)<<number<<setw(20)<<name<<setw(10)<<borrow_sign<<'\n';
}