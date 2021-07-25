//
// Created by 86185 on 2021/7/9.
//

#include "iostream"
#include <cstdlib>
#include <ctime>
using namespace std;

//#include "Unit00/Chapter03/chapter03.h"
//#include "cfloat"
#include "chapter04/Chapter04.cpp"
#include "chapter05/Chapter05.cpp"
#include "chapter06/Chapter06.cpp"
#include "chapter07/Chapter07.cpp"
//#include "chapter08/Chapter08.cpp"
#include "chapter09/Chapter09.cpp"
#include "Unit00/chapter10/Stock.cpp"
#include "Unit00/chapter11/Mytime.cpp"
#include "Unit00/chapter11/Vector.cpp"

void rand_walk(){
    using VECTOR::Vector;
    srand(time(0)); // 随机种子,time(0)返回当前的时间
    double direction;
    Vector step;
    Vector result(0.0, 0.0, 'r');
    unsigned long steps = 0;
    double target, dstep;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target){
        cout << "Enter step length: ";
        if(!(cin >> dstep)){
            break;
        }
        while(result.mag_val() < target){
            direction = rand() % 360; // 前进方向
            step.set(dstep, direction, 'p');
            result = result + step; // 两个向量相加
            steps ++;
        }

        // 直交系结果和极坐标系
        cout << "After " << steps << " steps, the subject has the following location:";
        cout << result ;
        result.polar_mode();
        cout << " or " << result << endl;

        cout << "Average outward distance per step = " << result.mag_val()/steps << endl;
        result.set(0.0, 0.0);
    }
    cout << "Done!\n";
}

int main(){
//    rand_walk();
//    Chapter09 chapter09;
//    chapter03.morechar();
//    chapter03.bondini();
//    chapter03.floatnum();
//    chapter04.arrayone();
//    chapter04.delete_name();
//    chapter05.text_in_01();
//    chapter06.cin_golf();
//    chapter09.new_place();
//    Stock alan("Tencent", 500, 23);
//    alan.acquire("Alibaba", 10000, 0.5);
//    alan.show();
//    MyTime time0;
//    MyTime time1 = {10, 20};
//    MyTime time2 = {1, 55};
//    MyTime total;
//
//    cout << "time0: " ;
//    time0.show();
//    cout << "time1: ";
//    time1.show();
//    cout << "time2: ";
//    time2.show();
//
//    total = time1 + time2;
//    cout << total;
//    total.show();


    return 0;

}
