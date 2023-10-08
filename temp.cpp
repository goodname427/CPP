#include <bits/stdc++.h>
using namespace std;

bool is_pow_of_2(int n)
{
    int rightest = n & (-n);
    return rightest != 0 && (n ^ rightest) == 0;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << is_pow_of_2(n) << endl;
    }
    
}
