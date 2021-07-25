//
// Created by 86185 on 2021/7/25.
//

#ifndef DSA_STRINGBAD_H
#define DSA_STRINGBAD_H
#include <iostream>
using namespace std;

class StringBad {
private:
    char *str; // pointer to string
    int len; // length of string
    static int num_strings; // number of objects
    /**
     * 无论创造了多少个类对象，程序都只创建一个静态变量的副本
     * 类的所有对象共享一个静态成员
     * **/

public:
    StringBad(const char * s);
    StringBad();
    ~StringBad();

    friend ostream & operator<<(ostream &os, const StringBad & st); // 操作符重载必须至少有一个参数类型是类类型
};


#endif //DSA_STRINGBAD_H
