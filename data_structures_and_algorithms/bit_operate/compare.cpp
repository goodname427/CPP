#include <bits/stdc++.h>
using namespace std;

/// @brief
/// @param n
/// @return 非负数返回1，负数返回0
int sign(int n)
{
    return !((n >> 31) & 1);
}

int max(int a, int b)
{
    int c = a - b;
    int sign_of_a = sign(a);
    int sign_of_b = sign(b);
    int sign_of_c = sign(c);
    int is_different_sign = sign_of_a ^ sign_of_b;
    int return_a = is_different_sign * sign_of_a + (!is_different_sign) * sign_of_c;

    return a * return_a + b * (!return_a);
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << a << "是" << (sign(a) ? "非负数" : "负数") << endl;
        cout << a << "和" << b << "中较大的数是" << max(a, b) << endl;
    }
    return 0;
}
