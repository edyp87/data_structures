#include "SingleLinkedList.h"
#include <iostream>


template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    auto temp = head;
    while (temp)
    {
        auto tempNext = temp->next;
        delete temp;
        temp = tempNext;
    }
}

template <typename T>
bool SingleLinkedList<T>::isEmpty() const
{
    return (head == nullptr);
}

template <typename T>
void SingleLinkedList<T>::addToHead(T value)
{
    head = new IntNode<T>(value, head);
    if (tail == nullptr) tail = head;
}

template <typename T>
void SingleLinkedList<T>::addToTail(T value)
{
    auto tempNode = new IntNode<T>(value);
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

template <typename T>
IntNode<T> *SingleLinkedList<T>::findNode(T value)
{
    return findNodeAndItsPrev(value).second;
}

template <typename T>
void SingleLinkedList<T>::removeNode(T value)
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

template <typename T>
int SingleLinkedList<T>::removeFromTail()
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

template <typename T>
int SingleLinkedList<T>::removeFromHead()
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

template <typename T>
std::string SingleLinkedList<T>::toStr() const
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

template <typename T>
std::pair<IntNode<T> *, IntNode<T> *> SingleLinkedList<T>::findNodeAndItsPrev(int value)
{
    auto temp = head;
    IntNode<T>* tempPrev = nullptr;

    while (temp)
    {
        if (temp->info == value)
        {
            return std::pair<IntNode<T>*, IntNode<T>*>(tempPrev, temp);
        }
        tempPrev = temp;
        temp = temp->next;
    }

    return std::pair<IntNode<T>*, IntNode<T>*>(nullptr, nullptr);
}

template <typename T>
IntNode<T> *SingleLinkedList<T>::findNodePrevToTail()
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

template class SingleLinkedList<int>;
