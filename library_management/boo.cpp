//
// Created by 18163 on 2021/1/25.
//
#include "book.h"
book::book(const char *s, int total) {
    no = total;
    borrowed = 0;
    strcpy(name,s);
}

void book::borrowbook(int readerNo) {
    if (borrowed != 0) cerr<<"this book has been borrowed."<<endl;
    borrowed = readerNo;
}

void book::returnbook() {
    if (borrowed == 0) cerr<<"this book has not been lent out."<<endl;
    borrowed = 0;
}

void book::display() const {
    cout<<setw(10)<<no<<setw(20)<<name<<setw(10)<<borrowed<<endl;
}

