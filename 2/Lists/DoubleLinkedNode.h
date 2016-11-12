#pragma once

template <typename T>
class DoubleLinkedNode
{
public:
    DoubleLinkedNode(T _info = 0, DoubleLinkedNode *_next = nullptr, DoubleLinkedNode *_prev = nullptr)
        : info(_info), next(_next), prev(_prev) {}

    T info;
    DoubleLinkedNode *next;
    DoubleLinkedNode *prev;
};
