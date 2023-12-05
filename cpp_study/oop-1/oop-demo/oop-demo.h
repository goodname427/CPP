#ifndef __OOPDEMO__
#define __OOPDEMO__

#include <iostream>

class Account
{
private:
    /* data */
public:
    static double m_rate;
    static void set_rate(const double &x) { m_rate = x; }
};

double Account::m_rate = 8.0;

class A
{
public:
    static A &getInstance();
    void setup() {}

private:
    A();
    A(const A &rhs);
};

inline A &A::getInstance()
{
    static A a;
    return a;
}

class Base;
class Derived;
class Component;

class Base
{
public:
    Base()
    {
        std::cout << "base constructor" << std::endl;
    }
    ~Base()
    {
        std::cout << "base destructor" << std::endl;
    }
};

class Component
{
public:
    Component()
    {
        std::cout << "component constructor" << std::endl;
    }

    ~Component()
    {
        std::cout << "component destructor" << std::endl;
    }
};

class Derived : public Base
{
private:
    Component c;

public:
    Derived()
    {
        std::cout << "derived constructor" << std::endl;
    }

    ~Derived()
    {
        std::cout << "derived destructor" << std::endl;
    }
};



#endif // __OOPDEMO__
