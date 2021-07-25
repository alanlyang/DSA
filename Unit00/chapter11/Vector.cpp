//
// Created by 86185 on 2021/7/22.
//

#include "Vector.h"
#include "Vector.h"
#include "cmath"

// 将sin, cos ,atan2, cout 加入命名空间，这里只是为了复习命名空间的使用
using std::sin;
using std::cos;
using std::atan2; // arctan函数
using std::cout;

namespace VECTOR{
    const double Reg_to_deg = 57.2957796; //角度与弧度的转化 180/π
    void Vector::set_mag() {
        mag = sqrt(x*x+y*y); // 类方法可以直接访问类成员
    }; // 半径

    void Vector::set_ang() {
        if(x==0.0 && y==0.0){
            ang = 0.0;
        } else{
            ang = atan2(y,x);
        }
    }; // 角度

    void Vector::set_x() {
        x = mag * cos(ang);
    }

    void Vector::set_y() {
        y = mag * sin(ang);
    }

    Vector::Vector() {
        x = y = mag = ang = 0.0;
        mode = 'r';
    }

    Vector::Vector(double n1, double n2, char form) {
        mode = form;
        if(mode == 'r'){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if (mode == 'p'){
            mag = n1;
            ang = n2/Reg_to_deg;
            set_x();
            set_y();
        }else{
            cout << "Incorrect 3rd argument to Vector ----";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }

    void Vector::set(double n1, double n2, char form) {
        mode = form;
        if(mode == 'r'){
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }else if (mode == 'p'){
            mag = n1;
            ang = n2/Reg_to_deg;
            set_x();
            set_y();
        }else{
            cout << "Incorrect 3rd argument to Vector ----";
            cout << "Vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = 'r';
        }
    }

    // 析构函数，有需要可以自定义
    Vector::~Vector() {}

    void Vector::polar_mode() {
        mode = 'p';
    }
    void Vector::rect_mode() {
        mode = 'r';
    }

    // const 参数说明该函数不允许修改b
    Vector Vector::operator+(const Vector &b) const {
        return Vector(x+b.x, y+b.y, 'r');
    }
    Vector Vector::operator-(const Vector &b) const {
        return Vector(x-b.x, y-b.y,'r');
    }
    Vector Vector::operator-() const {
        return Vector(-x, -y, 'r');
    }
    Vector Vector::operator*(double n) const {
        return Vector(n*x, n*y);
    }

    //友元函数不用 ::
    Vector operator *(double n, const Vector &a){
        return a*n;
    }
    std::ostream & operator<<(std::ostream &os, const Vector &v){
        if(v.mode == 'r'){
            os << "(x,y) = " << "( " << v.x << "," << v.y << " )" << std::endl;
        } else if(v.mode == 'p'){
            os << "(mag, ang) = " << "( " << v.mag << "," << v.y << " )" << std::endl;
        }else{
            os << "Vector object mode is invalid";
        }
        return os;
    }
}
