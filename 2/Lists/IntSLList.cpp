#include "IntSLList.h"
#include <iostream>

IntSLList::~IntSLList()
{
    auto temp = head;
    while (temp)
    {
        auto tempNext = temp->next;
        delete temp;
        temp = tempNext;
    }
}

bool IntSLList::isEmpty() const
{
    return (head == nullptr);
}

void IntSLList::addToHead(int value)
{
    m_isEmpty = false;
    head = new IntNode(value, head);
    if (tail == nullptr) tail = head;
}

void IntSLList::addToTail(int value)
{
    m_isEmpty = false;
    IntNode * tempNode = new IntNode(value);
    if (tail == nullptr)
    {
        head = tail = tempNode;
    }
    else
    {
        tail->next = tempNode;
        tail = tempNode;
    }
}

IntNode *IntSLList::findNode(int value)
{
    return findNodeAndItsPrev(value).second;
}

void IntSLList::removeNode(int value)
{
    auto foundNode = findNodeAndItsPrev(value);

    if (not foundNode.second)
    {
        return;
    }

    if (foundNode.first)
    {
        foundNode.first->next = foundNode.second->next;
    }
    else
    {
        head = foundNode.second->next;
    }
    delete foundNode.second;
}

int IntSLList::removeFromTail()
{
    if (tail == nullptr)
        throw std::string("List is empty");

    auto value = tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return value;
    }

    auto prevNode = findNodePrevToTail();

    delete tail;
    tail = prevNode;
    tail->next = nullptr;

    return value;
}

int IntSLList::removeFromHead()
{
    if (head == nullptr)
    {
        throw std::string("List is empty");
    }

    auto value = head->info;

    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
        return value;
    }

    auto temp = head->next;
    delete head;
    head = temp;

    return value;
}

std::string IntSLList::toStr() const
{
    auto tempPtr = head;
    std::string tempStr {};
    while (tempPtr)
    {
        tempStr += std::to_string(tempPtr->info);
        tempStr += " ";
        tempPtr = tempPtr->next;
    }

    if (not tempStr.empty()) tempStr.pop_back();

    return tempStr;
}

std::pair<IntNode*, IntNode*> IntSLList::findNodeAndItsPrev(int value)
{
    auto temp = head;
    IntNode* tempPrev = nullptr;

    while (temp)
    {
        if (temp->info == value)
        {
            return std::pair<IntNode*, IntNode*>(tempPrev, temp);
        }
        tempPrev = temp;
        temp = temp->next;
    }

    return std::pair<IntNode*, IntNode*>(nullptr, nullptr);
}

IntNode *IntSLList::findNodePrevToTail()
{
    auto temp = head;

    while (temp)
    {
        if (temp->next == tail)
        {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}
