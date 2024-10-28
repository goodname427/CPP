#include <bits/stdc++.h>
using namespace std;

template< class RetValType, class... ParamTypes >
using Method = RetValType(ParamTypes...);

template< class RetValType, class... ParamTypes >
class MethodClass
{
public:
    typedef RetValType (*Method)(ParamTypes... Params);
};

void SayHello(string name)
{
    cout << name + ": Hello!" << endl;
}

void Test(Method<void, string> method1, MethodClass<void, string>::Method method2)
{
    method1("method1");
    method2("method2");
}


int main()
{
    MethodClass<void, string>::Method method2 = &SayHello; 
    
    Test(SayHello, &SayHello);
    return 0;
}
