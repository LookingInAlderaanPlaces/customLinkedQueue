template <typename ItemType>
ItemType Node<ItemType>::getData(){
    return data;
}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext(){
    return next;
}

template <typename ItemType>
void Node<ItemType>::setData(ItemType theData){
    data = theData;
}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr){
    next = nextNodePtr;
}