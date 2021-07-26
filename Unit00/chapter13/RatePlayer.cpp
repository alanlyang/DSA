//
// Created by 86185 on 2021/7/26.
//

#include "RatePlayer.h"
#include "iostream"
using namespace std;

RatePlayer::RatePlayer(unsigned int r, const char *fn, const char *ln, bool ht): TableTennisPlayer(fn, ln, ht) {
    rating = r;
}
RatePlayer::RatePlayer(unsigned int r, const TableTennisPlayer &tp): TableTennisPlayer(tp) {
    rating = r;
}
//int main(){
//    TableTennisPlayer player1("Alan", "lyang", true);
//    RatePlayer rplayer1(1140,"Arya", "pei", false);
//    rplayer1.Name();
//    if(rplayer1.hasTable())
//        cout << ": has a table\n";
//    else
//        cout << ": hasn't a table \n";
//
//    player1.Name();
//    if(player1.hasTable())
//        cout << ": has a table\n";
//    else
//        cout << ": hasn't a table \n";
//
//    rplayer1.Name();
//    cout << " Rating: " << rplayer1.Rating() << endl;
//    RatePlayer rplayer2(1212, player1);
//    cout << "Name: " ;
//    rplayer2.Name();
//    cout << " Rating: " << rplayer2.Rating() << endl;
//}