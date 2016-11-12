#pragma once

#include "IntNode.h"
#include <string>

class IntSLList
{
public:
    virtual ~IntSLList();

    IntSLList() : head(nullptr), tail(nullptr) {}

    bool isEmpty() const;
    void addToHead(int value);
    void addToTail(int value);
    IntNode* findNode(int value);
    void removeNode(int value);
    int removeFromTail();
    int removeFromHead();
    std::string toStr() const;

private:
    std::pair<IntNode *, IntNode *> findNodeAndItsPrev(int value);
    IntNode* findNodePrevToTail();

    bool m_isEmpty = true;
    IntNode *head;
    IntNode *tail;
};
