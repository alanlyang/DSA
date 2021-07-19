//
// Created by 86185 on 2021/7/16.
//

#include "Chapter06.h"
#include "iostream"
#include "cctype"
#include "string"
#include "stdlib.h"

using namespace std;

void Chapter06::cctypes() {
    cout << "Enter text for analysis and type @ to terminal input \n";

    char ch;
    string str[5] = {"whitespace", "digit", "alpha", "punct", "others"};
    int counter[5] = {0, 0, 0, 0, 0}; //用数组来做不同类型的计数器

    cin.get(ch);
    while(ch != '@'){
        if(isspace(ch)) { counter[0]++; }
        else if(isdigit(ch)) counter[1]++;
        else if(isalpha(ch)) counter[2]++;
        else if(ispunct(ch)) counter[3]++;
        else counter[4]++;

        cin.get(ch);
    }
    for(int i=0; i<5; i++){
        cout << str[i] << " : " << counter[i] << endl;
    }
}
void Chapter06::cinfish() {
    const int Max = 5;

    double fish[Max];
    cout << "Please input teh weights of you fish \n";
    cout << "You may enter up to " << Max << " fish < q to terminate> \n";
    cout << "fish #1: ";

    // 获取输入信息
    int i = 0;
    while (i<Max && cin>>fish[i]){
        if(++i < Max)
            cout << "fish #" << i+1 << ": ";
    }

    // 计算平均重量
    double total = 0.0;
    for (int j=0; j<i; j++){
        total += fish[j];
    }

    // 输出结果
    if (i==0) {
        cout << "no fish \n";
    }
    else{
        cout << total/i << " = average weight of " << i << " fish \n";
    }

}
void Chapter06::cin_golf() {
    const int Max = 5;
    double golf[Max];
    cout << "Please enter you golf scores\n";

    int i = 0;
    char ch;
    while (i<Max){
        cout << "round #" << i+1 << " :";
        //写入失败时的异常处理
        cin >> ch;
        if(ch=='q') break;
        while(!(isdigit(ch))){
            cin.clear();
            while(cin.get() != '\n') {};
            cout << "Please input a number: ";
            cout.precision();
        }
        golf[i] = ch - '0';
        i++;
    }

    double total = 0.0;
    for(int j=0; j<i; j++){
        total += golf[j];
    }
    cout << total << endl;
    cout << i << endl;

    cout << total/i << "= average score " << i << " rounds";
}