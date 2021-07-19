//
// Created by 86185 on 2021/7/13.
//

#ifndef DSA_CHAPTER04_H
#define DSA_CHAPTER04_H
#include "cstring"
#include "iostream"

class Chapter04 {
public:
    void arrayone();
    void strings();
    void strtype1();
    void strtype3();
    void strtype4();
    void use_new();
    void array_new();
    void ptrstr();
    char* get_name(void){
        char temp[80];
        cout << "Enter last name: ";
        cin >> temp;

        char *pn = new char[strlen(temp)+1];
        strcpy(pn, temp);
        return pn;
    }
    void delete_name();
};


#endif //DSA_CHAPTER04_H
