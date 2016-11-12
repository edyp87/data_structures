#include "DoubleLinkedList.h"
#include <iostream>


template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
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
bool DoubleLinkedList<T>::isEmpty() const
{
    return (head == nullptr);
}

template <typename T>
void DoubleLinkedList<T>::addToHead(T value)
{
    head = new DoubleLinkedNode<T>(value, head);
    if (head->next != nullptr)
    {
        head->next->prev = head;
    }

    if (tail == nullptr) tail = head;
}

template <typename T>
void DoubleLinkedList<T>::addToTail(T value)
{
    auto tempNode = new DoubleLinkedNode<T>(value);
    if (tail == nullptr)
    {
        head = tail = tempNode;
    }
    else
    {
        tail->next = tempNode;
        tempNode->prev = tail;
        tail = tempNode;
    }
}

template <typename T>
DoubleLinkedNode<T> *DoubleLinkedList<T>::findNode(T value)
{
    auto temp = head;

    while (temp)
    {
        if (temp->info == value)
        {
            return temp;
        }
        temp = temp->next;
    }

    return nullptr;
}

template <typename T>
void DoubleLinkedList<T>::removeNode(T value)
{
    auto foundNode = findNode(value);

    if (not foundNode)
    {
        return;
    }

    if (foundNode == head)
    {
        removeFromHead();
    }
    else if (foundNode == tail)
    {
        removeFromTail();
    }
    else
    {
        foundNode->prev->next = foundNode->next;
        foundNode->next->prev = foundNode->prev;
        delete foundNode;
    }
}

template <typename T>
int DoubleLinkedList<T>::removeFromTail()
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

    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;

    return value;
}

template <typename T>
int DoubleLinkedList<T>::removeFromHead()
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

    head = head->next;
    delete head->prev;
    head->prev = nullptr;

    return value;
}

template <typename T>
std::string DoubleLinkedList<T>::toStr() const
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

template class DoubleLinkedList<int>;
