#include <bits/stdc++.h>
using namespace std;

template <template<typename Elem> typename Container,
          typename T>
void foo()
{
    Container<T> cont;
    for (int i = 0; i < 10; i++)
        cont.insert(cont.end(), T());
}

int main()
{
    foo<vector, int>();
    return;
}