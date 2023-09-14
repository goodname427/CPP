#include <bits/stdc++.h>
using namespace std;

bool is_match(vector<vector<int>> &map, vector<vector<int>> &_map, pair<int, int> p, int S, int L)
{
    if(p.first+S>L||p.second+S>L)
        return false;
    for (int i = 0; i <= S; i++)
        for (int j = 0; j <= S; j++)
            if (map[p.first + i][p.second + j] != _map[i][j])
                return false;
    return true;
}

int main()
{
    int n, L, S;
    cin >> n >> L >> S;

    vector<vector<int>> map(L + 1, vector<int>(L + 1, 0));
    vector<vector<int>> _map(S + 1, vector<int>(S + 1));
    vector<pair<int, int>> tree_vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> tree_vec[i].first >> tree_vec[i].second;
        map[tree_vec[i].first][tree_vec[i].second] = 1;
    }

    for (int i = S; i >= 0; i--)
        for (int j = 0; j <= S; j++)
            cin >> _map[i][j];

    int sum = 0;
    for (auto p : tree_vec)
    {
        if (is_match(map, _map, p, S, L))
            sum++;
    }
    cout << sum;
    return 0;
}
