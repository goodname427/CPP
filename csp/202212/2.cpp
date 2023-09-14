#include <bits/stdc++.h>
using namespace std;

int m;
int n;
int _default = -1;

class subject
{
public:
    int need;
    int time;
    int early;
    int late;
    subject(int need, int time) : need(need), time(time)
    {
        early = _default;
        late = _default;
    }
};

inline void dfs(vector<vector<int>> &mat, vector<subject> &vec, int i)
{
    if (vec[i].early != _default)
        return;

    for (int j = 1; j <= m; j++)
    {
        if (mat[i][j])
        {
            dfs(mat, vec, j);
            vec[i].early = vec[j].early + vec[j].time;
            return;
        }
    }
    vec[i].early = 1;
}

inline void dfs1(vector<vector<int>> &mat, vector<subject> &vec, int i)
{
    if (vec[i].late != _default)
        return;

    bool is_front = false;
    for (int j = 1; j <= m; j++)
    {
        if (mat[j][i])
        {
            dfs1(mat, vec, j);
            int late = vec[j].late - vec[i].time;
            if (vec[i].late == _default || vec[i].late > late)
                vec[i].late = late;
            is_front = true;
        }
    }
    if (!is_front)
        vec[i].late = n - vec[i].time + 1;
}

int main()
{
    cin >> n >> m;
    vector<subject> vec(m + 1, subject(0, 0));
    for (int i = 1; i <= m; i++)
        cin >> vec[i].need;
    for (int i = 1; i <= m; i++)
        cin >> vec[i].time;

    vector<vector<int>> mat(m + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
        mat[i][vec[i].need] = 1;

    for (int i = 1; i <= m; i++)
    {
        dfs(mat, vec, i);
        cout << vec[i].early << " ";
    }
    cout << endl;
    for (int i = 1; i <= m; i++)
    {
        dfs1(mat, vec, i);
        if(vec[i].late<1)
            return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cout << vec[i].late << " ";
    }
    return 0;
}
/*
100 5
0 1 2 3 4
10 10 10 10 10
*/
