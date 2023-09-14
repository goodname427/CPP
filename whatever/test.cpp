#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n = 3;

void display(vector<int> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void gen(int k)
{
    if (k > n)
    {
        display(v);
    }
    else
    {
        gen(k + 1);
        v.push_back(k);
        gen(k + 1);
        v.pop_back();
    }
}

int main()
{
    gen(1);
    return 0;
}
