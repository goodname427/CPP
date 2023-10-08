#include <bits/stdc++.h>
using namespace std;

int sign(int n)
{
    return !((n >> 31) & 1);
}


int add(int a, int b)
{
    int sum = a;
    while (b)
    {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }

    return sum;
}

int neg(int n)
{
    return add(~n, 1);
}

int sub(int a, int b)
{
    return add(a, neg(b));
}

int mul(int a, int b)
{
    int res = 0;
    int is_neg = sign(a) ^ sign(b);
    a = sign(a) ? a : neg(a);
    b = sign(b) ? b : neg(b);
    while (b)
    {
        if (b & 1)
        {
            res = add(res, a);
        }
        a <<= 1;
        b >>= 1;
    }

    return is_neg ? neg(res) : res;
}

int divide(int a, int b)
{
    int res = 0;
    int is_neg = sign(a) ^ sign(b);
    a = sign(a) ? a : neg(a);
    b = sign(b) ? b : neg(b);

    for (int i = 31; i >= 0; i--)
    {
        if((a >> i) >= b)
        {
            res |= (1 << i);
            a -= (b << i);
        }
    }

    return is_neg ? neg(res) : res;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a << " + " << b << " = " << add(a, b) << endl;
        cout << a << " - " << b << " = " << sub(a, b) << endl;
        cout << a << " * " << b << " = " << mul(a, b) << endl;
        cout << a << " / " << b << " = " << divide(a, b) << endl;
    }
    return 0;
}
