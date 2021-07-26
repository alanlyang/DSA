//
// Created by 86185 on 2021/7/26.
//

#ifndef DSA_RATEPLAYER_H
#define DSA_RATEPLAYER_H
#include "TableTennisPlayer.h"

class RatePlayer: public TableTennisPlayer{
private:
    unsigned int rating;
public:
    RatePlayer(unsigned int r=0, const char* fn="none", const char* ln="none", bool ht= false);
    RatePlayer(unsigned int r, const TableTennisPlayer & tp);// 使用一个tabletennisplayer的对象
    unsigned int Rating(){return rating;}
    void ResetRating(unsigned  int r) { rating = r;}
};


#endif //DSA_RATEPLAYER_H
