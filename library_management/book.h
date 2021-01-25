//
// Created by 18163 on 2021/1/25.
//

#ifndef LIBRARY_MANAGEMENT_BOOK_H
#define LIBRARY_MANAGEMENT_BOOK_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class err{
    string message;
public:
    explicit err(const string &ex);

    void explain();
};

class book{
    int number;
    string name;
    int borrow_sign;
public:
    book(const string &s = "", int total_number = 0);

    void borrow_book(const int &index);

    void return_book(const int &index);

    void display_msg();
};


#endif //LIBRARY_MANAGEMENT_BOOK_H
