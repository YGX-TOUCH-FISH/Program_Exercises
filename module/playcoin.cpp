//
// Created by 18163 on 2021/1/20.
//
#include <ctime>
#include <iostream>
#include "playcoin.h"
using namespace std;
void prn_instruction(){
    cout<<"LET GUESS!";
}
void play(){
    char flag = 'Y';
    int coin;
    srand(time(NULL));
    while (flag == 'Y' || flag == 'y'){
        coin = rand() % 2;
        if (get_call_from_user() == coin){
            cout<<"YOU WIN"<<endl;
        } else cout<<"I WIN"<<endl;
        cout<<"TRY AGAIN?\n";
        cout<<"(INPUT  Y/y OR N/n).";
        cin>>flag;
    }
    cout<<"GOODBYE"<<endl;
}
int get_call_from_user(){
    int guess;
    cout << "INPUT WHAT YOU GUESS : 0/1"<<endl;
    cin>>guess;
    return guess;
}