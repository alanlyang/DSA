//
// Created by 86185 on 2021/7/22.
//

#ifndef DSA_VECTOR_H
#define DSA_VECTOR_H
#include <istream>

// 这里将类放在命名空间中
namespace VECTOR {
    class Vector {
    private:
        double x;
        double y;
        double mag;
        double ang;
        char mode; //'r' 代表直角系， 'p'代表极坐标系

        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, char form='r');
        void set(double n1, double n2, char form='r');
        ~Vector();
        //自动成为内联函数
        double x_val() {return x;}
        double y_val() {return y;}
        double mag_val() {return mag;}
        double ang_val() {return ang;}
        void polar_mode();
        void rect_mode();

        // operator overloading
        Vector operator+ (const Vector &b) const ;
        Vector operator- (const Vector &b) const;
        Vector operator-()const; // - 有两种重载，一种是反方向，一种是2元向量相减
        Vector operator*(double n) const;

        // friends
        friend Vector operator*(double n, const Vector & a);
        friend std::ostream & operator<<(std::ostream & os, const Vector & v);
    };
}

#endif //DSA_VECTOR_H
