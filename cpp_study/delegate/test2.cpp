#include <bits/stdc++.h>
using namespace std;

void SayHi()
{
    cout << "Hi" << endl;
}

typedef void (*FuncPtr)();

int main()
{
    (*SayHi)();
    SayHi();

    FuncPtr ptr = &SayHi;
    (*ptr)();

    FuncPtr ptr2 = SayHi;
    ptr2();

    return 0;
}