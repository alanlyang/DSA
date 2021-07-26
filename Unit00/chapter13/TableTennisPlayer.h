//
// Created by 86185 on 2021/7/26.
//

#ifndef DSA_TABLETENNISPLAYER_H
#define DSA_TABLETENNISPLAYER_H


class TableTennisPlayer {
private:
    enum {LIM=20};
    char first_name[LIM];
    char last_name[LIM];
    bool has_table;

public:
    TableTennisPlayer(const char* fn="none", const char* ln="none", bool ht= false);
    void Name() const;
    bool hasTable()const{ return has_table;}
    void resetTable(bool v){ has_table = v;}
};


#endif //DSA_TABLETENNISPLAYER_H
