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
    if (isEmpty()) return;

    auto nodeAndItsPrev = findNodeAndItsPrev(value);

    if (nodeAndItsPrev.first == nodeAndItsPrev.second)
    {
        delete nodeAndItsPrev.first;
        tail = nullptr;
    }
    else
    {
        nodeAndItsPrev.first->next = nodeAndItsPrev.second->next;
        if (nodeAndItsPrev.second == tail)
        {
            tail = nodeAndItsPrev.first;

        }
        delete nodeAndItsPrev.second;
    }
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
std::pair<SingleLinkedNode<T> *, SingleLinkedNode<T> *> SingleCyclicList<T>::findNodeAndItsPrev(int value)
{
    if (isEmpty()) return std::pair<SingleLinkedNode<T>*, SingleLinkedNode<T>*>(nullptr, nullptr);

    auto temp = tail->next;
    SingleLinkedNode<T>* tempPrev = tail;

    do
    {
        if (temp->info == value)
        {
            return std::pair<SingleLinkedNode<T>*, SingleLinkedNode<T>*>(tempPrev, temp);
        }
        tempPrev = temp;
        temp = temp->next;
    }
    while (temp != tail->next);

    return std::pair<SingleLinkedNode<T>*, SingleLinkedNode<T>*>(nullptr, nullptr);
}

template class SingleCyclicList<int>;
