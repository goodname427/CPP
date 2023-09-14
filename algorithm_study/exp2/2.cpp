#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool has = false;
    cin >> n;
    for (int i = 3; i <= 7; i += 2)
    {
        if (n % i == 0)
        {
            has = true;
            cout << i << " ";
        }
    }
    if (!has)
        cout << "n";
}
