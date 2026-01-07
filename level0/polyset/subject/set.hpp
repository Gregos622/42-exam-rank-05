#pragma once

#include "searchable_bag.hpp"

class set : public searchable_bag {
private:
    searchable_bag *_bag; // owned (alloué dynamiquement)

    static searchable_bag *clone_bag(const searchable_bag &src);

public:
    set();                              // optionnel, mais canonique
    set(const searchable_bag &src);     // utilisé par le main: set sa(*a);
    set(const set &other);
    set &operator=(const set &other);
    virtual ~set();

    // Accès au bag wrappé (utilisé par le main)
    searchable_bag &get_bag();
    const searchable_bag &get_bag() const;

    // searchable_bag
    virtual bool has(int value) const;

    // bag
    virtual void insert(int value);
    virtual void insert(int *array, int size);
    virtual void print() const;
    virtual void clear();
};
