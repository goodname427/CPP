#include <bits/stdc++.h>
using namespace std;

template <typename T>
using vec = vector<T, allocator<T>>;

template <template <typename Elem> typename Container,
          typename T>
void foo()
{
    Container<T> cont;
    for (int i = 0; i < 10; i++)
        cont.insert(cont.end(), T());

    for (auto &i : cont)
        cout << i << " ";
    cout << endl;
}

int main()
{
    foo<vector, int>();
    foo<list, int>();
    foo<deque, int>();
    foo<vec, int>();
    return 0;
}