#pragma once

#include "SingleLinkedNode.h"
#include <string>

template <typename T>
class SingleLinkedList
{
public:
    virtual ~SingleLinkedList();

    SingleLinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const;
    void addToHead(T value);
    void addToTail(T value);
    SingleLinkedNode<T>* findNode(T value);
    void removeNode(T value);
    int removeFromTail();
    int removeFromHead();
    std::string toStr() const;

private:
    std::pair<SingleLinkedNode<T> *, SingleLinkedNode<T> *> findNodeAndItsPrev(int value);
    SingleLinkedNode<T>* findNodePrevToTail();

    SingleLinkedNode<T> *head;
    SingleLinkedNode<T> *tail;
};
