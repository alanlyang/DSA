//
// Created by 86185 on 2021/7/26.
//

#ifndef DSA_BRASSPLUS_H
#define DSA_BRASSPLUS_H
#include "AcctABC.h"
class Brass:public AcctABC{
//private:
//    enum {MAX=35};
//    char full_name[MAX];
//    long acct_num; // 账号
//    double balance; // 余额
public:
    Brass(const char*s = "Nullbody", long an=-1, double bal=0.0): AcctABC(s,an, bal){};
//    void Deposit(double amt); // 存款
    virtual void Withdraw(double amt); // 取钱
//    double Balance()const; // 余额
    virtual void ViewAcct()const; // 查看账户
    virtual ~Brass(){} // 惯例为基类声明一个虚拟析构函数
};

class BrassPlus: public AcctABC{
private:
    double max_loan;// 最大额度
    double rate; // 利率
    double owes_bank; // 负债
public:
    BrassPlus(const char *s="Nullbody", long an=-1, double bal=0.0, double ml=500, double r=0.1);
    BrassPlus(const Brass & ba, double ml=500, double r=0.1);
    virtual void ViewAcct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m){ max_loan = m ;}
    void ResetRate(double r) { rate = r;}
    void ResetOwes(){ owes_bank = 0; }
};


#endif //DSA_BRASSPLUS_H
