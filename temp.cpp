#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415f

int main()
{
    float a = 600, b = 2048;
    for (float i = 0; i < PI; i += 0.1)
    {
        cout << a * cos(i) + b << ",";
    }

    return 0;
}