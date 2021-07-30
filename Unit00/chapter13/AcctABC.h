//
// Created by 86185 on 2021/7/30.
//

#ifndef DSA_ACCTABC_H
#define DSA_ACCTABC_H

#include <ios>

using namespace std;

class AcctABC{
private:
    enum {MAX=35};
    char full_name[MAX];
    long acct_num;
    double balance;
protected:
    // 保护成员派生类可直接访问
    const char * FullName()const {return full_name;}
    long AcctNum()const {return acct_num;}
    std::ios_base::fmtflags SetFormat()const;

public:
    AcctABC(const char* s = "NullBody", long an=-1, double bal=0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0; // pure virtual function
    double Balance()const {return balance;}
    virtual void ViewAcct()const = 0;
    virtual ~AcctABC(){};
};

#endif //DSA_ACCTABC_H
