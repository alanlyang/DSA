//
// Created by 86185 on 2021/7/19.
//

#include "Chapter09.h"
#include "iostream"
#include <new>

using namespace std;
double warming = 0.3;
void Chapter09::update(double dt) {
    extern double warming; //声明使用外部变量, 该句可以省略，因为全局变量全局生效
    warming += dt;
    cout << "Updating global warming to " << warming << endl;
}
void Chapter09::local() {
    double warming = 0.8;
    cout << "Local warming = " << warming << "\n";
    cout << "But global warming = " << ::warming;
}
void Chapter09::external() {
    cout << "global warming is " << warming << endl;
    update(0.1);
    cout << "global warming is " << warming << endl;
    local();
    cout << "global warming si " << warming <<endl;
}

void use_new(){

}
void Chapter09::new_place() {
    const int BUF = 512;
    const int N = 5;
    char buffer[BUF];

    double *pd1, *pd2;
    int i;

    cout << "Calling new and palcement new:\n";
    pd1 = new double [N]; //分配N个double的内存
    pd2 = new (buffer) double[N]; // 在buffer中分配N个double的内存
    for(i=0; i<N; i++){
        pd2[i] = pd1[i] = 1000 + 20.0*i;
    }

    cout << "Buffer addresses:\n"
         << " heap: " << pd1  <<"\tstatic: " << (void*)buffer << endl; //void*表示任意类型指针
    cout << "Buffer contents: \n";
    for(i=0; i<N; i++){
        cout << pd1[i] << " at " << &pd1[i] << ";\t";
        cout << pd2[i] << " at " << &pd2[i] <<endl;
    }
    cout << "======================================\n";

    cout << "\n Calling new and placement new a second time: \n";
    double *pd3, *pd4;
    pd3 = new double [N];
    pd4 = new (buffer) double [N];
    for(i=0; i<N; i++){
        pd4[i] = pd3[i] = 1000+20*i;
    }
    cout << "Buffer contents: \n";
    for(i=0; i<N; i++){
        cout << pd3[i] << " at " << &pd3[i] << ";\t";
        cout << pd4[i] << " at " << &pd4[i] <<endl;
    }
    cout << "======================================\n";

    cout << "\n Calling new and placement new a third time: \n";
    delete [] pd1;
    pd1 = new double [N];
    pd2 = new (buffer + N*sizeof(double)) double [N];//新建一个大小为buffer+N*double的内存（为在buffer后追加？）
    for(i=0; i<N; i++){
        pd2[i] = pd1[i] = 1000+20*i; // 此时pd1已经被释放并新建
    }
    cout << "Buffer contents: \n";
    for(i=0; i<N; i++){
        cout << pd1[i] << " at " << &pd1[i] << ";\t";
        cout << pd2[i] << " at " << &pd2[i] <<endl;
    }
    delete[] pd1;
    delete[] pd3; //TODO 为什么不释放pd2和pd4 --> buffer指定的内存为静态内存，而delete只能用于堆内存
}