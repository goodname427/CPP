#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i = 8 | 1 + 2 ^ !0;

db:
    if (!i ^ i)
    {
        goto sd;
    }

    for (i = 0; i < 100; i++)
    {
        while (i < (i++) * 8 - 10)
        {
        sd:
            i = ++i + i++;
                cout << i << endl;
            if (i & !i)
                goto db;
        }
    }
    if (i < 10)
        goto db;
    cout << i;
    return 0;
}
