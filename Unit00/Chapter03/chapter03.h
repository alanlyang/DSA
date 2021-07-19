//
// Created by 86185 on 2021/7/12.
//

#include "iostream"

using namespace std;

class Chapter03 {
public:
    void morechar(){
      char ch = 'M'; // char类型不仅可以标识字符类型也可以标识小整数
      int i = ch;
      cout << "The Ascii code for " << ch << " is " << i << endl;

      cout << "Add one to the charter code: " << endl;
      ch += 1;
      i = ch;
      cout << "Now the code for "<< ch << " is " << i << endl;

      // using the cout.put() to display a char
      cout << "Display char ch using cout.put(): ";
      cout.put(ch);

      // using cout.put() to display a char constant
      // 这里put的字符串只用用单引号，双引号标识字符串，参数不合法
      cout.put('!');

      cout << "\n Done! \n";
    };
    void bondini(){
        cout << "\aOperation \"HyperHype\" is now activated \n";
        cout << "Enter you agent code: _____ \b\b\b\b\b";
        long code ;
        cin >> code;

        cout << "\aYou entered " << code << ".....\n";
        cout << "\a Code verified ! \n";
    };
    void floatnum(){
        // 强迫使用定点表示法
        cout.setf(ios_base::fixed, ios_base::floatfield);
        float tub = 10.0/3.0; // float 默认是6位精确位
        double mint = 10.0/3.0; // double 默认15位精确位
        const float million = 1.0e6;

        cout << "tub = " << tub;
        cout << ", a million tubs = " << million * tub;
        cout << ", \n and ten million tubs = " << 10 * million * tub << endl;

        cout << "mint = " << mint << " and a million mints = " << million * mint << endl;
    }
};

