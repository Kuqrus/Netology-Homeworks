#pragma once
#include <iostream>
#include <vector>
#include <memory>

class node
{
public:
    int m_value;
    std::weak_ptr<node> parent;
    node(int value);
    ~node();
};

void task_10_2();
