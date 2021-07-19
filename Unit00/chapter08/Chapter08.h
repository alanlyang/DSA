//
// Created by 86185 on 2021/7/18.
//

#ifndef DSA_CHAPTER08_H
#define DSA_CHAPTER08_H


class Chapter08 {
public:
    struct sysop{
        char name[26];
        char quote[64];
        int used;
    };
    struct job{
        char name[40];
        double salary;
        int floor;
    };

    void swapr(int &a, int &b );
    void swapp(int *p, int *q);
    void swapv(int a, int b);
    void swaps();

    const sysop &use(sysop &sysopref);
    void strtref();

    void file_it(ostream &os, double fo, const double fe[], int n);
    void file_func();

    //模板函数
    template<class Any>
    void Swap(Any &a, Any &b);
    //模板显式具体化
    template <> void Swap(job &j1, job &j2); //编译无法使用时只能定义为常规函数

    void show(job &j);
    void two_swap();


};


#endif //DSA_CHAPTER08_H
