#include <bits/stdc++.h>
using namespace std;

enum color
{
    red,
    blue,
    green
};

void paint(color c)
{
    switch (c)
    {
    case color::red:
        cout << "paint to red" << endl;
        break;
    case color::blue:
        cout << "paint to blue" << endl;
        break;
    case color::green:
        cout << "paint to green" << endl;
        break;
    default:
        break;
    }
}

int main()
{
    paint(color::red);
    paint(color::blue);
    paint(color::green);
    paint(red);
    return 0;
}
