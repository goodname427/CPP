#include <bits/stdc++.h>
#include "../util/cvectorop"
using namespace std;

string randomly_str(int max, int max_value = 10)
{
    vector<int> vec = randomly_vec(max, max_value);
    string res = "";
    for (auto e : vec)
        res += e + 'a';
    return res;
}
