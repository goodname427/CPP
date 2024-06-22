#include <bits/stdc++.h>
using namespace std;

class Strategy
{
public:
    virtual int Calc(int i) = 0;

    virtual ~Strategy() {} 
};

class PlusStrategy : public Strategy
{
    virtual int Calc(int i) override 
    {
        return i + 1;
    }
};

class SquareStrategy : public Strategy
{
    virtual int Calc(int i) override 
    {
        return i * i;
    }
};

class Calculator
{
private:
    Strategy* strategy;

public:
    Calculator(Strategy* strategy) : strategy(strategy)
    {

    }

    int Calc(int i)
    {
        return strategy->Calc(i);
    }
};
