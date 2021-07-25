//
// Created by 86185 on 2021/7/25.
//

#include "StringBad.h"
#include "cstring"

using namespace std;

int StringBad::num_strings = 0; //
// 不能再类声明中初始化，因为类声明仅描述如何分配内存，但不分配内存
// 除非静态成员是整型或枚举型const

StringBad::StringBad(const char *s) {
    len = strlen(s); // 参数为一个指针,而不是*s
    str = new char[len+1]; // 字符串不保存在对象中，字符串单独保存在堆内存中，对象仅保存了字符串的地址信息
    strcpy(str, s); // 不能 str = s, s 只是一个地址
    num_strings ++;
    cout << num_strings << " object(s) created \n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    strcpy(str, "c++"); // default string
    num_strings ++;
    cout << num_strings<< " " << str << "default object(s) created \n";
}

StringBad::~StringBad() {
    cout << "\"" << str << "\" object deleted ";
    num_strings--;
    cout << num_strings << " left \n";
    delete [] str;
}

ostream & operator << (ostream & os, const StringBad & st){
    os << st.str;
    return os;
}

void callme1(StringBad & rsb){
    cout << "String passed by reference: ";
    cout << "\t \"" << rsb << "\"\n";
}
void callme2(StringBad sb){ // 将类对象作为参数传递将导致析构函数被调用
    cout << "String passed by value: \t" << "\"" << sb << "\"\n";
}