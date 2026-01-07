#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other)
    : bag(other), tree_bag(other) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& other)
{
    if (this != &other)
        tree_bag::operator=(other);
    return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::has(int val) const
{
    node *cur = tree;
    while (cur != 0)
    {
        if (val == cur->value)
            return true;
        if (val < cur->value)
            cur = cur->l;
        else
            cur = cur->r;
    }
    return false;
}