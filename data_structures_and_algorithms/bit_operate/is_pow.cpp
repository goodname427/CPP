#include <bits/stdc++.h>
using namespace std;

bool is_pow_of_2(int n)
{
    return n && ((n & -n) == n);
}

bool is_pow_of_4(int n)
{
    return is_pow_of_2(n) && (n & 0x55555555);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << (is_pow_of_2(n)? "是":"不是") << "2的幂" << endl;
        cout << n << (is_pow_of_4(n)? "是":"不是") << "4的幂" << endl;
    }
    
    return 0;
}
