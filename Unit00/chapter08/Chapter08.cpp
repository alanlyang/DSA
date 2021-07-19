//
// Created by 86185 on 2021/7/18.
//

#include "Chapter08.h"
#include "iostream"
#include "fstream"
#include "cstdlib"
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

const Chapter08::sysop & Chapter08::use(sysop &sysopref) {
    // const意味着不能使用返回的引用来修改looper中的值,如use(copycat).used = 10
    cout << sysopref.name << " says: \t";
    cout << sysopref.quote << endl;
    sysopref.used ++; //每调用一次，原结构变量增加1
    return sysopref; // 返回原结构
}
void Chapter08::strtref() {
    sysop looper = {
            "Rick Fortran Looper",
            "I'm a goto kind of guy.",
            0
    };

    use(looper);
    cout << "Looper: " << looper.used << " use(s)\n";

    sysop copycat;
    copycat = use(looper); //返回的函数looper结构变量
    cout << "Looper: " << looper.used << " use(s)\n"; // 此时输出应该相同
    cout << "Copycat: " << copycat.used << "use(s)\n";
    cout << "Use(looper): " << use(looper).used << "use(s)\n"; // 第三次调用时只改变looper的值，不改变Copycat的值
    cout << "Now copycat: " << copycat.used << "use(s)\n";
}

void Chapter08::file_it(ostream &os, double fo, const double *fe, int n) {
    ios_base::fmtflags initial; // 存储io设置的数据类型
    initial = os.setf(ios_base::fixed); // 保留原始输入格式,即用定点表示法
    os.precision(1); // 精确到小数点后1位
    os << "Focal length of objective " << fo << "mm\n";
    os.setf(ios_base::showpoint); //写浮点值时总是保留小数点
    os.width(12);
    os << "f eyepiece";
    os.width(15);
    os << "magnification " << endl;
    for(int i=0;i<n;i++){
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int (fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);
}
void Chapter08::file_func() {
    const int LIMIT = 5;
    ofstream fout;
    const char *fn = "./chapter08.txt";

    fout.open(fn);
    if(!fout.is_open()){
        cout << "Can't open " << fn << endl;
        exit(EXIT_FAILURE);
    }

    // 读取物距
    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;

    // 读取目距
    double eps[LIMIT];
    cout << "Enter the focal length in mm of " << LIMIT << "eyepieces: \n";
    for(int i=0; i<LIMIT; i++){
        cout << "Eyepiece #" << i+1 << ": ";
        cin >> eps[i];
    }

    // 参数os即可指向 ofstream对象也可以指向cout
    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done!";
}

template <typename Any>
void Chapter08::Swap(Any &a, Any &b) {
    Any temp;
    temp = a;
    a = b;
    b = temp;
}
//显式具体化函数
template <> void Chapter08::Swap(job &j1, job &j2){
    job temp;
    temp = j1;
    j1.floor = j2.floor;
    j1.salary = j2.salary;
    j2.floor = temp.floor;
    j2.salary = temp.salary;
}
void Chapter08::show(job &j) {
    cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}
void Chapter08::two_swap() {
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);
    int i=10, j=20;
    cout << "i,j:\t" << i << "\t" << j << endl;
    cout << "Using compiler-generated int swapper: \n";
    Swap(i, j);
    cout << "Now i,j:\t" << i << "\t" << j << endl;

    job sue = { "Alan", 100, 2};
    job sid = {"arya", 200, 3};
    cout << "Before Swap: \n";
    show(sue);
    show(sid);
    Swap(sue,sid);
    cout << "After Swap: \n";
    show(sue);
    show(sid);

}