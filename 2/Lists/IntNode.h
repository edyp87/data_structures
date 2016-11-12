#pragma once

template <typename T>
class IntNode
{
public:
    IntNode(T _info = 0, IntNode *_next = nullptr) : info(_info), next(_next) {}

    T info;
    IntNode *next;
};
