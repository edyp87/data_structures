#pragma once

#include "SingleLinkedNode.h"
#include <string>

template <typename T>
class SingleCyclicList
{
public:
    virtual ~SingleCyclicList();

    SingleCyclicList() : tail(nullptr) {}

    bool isEmpty() const;
    void add(T value);
    SingleLinkedNode<T>* findNode(T value);
    void removeNode(T value);
    int removeFromTail();
    std::string toStr() const;

private:
    std::pair<SingleLinkedNode<T> *, SingleLinkedNode<T> *> findNodeAndItsPrev(int value);

    SingleLinkedNode<T> *tail;
};
