#include <iostream>
using namespace std;

class A
{
public:
    virtual void VirtualFun() { cout << "A virtual function" << endl; }
    void NotVirtualFun() { cout << "A not virtual function" << endl; }

    void Display()
    {
        VirtualFun();
        NotVirtualFun();
    }

    
};

class B : public A
{
public:
    void VirtualFun() { cout << "B override function" << endl; }
    void NotVirtualFun() { cout << "B not override function" << endl; }
};

int main(int argc, char const *argv[])
{
    A a;
    B b;
    a.Display();
    b.Display();
    return 0;
}
