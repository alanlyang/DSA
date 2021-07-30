//
// Created by 86185 on 2021/7/26.
//

#include "BrassPlus.h"
#include "cstring"
#include "iostream"
using namespace std;

Brass::Brass(const char *s, long an, double bal) {
    strncpy(full_name, s, MAX-1);
    full_name[MAX] = '\0';
    acct_num = an;
    balance = bal;
}

/** 存款函数 **/
void Brass::Deposit(double amt) {
    if(amt < 0){
        cout << "Negative deposit not allowed: "
        << "deposit is cancelled \n";
    }else{
        balance += amt;
    }
}

/** 取款函数 **/
void Brass::Withdraw(double amt) {
    if(amt < 0){
        cout << "Withdrawal amount must be positive: "
        << "withdrawal cancelled \n";
    }else if(amt <= balance){
        balance -= amt;
    }else
        cout << "Withdrawal amount of " << amt << "exceeds your balance\n"
             << "Withdrawal cancelled" << "余额不足 \n";
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    //set up ###.## format
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    cout << "Client:  " << full_name << endl;
    cout << "Account: " << acct_num << endl;
    cout << "Balance: " << balance << endl;

    cout.setf(initialState);
}

/** 创建派生类对象时，编译器会先生成基类对象 **/
BrassPlus::BrassPlus(const char *s, long an, double bal, double ml, double r): Brass(s,an, bal) {
    max_loan = ml;
    owes_bank = 0.0;
    rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r): Brass(ba){
    max_loan = ml;
    owes_bank = 0.0;
    rate = r;
}
void BrassPlus::ViewAcct() const {
    //set up ###.## format
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    // 派生类只能使用基类的公有函数来访问基类的成员变量
    Brass::ViewAcct();
    cout << "Maximum loan: $ " << max_loan << endl;
    cout << "Owed to bank: $" << owes_bank << endl;
    cout << "Loan rate   : " << rate * 100 << "%\n";
    cout.setf(initialState);
}
void BrassPlus::Withdraw(double amt) {
    //set up ###.## format
    ios_base::fmtflags initialState = cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);

    // 只能通过公有方法访问基类的成员
    double bal = Balance();
    if(amt <= bal){
        Brass::Withdraw(amt);
    }else if(amt <= bal+max_loan - owes_bank){
        double advance = amt - bal; // 预支额度,为负数
        owes_bank += advance * (1.0 + rate);
        cout << "Bank advanced: $" << advance << endl;
        cout << "Finance charge: $" << advance*rate << endl; // 利息
        Deposit(advance);// 余额增加一个负数.只能通过公有函数访问基类成员
        Brass::Withdraw(amt);
    }else{
        cout << "Credit limit exceed. Transaction cancelled \n";
    }
    cout.setf(initialState);
}

int main1(){
    Brass Piggy("Project Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << "\n";
    Hoggy.ViewAcct();
    cout << "\n";

    cout << "Depositing 1000 into the Hoggy Account \n";
    Hoggy.Deposit(1000);
    cout << "Hoggy Deposit: " << Hoggy.Balance() << endl; // 派生类课调用基类方法
    cout << "Withdrawing 4200 from the Piggy Account \n";
    Piggy.Withdraw(4200);
    cout << "Piggy Account balance: " << Piggy.Balance() << endl;
    cout << "Withdraw 4200 from the Hoggy Account \n";
    Hoggy.Withdraw(42-00);
    Hoggy.ViewAcct();
    return 0;
}
int main(){
    // 使用指针来将Brass和BrassPlus对象放入同一个数组中
    const int CLIENTS = 4;
    const int LEN = 40;
    Brass* p_clients[CLIENTS];

    int i;
    for(i=0; i<CLIENTS; i++){
        char temp[LEN];
        long temp_num;
        double temp_bal;
        char kind;
        cout << "Enter client's name: ";
        cin.getline(temp, LEN);
        cout << "Enter opening balance: ";
        cin >> temp_bal;
        cout << "Enter 1 for Brass Account or 2 for BrassPlus Account(q to quit): ";
        cin >> kind;
        if(kind=='q') break;
        if(kind == '1'){
            p_clients[i] = new Brass(temp, temp_num, temp_bal);
        }else{
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            p_clients[i] = new BrassPlus(temp, temp_num, temp_bal, tmax, trate);
        }
        while(cin.get()!='\n') continue; // 清空输入缓存
    }
    cout << endl;
    for(i=0; i<CLIENTS; i++){
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    for(i=0; i<CLIENTS; i++){
        delete p_clients[i]; // 调用new分配内存，必须调用delete释放内存
    }
    cout << "Done !";
    return 0;
}