#include <bits/stdc++.h>
#include "union_find_set.cpp"
using namespace std;

int main()
{
    union_find_set<int> set({1, 2, 3, 4, 5, 6});

    cout << set.is_same_set(1, 5) << endl;
    
    set.union_set(1, 2);
    set.union_set(4, 5);
    set.union_set(2, 4);

    cout << set.is_same_set(1, 5) << endl;
    cout << set.is_same_set(1, 6) << endl;
    cout << set.is_same_set(4, 2) << endl;
    return 0;
}
