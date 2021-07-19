//
// Created by 86185 on 2021/7/17.
//

#include "Chapter07.h"
#include "iostream"
using namespace std;

int Chapter07::sum_arr(int *arr, int n) {
    int total = 0;
    for(int i=0; i<n; i++){
        total += arr[i];
    }
    return total;
}
int Chapter07::sum_arr(int *begin, int *end) {
    const int* pt; //pt 指向一个const int 类型，即不能通过*pt修改数组的值
    int total = 0;
    for(pt=begin; pt<end; pt++){
        total += *pt;
    }
    return total;
}
void Chapter07::arr_fun1() {
    const int ArrSize = 8;
    int cookies[ArrSize] = {1, 2, 4, 8, 16,32,64,128};
    int sum = sum_arr(cookies, ArrSize);
    cout << "Total cookies eaten: " << sum << endl;
}

int Chapter07::fill_array(double *arr, int limit) {
    double temp;
    int i;

    for (i = 0; i < limit; i++) {
        cout << "Enter the value # " << i+1 << ": ";
        // 异常处理，输入不合法时提示重新输入
        while (!(cin >> temp)) {
            cin.clear(); // 清空输入缓冲
            while (cin.get() != '\n') continue;
            cout << "Bad input, Please re-input #" << i + 1 << ": ";
        }
        if (temp < 0) break; //终止信号
        arr[i] = temp;
    }
    return i;
}
void Chapter07::show_array(const double *arr, int n) {
    for(int i=0; i<n; i++){
        cout << "arr[" << i << "]:\t" << arr[i] << endl;
    }
}
void Chapter07::re_value(double *arr, int n, double r) {
    //这里r为增长比率
    for(int i=0; i<n; i++){
        arr[i] *= r;
    }
}
void Chapter07::arr_fun3() {
    const int Max = 5;
    double arr[Max];
    double new_value;

    // 填充数组, fill_array中应当含有初始化逻辑
    int size = fill_array(arr, Max);
    show_array(arr, size);

    //
    cout << "Enter the new value: ";
    cin >> new_value;

    // re_value中应当含有字符串分隔处理的逻辑
    re_value(arr, size, new_value);
    show_array(arr, size);
    cout << "Done!" << endl;
}

char * Chapter07::buildstr(char c, int n) {
    char* pstr = new char[n+1];
    pstr[n] = '\0';
    while(n-- > 0) pstr[n]=c;
    return pstr;
}
void Chapter07::strg_back() {
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter the number: ";
    cin >> times;

    char *ps = buildstr(ch, times);
    cout << ps << endl; //cout 在遇到字符串指针时会自动输出其值,使用*ps反而只会输出第一个字母
    ps = buildstr('+', 20);
    cout << ps << "--Done--" << endl;
    delete [] ps;
}

Chapter07::travel_time Chapter07::sum_time(travel_time t1, travel_time t2) {
    travel_time total;
    total.mins = (t1.mins + t2.mins) % 60;
    total.hour = t1.hour + t2.hour + (t1.mins + t2.mins) / 60;
    return total;
}
Chapter07::travel_time Chapter07::sum_time(travel_time *t1, travel_time *t2) {
    travel_time total;
    total.mins = (t1->mins + t2->mins) % 60;
    total.hour = t1->hour + t2->hour + (t1->mins + t2->mins) / 60;
    return total;
}
void Chapter07::show_time(travel_time t) {
    cout << t.hour << ":" << t.mins << endl;
}
void Chapter07::travel() {
    travel_time t1 = {12, 30};
    travel_time t2 = {3,45};

    travel_time total = sum_time(&t1, &t2);
    show_time(total);
}

void Chapter07::sub_divide(char *ar, int low, int high, int level) {
    if(level == 0) return; // 递归出口
    int mid = (high + low) / 2;
    ar[mid] = '|'; //改写中间位置字符
    sub_divide(ar, low, mid, level-1); //level可以理解为递归次数
    sub_divide(ar, mid, high, level-1);
}
void Chapter07::ruler() {
    const int Len = 66;
    const int Divs = 6;

    char ruler[Len];
    int i;

    // 字符串初始化为空格串
    for(i=1; i<Len-2; i++) ruler[i]=' ';
    ruler[Len-1] = '\0';
    int max = Len-2; //最后一个字符串为空字符串
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;
    for (i=1; i<=Divs; i++){
        sub_divide(ruler,min,max,i);
        cout << ruler << endl;
        //重置ruler
        for(int j=1; j<Len-2; j++){
            ruler[j] = ' ';
        }
    }
}

double Chapter07::betay(int lns) {
    return 0.05 * lns;
}
double Chapter07::pam(int lns) {
    return 0.03*lns + 0.0004*lns*lns;
}

//相当于Python中的装饰器
void Chapter07::estimate(int lines, double(*pf)(int)) {
    cout << lines << " lines will take" ;
    cout << (*pf)(lines) << " hours\n";
}

void Chapter07::fun_ptr() {
    int code;

    cout << "How many lines of code do you need?" ;
    cin >> code;
    cout << "Here's Betay's estimate:\n";
    estimate(code, betay);
    cout << "Here's Pam's estimate: \n";
    estimate(code, pam);
}