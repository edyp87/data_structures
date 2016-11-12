#pragma once

class IntNode
{
public:
    IntNode(int _info = 0, IntNode *_next = nullptr) : info(_info), next(_next) {}

    int info;
    IntNode *next;
};
