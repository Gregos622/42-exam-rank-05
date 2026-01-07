#include "set.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set() : _bag(0) {}

set::set(const searchable_bag &src) : _bag(clone_bag(src)) {}

set::set(const set &other) : _bag(0)
{
    if (other._bag)
        _bag = clone_bag(*other._bag);
}

set &set::operator=(const set &other)
{
    if (this != &other)
    {
        delete _bag;
        _bag = 0;
        if (other._bag)
            _bag = clone_bag(*other._bag);
    }
    return *this;
}

set::~set()
{
    delete _bag;
}

searchable_bag &set::get_bag()
{
    return *_bag;
}

const searchable_bag &set::get_bag() const
{
    return *_bag;
}

bool set::has(int value) const
{
    if (!_bag)
        return false;
    return _bag->has(value);
}

void set::insert(int value)
{
    if (!_bag)
        return;
    if (!_bag->has(value))
        _bag->insert(value);
}

void set::insert(int *array, int size)
{
    if (!_bag || !array || size <= 0)
        return;
    for (int i = 0; i < size; ++i)
        insert(array[i]); // réutilise la règle d'unicité
}

void set::print() const
{
    if (_bag)
        _bag->print();
}

void set::clear()
{
    if (_bag)
        _bag->clear();
}

searchable_bag *set::clone_bag(const searchable_bag &src)
{
    // On clone selon le type concret (array ou tree)
    const searchable_array_bag *a =
        dynamic_cast<const searchable_array_bag *>(&src);
    if (a)
        return new searchable_array_bag(*a);

    const searchable_tree_bag *t =
        dynamic_cast<const searchable_tree_bag *>(&src);
    if (t)
        return new searchable_tree_bag(*t);

    // Si le sujet ne fournit que ces 2 classes, on n’arrive jamais ici.
    return 0;
}
