#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

int main()
{
    Fraction f(1, 2);

    double d = 0.2 + f;
    cout << d << endl;

    Fraction f2 = f + Fraction(4);
    cout << f2 << endl;
    return 0;
}
