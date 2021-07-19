//
// Created by 86185 on 2021/7/15.
//

#include "Chapter05.h"
#include "iostream"

using namespace std;
void Chapter05::text_in_01() {
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;// 使用入口循环时必须先获取一个字符
    // 单引号表示字符，双引号表示字符串
    while (ch != '#'){
        cout << ch;
        count ++;
        // cin 在读取char值时省略空格和换行符， 可以使用cin.get代替
//        cin >> ch; //此时#后面的字符被缓冲
        cin.get(ch);// 默认是ch的引用类型
    }
    cout << endl << count << " characters read\n";

}


