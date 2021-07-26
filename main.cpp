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
#include "Unit00/chapter12/StringBad.cpp"
#include "Unit00/chapter12/Queue.cpp"
#include "Unit00/chapter12/Consumer.cpp"

void chapter11_rand_walk(){
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
void chapter12_veg_news(){
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl of Dollars");
    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    callme1(headline1);
    cout << "headline1: " << headline1 << endl;
    callme2(headline2);
    cout << "headline2: " << headline2 << endl;
    cout << "Initialize one object of another: \n";
    StringBad sailor = sports;
    cout << "sailor: " << sailor << endl;
    cout << "Assign one object to another: \n";
    StringBad knot;
    knot = headline1;
    cout << "knot: " << knot << endl;
    cout << "Done!" << "\n" << "开始调用析构函数\n";
}
void chapter12_bank(){
    const int MIN_PER_HR = 60;
    cout << "Case Study: Bank of Heather Automatic Teller \n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cycle_limit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double per_hour;
    cin >> per_hour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR/per_hour; //仿真时间间隔

    Item temp;
    long turn_aways = 0;//等候人数
    long customers = 0; //队列中的人数
    long served = 0; // 已服务完的人数
    long sum_line = 0; //累计队列长度
    int wait_time = 0; // 等待时间
    long line_wait = 0; //累计服务时间

    // run the simulation
    for(int cycle=0; cycle<cycle_limit; cycle++){
        if(new_customer(min_per_cust)){
            if(line.is_full())
                turn_aways++;
            else{
                customers++;
                temp.set(cycle);
                line.en_queue(temp);
            }
        }
        if(wait_time<=0 && !line.is_empty()){
            line.de_queue(temp);//dequeue会修改temp的值
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if(wait_time > 0){
            wait_time --;
        }
        sum_line += line.queue_count();
    }

    //report results
    if(customers > 0){
        cout << "Customers accepted: " << customers << endl;
        cout << "Customers served  : " << served <<endl;
        cout << "Turn aways        : " << turn_aways << endl;
        cout << "Average Queue Size: " ;
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout.setf(ios_base::showpoint);
        cout << (double)sum_line/cycle_limit << endl;
        cout << "Average wait time : ";
        cout << (double)line_wait/served << " minutes\n";
    } else
        cout << "No customers!\n";
    cout << "Done! \n";
}

//int _main(){
//    while(true){
//        char q;
//        cin >> q;
//        if(q=='q') break;
//        chapter12_bank();
//    }
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


//    return 0;
//
//}
