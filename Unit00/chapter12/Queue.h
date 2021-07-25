//
// Created by 86185 on 2021/7/25.
//

#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H
#include "Consumer.h"

typedef Consumer Item;

class Queue {
private:
    enum {Q_SIZE=10};
    struct Node{
        Item item;
        struct Node* next;
    };

    Node* front;
    Node* rear;
    int items;
    const int qsize;

    // Prevent compilation errors
    Queue(const Queue &q):qsize(0){}; // 复制构造函数
    Queue & operator=(const Queue &q){return *this;} // 通常重载需要声明为友元
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool is_empty()const;
    bool is_full()const;
    int queue_count()const;
    bool en_queue(const Item & item);
    bool de_queue(Item & item);
};


#endif //DSA_QUEUE_H
