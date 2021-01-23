//
// Created by 18163 on 2021/1/21.
//
#include "LLINT.h"
LongLongInt::LongLongInt() {
    head = new single;
    head->data = 0;
    //0 means positive,while 1 means negative;
    single *p;
    p = new single;
    p->data = 0;
    p->next = nullptr;
    head->next = p;
    length = 1;
}

LongLongInt::LongLongInt(const string &number) {
    //special judge when >> or << ;
    //judge1: number.empty()
    //judge2: number == "-"
    //judge3: number contains no-number char
    //...
    //LinkList: head(p/n)-> (10^0) -> ... -> (10^(length-1)) -> nullptr
    head = new single;
    head->next = nullptr;
    if (number[0] == '-'){
        head->data = 1;//negative
        length = number.length() - 1;
        for(int i = 1 ; i < number.length() ; ++i){
            single *p ;
            p = new single;
            p->data = number[i] - '0';
            p->next = head->next;
            head->next = p;
        }
    } else{
        head->data = 0;
        length = number.length();
        for(int i = 0 ; i < number.length() ; ++i){
            single *p;
            p = new single;
            p->data = number[i] - '0';
            p->next = head->next;
            head->next = p;
        }
    }
}

LongLongInt::LongLongInt(const int &number) {
    head = new single;
    head->next = nullptr;
    if (number < 0)head->data = 1;
    else head->data = 0;

    int num = number;
    string value;
    if (num < 0)num = -num;
    while (num != 0){
        value += num%10 + '0';
        num /= 10;
    }
    length = value.length();
    reverse(value.begin(),value.end());
    for(int i = 0 ; i < length ; ++i){
        single *point;
        point = new single;
        point->data = value[i] - '0';
        point->next = head->next;
        head->next = point;
    }
}

LongLongInt LongLongInt::operator+(const LongLongInt &ex) const {
    string number1 = ConvertToString(*this);
    string number2 = ConvertToString(ex);
    //num1 num2 : reverse order (absolute value) WITHOUT '-'!!!
//    if (head->data == 1)number1 += '-';
//    if (ex.head->data == 1)number2 += '-';
    string sumstr;
    string answer_str;
    unsigned len1 , len2 , maxlen , minlen;
    int *carry_array;
    int x;
    char xx;
    if (head->data == 0 && ex.head->data == 0){
        len1 = number1.length();
        len2 = number2.length();
        maxlen = max(len1, len2);
        minlen = min(len1, len2);
        carry_array = new int [maxlen + 1]{0};//init with value 0
        if (len1 == len2){//maxlen == minlen
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - '0' + number2[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            if (carry_array[maxlen] == 1)sumstr += "1";
        }
        if (len1 > len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - '0' + number2[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number1[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            if (carry_array[maxlen] == 1)sumstr += "1";
        }
        if (len1 < len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - '0' + number2[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number2[i] - '0' + carry_array[i];\
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            if (carry_array[maxlen] == 1)sumstr += "1";
        }
        answer_str = sumstr;
    }// p + p //right
    if (head->data == 1 && ex.head->data == 1){
        len1 = number1.length();
        len2 = number2.length();
        maxlen = max(len1, len2);
        minlen = min(len1, len2);
        carry_array = new int [maxlen + 1]{0};//init with value 0
        if (len1 == len2){//maxlen == minlen
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - '0' + number2[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            if (carry_array[maxlen] == 1)sumstr += "1";
        }
        if (len1 > len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - '0' + number2[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number1[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            if (carry_array[maxlen] == 1)sumstr += "1";
        }
        if (len1 < len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - '0' + number2[i] - '0' + carry_array[i];
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number2[i] - '0' + carry_array[i];\
                carry_array[i+1] = (x - x%10)/10;
                x %= 10;
                xx = x + '0';
                sumstr += xx;
            }
            if (carry_array[maxlen] == 1)sumstr += "1";
        }
        answer_str = sumstr;
        answer_str += '-';
    }// n + n //right
    if (head->data == 0 && ex.head->data == 1){// p + n
        len1 = number1.length();
        len2 = number2.length();
        maxlen = max(len1, len2);
        minlen = min(len1, len2);
        carry_array = new int [maxlen + 1]{0};
        if (len1 == len2){
            reverse(number1.begin(),number1.end());
            reverse(number2.begin(),number2.end());
            if (number1 == number2){
                sumstr = "0";
                answer_str = "0";
            }//abs(n1) == abs(n2)
            if (number1 > number2){
                reverse(number1.begin(),number1.end());
                reverse(number2.begin(),number2.end());
                for(int i = 0 ; i < minlen ; ++i){
                    x = number1[i] - number2[i] - carry_array[i];
                    if (x < 0){
                        carry_array[i+1] = 1;
                        x += 10;
                    }
                    xx = x + '0';
                    sumstr += xx;
                }
                reverse(sumstr.begin(),sumstr.end());
                bool flag = false;
                for(int i = 0 ; i < sumstr.length(); ++i){
                    if (sumstr[i] != '0' && !flag)flag = true;
                    if (!flag) continue;
                    answer_str += sumstr[i];
                }
            }//abs(n1) > abs(n2)
            if (number1 < number2){
                reverse(number1.begin(),number1.end());
                reverse(number2.begin(),number2.end());
                for(int i = 0 ; i < minlen ; ++i){
                    x = number2[i] - number1[i] - carry_array[i];
                    if (x < 0){
                        carry_array[i+1] = 1;
                        x += 10;
                    }
                    xx = x + '0';
                    sumstr += xx;
                }
                reverse(sumstr.begin(),sumstr.end());
                bool flag = false;
                for(int i = 0 ; i < sumstr.length(); ++i){
                    if (sumstr[i] != '0' && !flag)flag = true;
                    if (!flag) continue;
                    answer_str += sumstr[i];
                }
                reverse(answer_str.begin(),answer_str.end());
                answer_str += '-';//opposite
                reverse(answer_str.begin(),answer_str.end());
            }//abs(n1) < abs(n2)
        }//maxlen == minlen //right
        if (len1 > len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - number2[i] - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number1[i] - '0' - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            reverse(sumstr.begin(),sumstr.end());
            bool flag = false;
            for(int i = 0 ; i < sumstr.length(); ++i){
                if (sumstr[i] != '0' && !flag)flag = true;
                if (!flag) continue;
                answer_str += sumstr[i];
            }
        }//abs(n1) > abs(n2) //see you tomorrow
        if (len1 < len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number2[i] - number1[i] - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number2[i] - '0' - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            reverse(sumstr.begin(),sumstr.end());
            bool flag = false;
            for(int i = 0 ; i < sumstr.length(); ++i){
                if (sumstr[i] != '0' && !flag)flag = true;
                if (!flag) continue;
                answer_str += sumstr[i];
            }
            reverse(answer_str.begin(),answer_str.end());
            answer_str += '-';
            reverse(answer_str.begin(),answer_str.end());
        }//abs(n1) < abs(n2)
    }// p + n
    if (head->data == 1 && ex.head->data == 0){// n + p;
        swap(number1,number2);//Convert it to p + n;
        len1 = number1.length();
        len2 = number2.length();
        maxlen = max(len1, len2);
        minlen = min(len1, len2);
        carry_array = new int [maxlen + 1]{0};
        if (len1 == len2){
            reverse(number1.begin(),number1.end());
            reverse(number2.begin(),number2.end());
            if (number1 == number2){
                sumstr = "0";
                answer_str = "0";
            }//abs(n1) == abs(n2)
            if (number1 > number2){
                reverse(number1.begin(),number1.end());
                reverse(number2.begin(),number2.end());
                for(int i = 0 ; i < minlen ; ++i){
                    x = number1[i] - number2[i] - carry_array[i];
                    if (x < 0){
                        carry_array[i+1] = 1;
                        x += 10;
                    }
                    xx = x + '0';
                    sumstr += xx;
                }
                reverse(sumstr.begin(),sumstr.end());
                bool flag = false;
                for(int i = 0 ; i < sumstr.length(); ++i){
                    if (sumstr[i] != '0' && !flag)flag = true;
                    if (!flag) continue;
                    answer_str += sumstr[i];
                }
            }//abs(n1) > abs(n2)
            if (number1 < number2){
                reverse(number1.begin(),number1.end());
                reverse(number2.begin(),number2.end());
                for(int i = 0 ; i < minlen ; ++i){
                    x = number2[i] - number1[i] - carry_array[i];
                    if (x < 0){
                        carry_array[i+1] = 1;
                        x += 10;
                    }
                    xx = x + '0';
                    sumstr += xx;
                }
                reverse(sumstr.begin(),sumstr.end());
                bool flag = false;
                for(int i = 0 ; i < sumstr.length(); ++i){
                    if (sumstr[i] != '0' && !flag)flag = true;
                    if (!flag) continue;
                    answer_str += sumstr[i];
                }
                reverse(answer_str.begin(),answer_str.end());
                answer_str += '-';//opposite
                reverse(answer_str.begin(),answer_str.end());
            }//abs(n1) < abs(n2)
        }//maxlen == minlen //right
        if (len1 > len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number1[i] - number2[i] - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number1[i] - '0' - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            reverse(sumstr.begin(),sumstr.end());
            bool flag = false;
            for(int i = 0 ; i < sumstr.length(); ++i){
                if (sumstr[i] != '0' && !flag)flag = true;
                if (!flag) continue;
                answer_str += sumstr[i];
            }
        }//abs(n1) > abs(n2) //see you tomorrow
        if (len1 < len2){
            for(int i = 0 ; i < minlen ; ++i){
                x = number2[i] - number1[i] - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            for(int i = minlen ; i < maxlen ; ++i){
                x = number2[i] - '0' - carry_array[i];
                if (x < 0){
                    carry_array[i+1] = 1;
                    x += 10;
                }
                xx = x + '0';
                sumstr += xx;
            }
            reverse(sumstr.begin(),sumstr.end());
            bool flag = false;
            for(int i = 0 ; i < sumstr.length(); ++i){
                if (sumstr[i] != '0' && !flag)flag = true;
                if (!flag) continue;
                answer_str += sumstr[i];
            }
            reverse(answer_str.begin(),answer_str.end());
            answer_str += '-';
            reverse(answer_str.begin(),answer_str.end());
        }//abs(n1) < abs(n2)
    }// n + p to be done
    LongLongInt answer(answer_str);
    return answer;
}

LongLongInt LongLongInt::operator-(const LongLongInt &ex) const {
    string tmp = ConvertToString(ex);

    if (ex.head->data == 1){
        reverse(tmp.begin(),tmp.end());
        LongLongInt other(tmp);
        return (*this + other);
    }//*this - n
    if (ex.head->data == 0){
        tmp += '-';
        reverse(tmp.begin(),tmp.end());
        LongLongInt other(tmp);
        return (*this + other);
    }
}

LongLongInt LongLongInt::operator*(const LongLongInt &ex) const {
    string number1 = ConvertToString(*this);
    string number2 = ConvertToString(ex);
    string number = multiply(number1,number2);
    if (head->data + ex.head->data == 1)
        number += '-';
    reverse(number.begin(),number.end());
    LongLongInt answer(number);
    return answer;
}

LongLongInt &LongLongInt::operator++() {
    LongLongInt bit(1);
    *this = *this + bit;
    return *this;
}

LongLongInt LongLongInt::operator++(int x) {
    string value = ConvertToString(*this);
    if (head->data == 1)value += '-';
    reverse(value.begin(),value.end());
    LongLongInt answer(value);
    LongLongInt bit(1);
    *this = *this + bit;
    return answer;
}

LongLongInt &LongLongInt::operator--() {
    LongLongInt bit(-1);
    *this = *this + bit;
    return *this;
}

LongLongInt LongLongInt::operator--(int x){
    string value = ConvertToString(*this);
    if (head->data == 1)value += '-';
    reverse(value.begin(),value.end());
    LongLongInt answer(value);
    LongLongInt bit(-1);
    *this = *this + bit;
    return answer;
}

LongLongInt &LongLongInt::operator=(const LongLongInt &ex) {
    if (this == &ex)return *this;
    //to handle self-assignment
    clear(*this);
    head->data = ex.head->data;
    string number = ConvertToString(ex);
    reverse(number.begin(),number.end());
    //now number is on correct order..
    length = number.length();
    for(auto i : number){
        single *pointer;
        pointer = new single;
        pointer->data = i - '0';
        pointer->next = head->next;
        head->next = pointer;
    }
    return *this;
}

LongLongInt &LongLongInt::operator=(const int &ex) {
    clear(*this);
    if (ex >= 0)this->head->data = 0;
    if (ex < 0)this->head->data = 1;
    int num = ex;
    string value;
    if (num < 0)num = -num;
    while (num != 0){
        value += num%10 + '0';
        num /= 10;
    }
    length = value.length();
    reverse(value.begin(),value.end());
    for(int i = 0 ; i < length ; ++i){
        single *point;
        point = new single;
        point->data = value[i] - '0';
        point->next = head->next;
        head->next = point;
    }
    return *this;
}

bool LongLongInt::operator==(const LongLongInt &ex)const{
    if (length != ex.length )return false;
    if (head->data != ex.head->data)return false;
    string number1 = ConvertToString(*this);
    string number2 = ConvertToString(ex);
    reverse(number1.begin(),number1.end());
    reverse(number2.begin(),number2.end());
    if (number1 != number2)return false;
    return true;
}

bool LongLongInt::operator>(const LongLongInt &ex) const{
    if (*this == ex)return false;
    string number1 = ConvertToString(*this);
    string number2 = ConvertToString(ex);
    reverse(number1.begin(),number1.end());
    reverse(number2.begin(),number2.end());
    switch (head->data + ex.head->data) {
        case 0:{//p - p
            if (length > ex.length)return true;
            if (length < ex.length)return false;
            if (number1 > number2)return true;
            return false;
        }
        case 1:{//p - n / n - p
            if (head->data == 0)return true;
            if (head->data == 1)return false;
        }
        case 2:{//n - n
            if (length > ex.length)return false;
            if (length < ex.length)return true;
            if (number1 < number2)return true;
            return false;
        }
    }
}

bool LongLongInt::operator<(const LongLongInt &ex) const{
    if (*this == ex)return false;//==
    string number1 = ConvertToString(*this);
    string number2 = ConvertToString(ex);
    reverse(number1.begin(),number1.end());
    reverse(number2.begin(),number2.end());
    switch (head->data + ex.head->data) {
        case 0:{//p - p
            if (length < ex.length)return true;
            if (length > ex.length)return false;
            if (number1 < number2)return true;
            return false;
        }
        case 1:{//p - n / n - p
            if (head->data == 1)return true;
            if (head->data == 0)return false;
        }
        case 2:{//n - n
            if (length > ex.length)return true;
            if (length < ex.length)return false;
            if (number1 > number2)return true;
            return false;
        }
    }
}

istream &operator>>(istream &is ,LongLongInt &ex){
    string number;
    is>>number;
    if (!check(number))return is;//convert it to cerr?
    clear(ex);
    if (number[0] == '-'){
        ex.head->data = 1;//negative
        ex.length = number.length() - 1;
        for(int i = 1 ; i < number.length() ; ++i){
            single *p ;
            p = new single;
            p->data = number[i] - '0';
            p->next = ex.head->next;
            ex.head->next = p;
        }
    } else{
        ex.head->data = 0;
        ex.length = number.length();
        for(int i = 0 ; i < number.length() ; ++i){
            single *p;
            p = new single;
            p->data = number[i] - '0';
            p->next = ex.head->next;
            ex.head->next = p;
        }
    }
    return is;
}

ostream &operator<<(ostream &os, const LongLongInt &ex){
    string answer , counterfeit;
    counterfeit = ConvertToString(ex);
    if (ex.head->data == 1)counterfeit += "-";
    reverse(counterfeit.begin(),counterfeit.end());
    answer = counterfeit;
    os<<answer;
    return os;
}

bool check(string &a){
    if (a[0] != '-'){
        if (a[1] == '0'){
            a = "0";return true;
        }
        for(int i = 0 ; i < a.length() ; ++i){
            if (a[i] < '0' || a[i] > '9')return false;
        }
        return true;
    }
    if (a[0] == '-'){
        for(int i = 1 ; i < a.length() ; ++i){
            if (a[i] < '0' || a[i] > '9')return false;
        }
        return true;
    }
}

void clear(LongLongInt &ex) {
    while (ex.head->next != nullptr){
        auto p = ex.head->next;
        auto q = p->next;
        delete p ;
        ex.head->next = q;
    }
    ex.head->data = 0;
    ex.length = 0;
}

string ConvertToString(const LongLongInt &ex){
    string number;
    single *pointer = ex.head;
    pointer = pointer->next;
    while (pointer != nullptr){
        switch (pointer->data) {
            case 0:number += "0";break;
            case 1:number += "1";break;
            case 2:number += "2";break;
            case 3:number += "3";break;
            case 4:number += "4";break;
            case 5:number += "5";break;
            case 6:number += "6";break;
            case 7:number += "7";break;
            case 8:number += "8";break;
            case 9:number += "9";break;
        }
        pointer = pointer->next;
    }
    return number;
}

string multiply(const string &a, const string &b){
    //a , b: reverse order
    unsigned length1 , length2;
    int *save_a , *save_b , *product;
    string answer;
    length1 = a.length();
    length2 = b.length();
    save_a = new int [length1]{0};
    save_b = new int [length2]{0};
    product = new int [length1 + length2]{0};
    for(int i = 0 ; i < length1 ; ++i)
        save_a[i] = a[i] - '0';
    for(int i = 0 ; i < length2 ; ++i)
        save_b[i] = b[i] - '0';
    for(int i = 0 ; i < length1 ; ++i){
        for(int j = 0 ; j < length2 ; ++j){
            product[i+j] += save_a[i]*save_b[j];
        }
    }
    for(int i = 0 ; i < length1+length2 - 1 ; ++i){
        if (product[i] >= 10){
            product[i+1] += product[i]/10;
            product[i] %= 10;
        }
        answer += '0' + product[i];
    }
    if (product[length1+length2-1] != 0)
        answer += '0' + product[length1+length2-1];
    return answer;
}