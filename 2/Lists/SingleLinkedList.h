#pragma once

#include "IntNode.h"
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
    IntNode<T>* findNode(T value);
    void removeNode(T value);
    int removeFromTail();
    int removeFromHead();
    std::string toStr() const;

private:
    std::pair<IntNode<T> *, IntNode<T> *> findNodeAndItsPrev(int value);
    IntNode<T>* findNodePrevToTail();

    IntNode<T> *head;
    IntNode<T> *tail;
};
