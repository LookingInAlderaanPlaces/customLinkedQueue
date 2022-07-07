#ifndef QUEUE_
#define QUEUE_
#include "Node.h"

template <typename ItemType>
class Queue{
    private:
    using NodePtr = Node<ItemType>*;
    NodePtr firstPtr = nullptr;
    NodePtr backPtr = nullptr;
    int ItemCount = 0;
    public:
    Queue() = default;
    void enqueue(ItemType newEntry);
    bool dequeue();
    ItemType peekFront();
    ItemType peekBack();
    bool isEmpty();
    int size();
    void printQueue();
    ~Queue();
};

#include "Queue.cpp"
#endif