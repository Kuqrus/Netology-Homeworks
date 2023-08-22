#include "task_10_2.h"

node::node(int value) : m_value{ value } {};
node::~node() { std::cout << "destructor called\n"; }

void task_10_2() {
    auto node1 = std::make_shared<node>(1);
    auto node2 = std::make_shared<node>(2);
    node1->parent = node2;
    node2->parent = node1;
}