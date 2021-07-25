//
// Created by 86185 on 2021/7/21.
//

#include "MyTime.h"
#include <iostream>

using namespace std;

// 默认构造行数
MyTime::MyTime() {
    hours = minutes = 0;
}
MyTime::MyTime(int h, int m) {
    hours = h;
    minutes = m;
}

// 功能函数
void MyTime::add_hour(int h) {
    hours += h;
}
void MyTime::add_min(int m) {
    minutes += m;
    hours += (minutes / 60);
    minutes = minutes % 60;
}
void MyTime::reset(int h, int m) {
    hours = h;
    minutes = m;
}
//返回的是一个复制的对象
//MyTime MyTime::sum(const MyTime &t) const {
//    MyTime s_time;
//    s_time.minutes = minutes + t.minutes;
//    s_time.hours = hours + t.hours + s_time.minutes/60;
//    s_time.minutes %= 60;
//    return s_time;
//}
/** 使用操作符重载来替换sum 函数使得更加符合用户逻辑 **/
MyTime MyTime::operator+(const MyTime &t) const {
    MyTime s_time;
    s_time.minutes = minutes + t.minutes;
    s_time.hours = hours + t.hours + s_time.minutes/60;
    s_time.minutes %= 60;
    return s_time;
}
MyTime MyTime::operator*(double n) const {
    MyTime result;
    long totalminutes = hours * n * 60 + minutes * n;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return  result;
}
ostream & operator<<(ostream & os, const MyTime & t){
    os << t.hours << " hours " << t.minutes << " minutes ";
    return os;
}
void MyTime::show() const {
    cout << hours << " hours " << minutes << " minutes " << endl;
}