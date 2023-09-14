#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
int mat[MAX][MAX];
int n;

void aov_sort()
{
    int *in = new int[n];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        in[i] = 0;
        for (int j = 0; j < n; j++)
            if (mat[j][i])
                in[i]++;
        if (!in[i])
            s.push(i);
    }
    while (!s.empty())
    {
        int cur = s.top();
        s.pop();
        cout << cur << " ";
        for (int i = 0; i < n; i++)
            if (mat[cur][i] && !(--in[i]))
                s.push(i);
    }
    delete[] in;
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        int s, t;
        cin >> s >> t;
        mat[t][s] = 1;
    }
    aov_sort();
    return 0;
}
/*
7 10
0 2
0 3
1 3
1 5
2 4
3 4
3 6
3 5
4 6
5 6
*/