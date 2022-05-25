#ifndef NODE_
#define NODE_

template <typename ItemType>
class Node{
    private:
    ItemType data;
    Node<ItemType>* next;
    public:
    Node() = default;
    ItemType getData();
    Node<ItemType>* getNext();
    void setData(ItemType theData);
    void setNext(Node<ItemType>* nextNodePtr);
};

#include "Node.cpp"
#endif