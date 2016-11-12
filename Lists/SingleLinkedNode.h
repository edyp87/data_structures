#pragma once

template <typename T>
class SingleLinkedNode
{
public:
    SingleLinkedNode(T _info = 0, SingleLinkedNode *_next = nullptr) : info(_info), next(_next) {}

    T info;
    SingleLinkedNode *next;
};
