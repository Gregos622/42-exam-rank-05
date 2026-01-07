#include <iostream>

class C
{
public:
    virtual ~C() {}
    virtual void print() const = 0;
};

class A : public C
{
public:
    void print() const { std::cout << "Class A\n"; }
};

class B : public C
{
public:
    void print() const { std::cout << "Class B\n"; }
};

int main()
{
    C* c = new A();
    c->print();
    delete c;
}