//
// Created by 86185 on 2021/7/18.
//

#include "Chapter08.h"
#include "iostream"
using namespace std;

void Chapter08::swapv(int a, int b) {
    // 由于没有返回，因此在子函数交换后的值无法传递出去
    // a, b 是复制了实参的值进行交换，不会影响到实参
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void Chapter08::swapr(int &a, int &b) {
    // 引用变量交换后会影响到原函数中实参的值，
    // a,b相当于实参的别名，修改会引起实参值的改变
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void Chapter08::swapp(int *p, int *q){
    // 指针是一种引用，会对地址所指向的值进行交换
    // 但是要使用*操作符
    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}
void Chapter08::swaps() {
    int wallet1 = 300;
    int wallet2 = 350;

    cout << "wallet1 : $" << wallet1;
    cout << "\twallet2 : $" << wallet2 << endl;

    cout << "使用引用交换数据: \n";
    swapr(wallet1, wallet2);
    cout << "wallet1 : $" << wallet1;
    cout << "\twallet2 : $" << wallet2 << endl;

    cout << "使用指针交换数据: \n";
    swapp(&wallet1, &wallet2); // 再次交换，应该和原值相同
    cout << "wallet1 : $" << wallet1;
    cout << "\twallet2 : $" << wallet2 << endl;

    cout << "使用值交换数据: \n";
    swapv(wallet1, wallet2);
    cout << "wallet1 : $" << wallet1;
    cout << "\twallet2 : $" << wallet2 << endl;
}