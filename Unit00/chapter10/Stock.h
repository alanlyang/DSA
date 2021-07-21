//
// Created by 86185 on 2021/7/20.
//

#ifndef DSA_STOCK_H
#define DSA_STOCK_H

#include "iostream"
#include "cstring"
#include "string"

/**
 * 类声明通常不定义类函数的具体实现，
 * 只定义函数原型
 */
class Stock {
private:
    /**
     * 数据结构定义为： 公司名称，份额，每股价格，总价格
     */
    char company[30]; // 私有成员只能通过公有成员函数访问,也可以使用string类代替
    string m_cmp;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares*share_val; }

public:
//    Stock(); // 默认构造函数
    Stock(string cmp, int n, double pr); //构造函数没有返回类型
//    ~Stock(); // 析构函数

    void acquire(const char* co, int n, double pr);
    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    void show() const;
    const Stock & topval(const Stock & s) const; //返回一个Stock对象本身而不是其拷贝
};


#endif //DSA_STOCK_H
