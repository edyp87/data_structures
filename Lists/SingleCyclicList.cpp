#include "SingleCyclicList.h"
#include <iostream>


template <typename T>
SingleCyclicList<T>::~SingleCyclicList()
{
    if (isEmpty()) return;

    auto tempPtr = tail->next;

    while (tempPtr != tail)
    {
        auto temp = tempPtr;
        tempPtr = tempPtr->next;
        delete temp;
    }

    delete tail;
}

template <typename T>
bool SingleCyclicList<T>::isEmpty() const
{
    return (tail == nullptr);
}

template <typename T>
void SingleCyclicList<T>::add(T value)
{
    if (isEmpty())
    {
        tail = new SingleLinkedNode<T>(value);
        tail->next = tail;
    }
    else
    {
        tail->next = new SingleLinkedNode<T>(value, tail->next);
        tail = tail->next;
    }
}

template <typename T>
SingleLinkedNode<T> *SingleCyclicList<T>::findNode(T value)
{
    return findNodeAndItsPrev(value).second;
}

template <typename T>
void SingleCyclicList<T>::removeNode(T value)
{
    auto nodeAndItsPrev = findNodeAndItsPrev(value);

    if (not nodeAndItsPrev.first) return;

    if (hasOnlyOneElement())
    {
        tail = nullptr;
    }
    else
    {
        nodeAndItsPrev.first->next = nodeAndItsPrev.second->next;
        if (nodeAndItsPrev.second == tail)
        {
            tail = nodeAndItsPrev.first;
        }
    }
    delete nodeAndItsPrev.second;
}

template <typename T>
std::string SingleCyclicList<T>::toStr() const
{
    if (isEmpty()) return "";

    auto tempPtr = tail->next;
    std::string tempStr {};

    do
    {
        tempStr += std::to_string(tempPtr->info);
        tempStr += " ";
        tempPtr = tempPtr->next;
    }
    while (tempPtr != tail->next);

    if (not tempStr.empty()) tempStr.pop_back();

    return tempStr;
}

template <typename T>
bool SingleCyclicList<T>::hasOnlyOneElement() const
{
    return tail->next == tail;
}

template <typename T>
std::pair<SingleLinkedNode<T> *, SingleLinkedNode<T> *> SingleCyclicList<T>::findNodeAndItsPrev(int value)
{
    if (isEmpty()) return { nullptr, nullptr };

    auto temp = tail->next;
    SingleLinkedNode<T>* tempPrev = tail;

    do
    {
        if (temp->info == value)
        {
            return { tempPrev, temp };
        }
        tempPrev = temp;
        temp = temp->next;
    }
    while (temp != tail->next);

    return { nullptr, nullptr };
}

template class SingleCyclicList<int>;
