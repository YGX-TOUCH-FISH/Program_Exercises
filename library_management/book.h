//
// Created by 18163 on 2021/1/25.
//

#ifndef LIBRARY_MANAGEMENT_BOOK_H
#define LIBRARY_MANAGEMENT_BOOK_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class book{
    int no;
    char name[20];
    int borrowed;

public:
    book(const char *s = "" , int total = 0);

    void borrowbook(int readerNo);

    void returnbook();

    void display()const;
};

#endif //LIBRARY_MANAGEMENT_BOOK_H
