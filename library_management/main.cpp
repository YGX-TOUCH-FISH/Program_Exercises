#include <iostream>
#include <fstream>
#include "book.h"
using namespace std;
void init();
void addbook();
void borrow();
void back();
void show_message();
void createInvertFile();
int main() {


    return 0;
}

void init(){
    ofstream outfile;
    outfile.open("booklist");
    int total_number = 0;
    outfile.write(reinterpret_cast<char *>(&total_number), sizeof(total_number));
    outfile.close();
}

void addbook(){
    int total_number;
    fstream iofile;
    iofile.open("booklist");
    iofile.seekg(0);
    iofile.read(reinterpret_cast<char *>(&total_number), sizeof(total_number));
    ++total_number;
    string a;
    book *bk;
    while (true){
        cout<<"please input book name:\n";
        cin>>a;
        try {
            bk = new book(a,total_number);
            break;
        } catch (err &ex) {
            ex.explain();
            continue;
        }
    }
    iofile.seekp(0);
    iofile.write(reinterpret_cast<char *>(&total_number), sizeof(total_number));
    iofile.seekp((total_number-1)*sizeof(*bk) + sizeof(total_number));
    iofile.write(reinterpret_cast<char *>(bk), sizeof(*bk));
    delete bk;
    iofile.close();
}

void borrow(){
    int bknum;
    int readernum;
    book bk;
    fstream iofile;
    iofile.open("booklist");
    while (true){
        try {
            cout<<"please input book number:\n";
            cin>>bknum;
            iofile.seekg((bknum-1)*sizeof(book)+sizeof(int));
            cout<<"please input reader number\n";
            cin>>readernum;
            iofile.read(reinterpret_cast<char *>(&bk), sizeof(bk));
            bk.borrow_book(readernum);
            break;
        } catch (err &ex) {
            ex.explain();
            continue;
        }
    }
}

void back(){
    int bknum;
    int readernum;
    book bk;
    fstream iofile;
    iofile.open("booklist");
    while (true){
        try {
            cout<<"please input book number:\n";
            cin>>bknum;
            iofile.seekg((bknum-1)*sizeof(book)+sizeof(int));
            cout<<"please input reader number\n";
            cin>>readernum;
            iofile.read(reinterpret_cast<char *>(&bk), sizeof(bk));
            bk.return_book(readernum);
            break;
        } catch (err &ex) {
            ex.explain();
            continue;
        }
    }
}

void show_message(){
    book bk;
    fstream iofile("booklist");
    iofile.seekg(sizeof(int));
    iofile.read(reinterpret_cast<char *>(&bk), sizeof(bk));
    cout<<setw(10)<<"NUMBER"<<setw(20)<<"NAME"<<setw(10)<<"BORROW"<<'\n';
    while (!iofile.eof()){
        bk.display_msg();
        iofile.read(reinterpret_cast<char *>(&bk), sizeof(bk));
    }
    iofile.close();
}

//void createInvertFile(){
//    fstream outlist;
//    outlist.open("booklist");
//    if (!outlist){
//        cerr<<"fail to open booklist\n";
//        return;
//    }
//    ofstream outkeylist;
//    outkeylist.open("keywordlist");
//    if (!outkeylist){
//        cerr<<"fail to open keywordlist\n";
//        return;
//    }
//
//}