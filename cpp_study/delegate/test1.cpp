#include <bits/stdc++.h>
using namespace std;

template <class UserClass>
class TMethodPtrResolver
{
public:
    typedef string (UserClass::*Salutation)(string Param);
};

class Method
{
public:
    string SayHello(string name)
    {
        return name + ": Hello!";
    }
};

typedef string (*Salutation)(string Param);

string SayHi(string name)
{
    return name + ": Hi!";
}

int main()
{
    Method method;
    TMethodPtrResolver<Method>::Salutation ptr = &Method::SayHello;
    // 语法糖
    // TMethodPtrResolver<Method>::Salutation ptr = Method::SayHello;

    cout << (method.*ptr)("cgl") << endl;
    cout << (method.SayHello)("cgl") << endl;
    cout << method.SayHello("cgl") << endl;

    Salutation salutation = &SayHi;
    // 语法糖
    // Salutation salutation = SayHi;
    cout << (*salutation)("xxl") << endl;
    // 语法糖
    // cout << salutation("xxl") << endl;

    return 0;
}