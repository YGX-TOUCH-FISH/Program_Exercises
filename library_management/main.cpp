#include <iostream>
#include <fstream>
#include "book.h"
using namespace std;
void init();

void addbook();

void borrow();

void back();

void displaybook();

void help();
int main() {
    int select;
    void (*func[5])()= {init ,  addbook , borrow , back, displaybook};
    help();
    while (true){
        cin>>select;
        if (select == -1)break;
        if (select >= 5)help();
        func[select]();
    }
    cout<<"wish you a nice day!";
    return 0;
}
void init(){
    ofstream outfile("book");
    int no = 0;

    outfile.write(reinterpret_cast<char *>(&no), sizeof(no));
    outfile.close();
}

void addbook(){
    //open the database
    fstream outfile("book");outfile.seekg(0);outfile.seekp(0);

    char ch[20];
    book *additive;
    int currentno;
    outfile.read(reinterpret_cast<char *>(&currentno),sizeof (currentno));
    //update current number && make a new book
    cout<<"please input the name of book:";
    cin>>ch;
    ++currentno;
    additive = new book(ch , currentno);
    //add message
    outfile.seekp(0,ios::end);
    outfile.write(reinterpret_cast<char *>(additive),sizeof (*additive));
    delete additive;
    //update current number in file
    outfile.seekp(0);
    outfile.write(reinterpret_cast<char *>(&currentno),sizeof (currentno));

    outfile.close();
}

void borrow(){
    int booknumber , readernumber;
    fstream outfile("book");outfile.seekp(0);outfile.seekg(0);
    book bk;

    cout<<"please input the number of book and the number of reader:"<<endl;
    cin>>booknumber>>readernumber;

    outfile.seekg((booknumber-1)*sizeof(book) + sizeof(int));
    outfile.read(reinterpret_cast<char *>(&bk), sizeof(bk));

    bk.borrowbook(readernumber);

    outfile.seekp((booknumber-1)*sizeof(book) + sizeof(int));
    outfile.write(reinterpret_cast<char *>(&bk), sizeof(bk));

    outfile.close();
}

void back(){
    int booknumber;
    book bk;
    fstream outfile("book");

    cout<<"please input the book's number that should be returned:"<<endl;
    cin>>booknumber;

    outfile.seekg((booknumber-1)* sizeof(bk)+ sizeof(int ));
    outfile.read(reinterpret_cast<char *>(&bk), sizeof(bk));

    bk.returnbook();

    outfile.seekp((booknumber-1)* sizeof(bk)+ sizeof(int ));
    outfile.write(reinterpret_cast<char *>(&bk), sizeof(bk));

    outfile.close();
}

void displaybook(){
    ifstream infile("book");
    book bk;
    cout<<"NUMBER                NAME             BORROW\n";
    infile.seekg(sizeof(int ));
    infile.read(reinterpret_cast<char *>(&bk),sizeof(bk));
    while (!infile.eof()){
        bk.display();
        infile.read(reinterpret_cast<char *>(&bk),sizeof(bk));
    }
    infile.close();
}

void help(){
    cout<<"welcome to my library!"<<endl;
    cout<<"-1 ---exit\n"
          "0  ---initialize the file \n"
          "1  ---add a book\n"
          "2  ---borrow a book\n"
          "3  ---return a book\n"
          "4  ---show all  the book's message\n";
}