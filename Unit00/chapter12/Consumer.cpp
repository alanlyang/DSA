//
// Created by 86185 on 2021/7/25.
//

#include "Consumer.h"
#include "cstdlib"
using namespace std;
void Consumer::set(long when) {
    process_time = rand()%3 + 1;
    arrive = when;
}