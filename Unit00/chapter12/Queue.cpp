//
// Created by 86185 on 2021/7/25.
//

#include "Queue.h"
#include "cstdlib"

Queue::Queue(int qs) :qsize(qs){
    front = rear = NULL;
    items = 0;
}
Queue::~Queue() {
    Node * temp;
    while(front != NULL){
        temp = front; // front为队首指针
        front = front->next;
        delete temp;
    }
}
bool Queue::is_empty() const {
    return items == 0;
}
bool Queue::is_full() const {
    return items == Q_SIZE;
}
int Queue::queue_count() const {
    return items;
}
bool Queue::en_queue(const Item &item) {
    if(is_full()) return false; // 队列已满
    Node* add = new Node;
    if(add == NULL) return false; // 内存分配失败
    add->next = NULL;
    add->item = item;
    items++;
    if (front==NULL) {
        front = add;
    } else{
        rear->next = add;
    }
    rear = add;
    return true;
}
bool Queue::de_queue(Item &item) {
    if(is_empty()) return false;//队列为空
    //否则删除队首元素
    item = front->item; // 将第一个元素出队供调用程序使用
    items--;
    Node* temp;
    temp = front;
    front = front->next;
    delete temp;
    if(items == 0){
        rear = NULL;
    }
    return true;
}

// 用来模拟随机用户到来
bool new_customer(double x){
    return (rand()*x/RAND_MAX < 1); //随机生成一个0-x之间的整数
}