//
// Created by 86185 on 2021/7/25.
//

#ifndef DSA_CONSUMER_H
#define DSA_CONSUMER_H


class Consumer {
private:
    long arrive;
    int process_time;

public:
    Consumer(){ arrive=process_time=0;}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return process_time;}
};


#endif //DSA_CONSUMER_H
