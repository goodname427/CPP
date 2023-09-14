#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
#define INF 10000

class edge
{
public:
    int from;
    int to;
    int distance;
    edge(int from, int to, int distance) : from(from), to(to), distance(distance) {}
};

int mat[MAX][MAX];
int m;
int n;
vector<edge> mat_edge;

void init(int inf = INF)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = inf;
}

void input()
{
    cin >> m >> n;
    init();
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (j < i && mat[i][j] != -1)
            {
                mat_edge.push_back(edge(i, j, mat[i][j]));
            }
        }
}

void dfs(vector<edge> &solve, vector<edge> &remain)
{
}

int main()
{
    input();
    int begin;
    cin >> begin;
    vector<edge> solve, remain = mat_edge;
    return 0;
}
/*
4
-1 2 5 7
2 -1 8 3
5 8 -1 1
7 3 1 -1
1
*/