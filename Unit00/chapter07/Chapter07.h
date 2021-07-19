//
// Created by 86185 on 2021/7/17.
//

#ifndef DSA_CHAPTER07_H
#define DSA_CHAPTER07_H


class Chapter07 {
public:
    struct travel_time {
        int hour;
        int mins;
    };

    int sum_arr(int arr[], int n);
    int sum_arr(int* begin, int*end); //此时不需要传递数组指针，因为begin对应的就是数组开始的位置
    int fill_array(double arr[], int limit);
    void show_array(const double arr[], int n); // 使用const说明不能使用arr指针来修改原始数组的值
    void re_value(double arr[], int n, double r);
    char* buildstr(char c, int n);
    travel_time sum_time(travel_time t1, travel_time t2);
    travel_time sum_time(travel_time* t1, travel_time *t2);
    void show_time(travel_time t);
    void sub_divide(char ar[], int low, int high, int level);
    static double betay(int lns);
    static double pam(int lns);
    void estimate(int lines, double (*pf)(int));

    void arr_fun1();
    void arr_fun3();
    void strg_back();
    void travel();
    void ruler();
    void fun_ptr();

};


#endif //DSA_CHAPTER07_H
