#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *p = new int[10];
    cout << sizeof(p) << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << p + i << endl;
    }
    delete p;
    return 0;
}
