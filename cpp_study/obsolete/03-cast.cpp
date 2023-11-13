#include <bits/stdc++.h>
using namespace std;

int main()
{
    float f = 123.23;
    int i = static_cast<int>(f);
    int j = (int)f;
    cout << i << endl
         << j << endl;

    const int c = 10;
    int& r = const_cast<int&>(c); // 常量转换，将const int转换为int
    // int r = c;
    cout << r << endl;
    r = 11;
    cout << c << endl;
    cout << r << endl;
    return 0;
}
