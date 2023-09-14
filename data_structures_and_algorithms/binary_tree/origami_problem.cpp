#include <bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void solve(int max_level, int cur_level, bool concave)
{
    if(cur_level > max_level)
        return;

    solve(max_level, cur_level + 1, true);
    
    cout << (concave ? "凹" : "凸") << " ";
    
    solve(max_level, cur_level + 1, false);
}

void solve(int n)
{
    solve(n, 1, true);
}

int main()
{
    int n = random(10);
    cout << n << endl;
    solve(n);
    return 0;
}
