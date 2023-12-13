#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 0;
    int *p = &x;
    int &r = x;

    cout << sizeof(x) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(r) << endl;
    return 0;
}
