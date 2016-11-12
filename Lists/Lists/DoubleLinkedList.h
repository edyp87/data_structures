#pragma once

#include "DoubleLinkedNode.h"
#include <string>

template <typename T>
class DoubleLinkedList
{
public:
    virtual ~DoubleLinkedList();

    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const;
    void addToHead(T value);
    void addToTail(T value);
    DoubleLinkedNode<T>* findNode(T value);
    void removeNode(T value);
    int removeFromTail();
    int removeFromHead();
    std::string toStr() const;

private:
    DoubleLinkedNode<T> *head;
    DoubleLinkedNode<T> *tail;
};
