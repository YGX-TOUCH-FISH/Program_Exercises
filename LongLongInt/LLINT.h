//
// Created by 18163 on 2021/1/21.
//

#ifndef LONGLONGINT_LLINT_H
#define LONGLONGINT_LLINT_H
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
struct single{
    int data;
    single *next;
};

class LongLongInt{
private:
    single *head;
    unsigned length;
public:
    LongLongInt();

    explicit LongLongInt(const string &number);

    LongLongInt operator+(const LongLongInt &ex)const;

    LongLongInt operator-(const LongLongInt &ex)const;

    LongLongInt operator*(const LongLongInt &ex)const;

    LongLongInt &operator++();

    LongLongInt operator++(int x);

    LongLongInt &operator--();

    LongLongInt operator--(int x);

    LongLongInt &operator=(const LongLongInt &ex);

    bool operator ==(const LongLongInt &ex)const;

    bool operator >(const LongLongInt &ex)const;

    bool operator <(const LongLongInt &ex)const;

    friend istream& operator >>(istream &is, LongLongInt &ex);

    friend ostream& operator <<(ostream &os, const LongLongInt &ex);

    friend void clear(LongLongInt &ex);

    friend string ConvertToString(const LongLongInt &ex);

    friend LongLongInt power(const LongLongInt &ex , const int &x);
};

istream& operator >>(istream &is , LongLongInt &ex);

ostream& operator <<(ostream &os , const LongLongInt &ex);

bool check(string &a);

void clear(LongLongInt &ex);

string ConvertToString(const LongLongInt &ex);

LongLongInt power(const LongLongInt &ex , const int &x);

string multiply(const string &a , const string &b);
//original save && reverse order


#endif //LONGLONGINT_LLINT_H
