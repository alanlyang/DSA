//
// Created by 86185 on 2021/7/20.
//

#include "Stock.h"

void Stock::acquire(const char *co, int n, double pr) {
    strncpy(company, co, 29); // 复制字符串的前n个字符
    company[29] = '\0'; // 类方法可以直接访问类的私有成员

    if(n<0){
        cerr << "Number of shares can't be negative "
             << company << " shares set to 0.\n";
        shares = 0;
    }
    else{
        shares = n;
    };
    share_val = pr;
    set_tot();
}
void Stock::buy(int num, double price) {
    if(num<0){
        std::cerr << "Number of shares can't be negative "
            << "Transaction is aborted \n";
    } else{
        shares += num;
        share_val = price;
        set_tot();
    }
}
void Stock::sell(int num, double price) {
    if(num<0){
        std::cerr << "Number of shares can't be negative "
                  << "Transaction is aborted \n";
    } else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}
void Stock::update(double price) {
    share_val = price;
    set_tot();
}
void Stock::show() const {
    cout << "Company: " << m_cmp << "\t Shares: " << shares << "\tPrice: "
         << share_val << "\t Total_value: " << total_val << endl;
}
Stock::Stock(string cmp, int n, double pr) {
//    strncpy(company, co, 29);
//    company[29] = '\0';
    m_cmp = cmp;
    if(n<0){
        cerr << "Number of shares can't be negative "
             << company << " shares set to 0.\n";
        shares = 0;
    } else{
        shares = n;
    }
    share_val = pr;
    set_tot();
}
const Stock & Stock::topval(const Stock &s) const {
    if(s.total_val > this->total_val){
        return s;
    }else{
        return *this;
    }
}