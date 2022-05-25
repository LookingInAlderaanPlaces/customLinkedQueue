template <typename ItemType>
void Queue<ItemType>::enqueue(ItemType newEntry){
    if (isEmpty()){
        firstPtr = new Node<ItemType>;
        firstPtr->Node::setData(newEntry);
        firstPtr->Node::setNext(nullptr);
        backPtr = firstPtr;
        ++ItemCount;
    }
    else if(ItemCount == 1){
        backPtr = new Node<ItemType>;
        backPtr->Node::setData(newEntry);
        backPtr->Node::setNext(nullptr);
        firstPtr->Node::setNext(backPtr);
        ++ItemCount;
    }
    else{
        NodePtr prevPtr = backPtr;
        backPtr = new Node<ItemType>;
        backPtr->Node::setData(newEntry);
        backPtr->Node::setNext(nullptr);
        prevPtr->Node::setNext(backPtr);
        ++ItemCount;
    }

}

template <typename ItemType>
bool Queue<ItemType>::dequeue(){
    NodePtr deletedNode = firstPtr;
    firstPtr = firstPtr->getNext();
    delete deletedNode;
    --ItemCount;

}

template <typename ItemType>
ItemType Queue<ItemType>::peekFront(){
    return firstPtr->Node::getData();
}

template <typename ItemType>
ItemType Queue<ItemType>::peekBack(){
    return backPtr->Node::getData();
}

template <typename ItemType>
bool Queue<ItemType>::isEmpty(){
    if (ItemCount == 0){
        return true;
    }
    else{
        return false;
    }
}

template <typename ItemType>
int Queue<ItemType>::size(){
    return ItemCount;
}

template <typename ItemType>
Queue<ItemType>::~Queue(){
    while (!isEmpty()){
        dequeue();
    }
}