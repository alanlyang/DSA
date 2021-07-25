//
// Created by 86185 on 2021/7/21.
//

#ifndef DSA_MYTIME_H
#define DSA_MYTIME_H


class MyTime {
private:
    int hours;
    int minutes;

public:
    MyTime();
    MyTime(int h, int m=0);
    void add_min(int m);
    void add_hour(int h);
    void reset(int h=0, int m=0);
//    MyTime sum(const MyTime &t) const;
    MyTime operator + (const MyTime &t) const;
    void show() const;
    MyTime operator * (double n) const;
    friend MyTime operator* (double m, const MyTime &t){return t*m;}
    friend std::ostream & operator<< (std::ostream &os, const MyTime &t);
};


#endif //DSA_MYTIME_H
