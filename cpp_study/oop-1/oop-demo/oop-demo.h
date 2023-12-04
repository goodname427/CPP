#ifndef __OOPDEMO__
#define __OOPDEMO__

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
    static A& getInstance();
    setup() {}
private:
    A();
    A(const A& rhs);
};

inline A &A::getInstance()
{
    static A a;
    return a;
}

#endif // __OOPDEMO__
