#include <bits/stdc++.h>
using namespace std;

struct Foo
{
    Foo() {}
    Foo(const Foo &f) {}

    void method() { cout << "foo" << endl; }
};

int main()
{
    shared_ptr<Foo> sp(new Foo);

    Foo f(*sp);  

    sp->method();
    return 0;
}
