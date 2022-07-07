template <typename ItemType>
void Queue<ItemType>::enqueue(ItemType newEntry){
    if (isEmpty()){
        firstPtr = new Node<ItemType>;
        firstPtr->Node::setData(newEntry);
        firstPtr->Node::setNext(nullptr);
        backPtr = firstPtr;
        ++ItemCount;
    }
    else{
        NodePtr tempPtr = backPtr;
        backPtr = new Node<ItemType>;
        tempPtr->setNext(backPtr);
        backPtr->setData(newEntry);
        backPtr->setNext(nullptr);
        ++ItemCount;
    }
}

template <typename ItemType>
bool Queue<ItemType>::dequeue(){
    if (!isEmpty()){
        NodePtr deletedNode = firstPtr;
        firstPtr = firstPtr->getNext();
        delete deletedNode;
        --ItemCount;
        return true;
    }
    else{
        std::cout << "Your queue is empty!\n";
        return false;
    }

}

template <typename ItemType>
ItemType Queue<ItemType>::peekFront(){
    if (!isEmpty()){    
        return firstPtr->Node::getData();
    }
    else{
        throw std::logic_error("Your queue is empty!");
    }
}

template <typename ItemType>
ItemType Queue<ItemType>::peekBack(){
    if (!isEmpty()){
        return backPtr->Node::getData();
    }
    else{
        throw std::logic_error("Your queue is empty!");
    }
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
void Queue<ItemType>::printQueue(){
    NodePtr tempPtr = firstPtr;
    if(!isEmpty()){
        while (tempPtr != nullptr)
        {
            std::cout << tempPtr->getData();
            tempPtr = tempPtr->getNext();
        }
    }
    else{
        std::cout << "Your list is empty!\n";
    }
}

template <typename ItemType>
Queue<ItemType>::~Queue(){
    while (!isEmpty()){
        dequeue();
    }
}