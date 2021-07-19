//
// Created by 86185 on 2021/7/13.
//

#include "Chapter04.h"
#include "cstring"
#include "string"
using namespace std;

void Chapter04::arrayone() {
    // Create and Initialize array
    int yams[3] = {7, 8, 6};
    int yamcosts[3] = {20, 30, 5};

    cout << "Total yams = ";
    cout << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs ";
    cout << yamcosts[1] << "cents per yam.\n";

    int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
    total = total + yams[2]*yamcosts[2];

    cout << "The total yam expense is " << total << " cents.\n";
    cout << "Size of yams array is " << sizeof yams << endl;
    cout << "Size of one element is " << sizeof yams[0] << " bytes \n";
}
void Chapter04::strings() {
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++boy";
    char name3[Size] ;

    cout << "What's your name ? \n";
    cin >> name1; // cin 使用空格来界定字符串的界, 如果想要整行的读取，需要使用cin.getline()或 cin.get()函数
    cout << "Well, " << name1 << ", you name has ";
    cout << strlen(name1) << " letters and is stored \n";
    cout << "in an array of " << sizeof(name1) << " bytes \n";
    cout << "Your initial is " << name1[0] << endl;

    name2[3] = '\0'; // 注意字符常量使用单引号
    cout << "Here are the first 3 characters of my name: ";
    cout << name2 << "\n";

    cin >> name3; // 此时如果前面输入为alan yang,则name3会直接输出yang
    cout << "name3 is : " << name3 << endl;
}
void Chapter04::strtype1() {
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline: ";
    cin >> charr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;
    cout << "Here are some felines : \n";
    cout << charr1 << " " << charr2 << " "
         << str1 << " " << str2 << endl;
    cout << "The third letter in " << charr2 << "is "
        << charr2[2] << endl;
    cout << "The third letter in " << str2 << " is "
        << str2[2] << endl;
    cout << str1.length();
}
void Chapter04::strtype3() {
    char charr1[20];
    char charr2[20] = "jaquar";
}
void Chapter04::strtype4() {
    char charr[20];
    string str;

    cout << "Length of string in charr before input: " << strlen(charr) <<endl;
    cout << "Length of string in str before input: " << str.size() << endl;

    cout << "Enter a line of text: \n";
    cin.getline(charr, 20);
    cout << "You entered: " << charr << " \n";

    cout << "Enter another line of text: \n";
    getline(cin, str); // cin now an argument; no length specifier
    cout << "You entered : " << str << endl;

    cout << "Length of string in charr after input: " << strlen(charr) << endl;
    cout << "Length of string in str after input: " << str.size() << endl;


}
void Chapter04::use_new() {
    int *pt = new int;
    *pt = 1001;

    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt <<endl;

    double *pd = new double;
    *pd = 100000001.0;

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;

    cout << "size of pt = " << sizeof(pt) << endl;
    cout << "size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd =" << sizeof(pd) << endl;
    cout << "size of *pd =" << sizeof(*pd) << endl;
}
void Chapter04::array_new() {
    //分配三个double的数组连续内存
    double *p3 = new double [3];

    //数组初始化
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    // 此时p3指向数组的第一个元素
    cout << "p3: " << p3 << endl;
    cout << "p3[1] is " << p3[1] << endl;

    // 指针自增
    p3 += 1; /** 这里自增后地址增加了8个字节，也就是说这里的指针自增不是地址绝对值的自增，
              ** 而是指正指向元素的自增，即增加了一个double的数量
              * 这里涉及到的是指针的运算 **/
    cout << "p3:" << p3 << endl;
    cout << "Now p3[0] is " << p3[0] << " and "
         << "p3[1] is " << p3[1] << endl;

    //重新指向第一个元素
    p3 -= 1;
    cout << "p3: " << p3 << endl;

    // 释放内存
    delete [] p3;
}
void Chapter04::ptrstr() {
    // 对字符串数组的声明也可以用string类
    char animal[20] = "bear";
    // bird 是指向字符串的指针
    const char *bird = "wren";
    char *ps;

    cout << animal << " and " << bird << "\n";
    // ps 的地址为随机地址
    //cout << (int*)ps << endl;

    cout << "Enter a kind of animal: ";
    cin >> animal;
    // cin >> ps 不行，因为系统没有为ps分配任何的内存

    // 此时ps 指向输入的字符串
    ps = animal;
    cout << ps << "s!\n";

    cout << "Before using strcpy(): \n";
    // 这里作强制类型转换是因为当cout接受一个char*类型的时候，会默认打印字符串。因此需要作
    // 强制类型转换来打印地址信息
    cout << animal << " at " << (int*)animal <<endl;
    cout << ps << " at " << (int*) ps << endl;

    // 给ps分配新的内存，+1是为了存储\0的字符
    ps = new char[strlen(animal)+1];
//    ps = animal; 如果这样赋值，那么新分配的内存将无法访问也无法释放，造成内存泄漏
//    cout << ps << endl;
    strcpy(ps, animal);

    cout << "After using strcpu(): \n";
    cout << animal << " at " << (int*)animal << endl;
    cout << ps << " at " << (int*)ps << endl;
    delete [] ps;
}
void Chapter04::delete_name() {
    char* name;
    for(int i=0; i<5; i++) {
        name = get_name();
        cout << name << " at " << (int *) name << endl;
        delete[] name;
    }
}