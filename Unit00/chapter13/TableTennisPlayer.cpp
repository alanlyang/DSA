//
// Created by 86185 on 2021/7/26.
//
#include "iostream"
#include "cstring"
#include "TableTennisPlayer.h"
using namespace std;

TableTennisPlayer::TableTennisPlayer(const char *fn, const char *ln, bool ht) {
    strncpy(first_name, fn, LIM-1); // 不能用first_name = fn, 这样只是复制了fn的地址
    first_name[LIM-1] = '\0';
    strncpy(last_name, ln, LIM-1);
    last_name[LIM-1] = '\0';
    has_table = ht;
}

void TableTennisPlayer::Name() const {
    cout << first_name << " " << last_name;
}

//int _main(){
//    TableTennisPlayer player1("Alan", "lyang", true);
//    TableTennisPlayer player2("Arya", "lpei", false);
//    player1.Name();
//    if(player1.hasTable())
//        cout << ": has a table\n";
//    else
//        cout << ": hasn't a table \n";
//
//    player2.Name();
//    if(player2.hasTable())
//        cout << ": has a table\n";
//    else
//        cout << ": hasn't a table \n";
//}