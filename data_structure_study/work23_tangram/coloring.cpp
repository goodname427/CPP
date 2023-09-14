#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];
int visited[MAX];
int color[MAX];//记录节点颜色 -1为未着色
int n;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = 0;
}

void coloring_dfs(int v)
{
    visited[v] = 1;
    int _color = 0;//预着色颜色
    for (int i = 0; i < n; i++)
        if (mat[v][i] && color[i] == _color)//判断相邻节点颜色是否与预着色颜色相同
        {
            _color++;
            i = 0;
        }
    color[v] = _color;
    for (int i = 0; i < n; i++)
        if (!visited[i] && mat[v][i])
            coloring_dfs(i);
}

void coloring_bfs(int v)
{
    memset(color, -1, sizeof(int) * n); //初始化颜色数组
    int *visited = new int[n];          //记录节点是否访问
    for (int i = 0; i < n; i++)         //初始化
        visited[i] = 0;
    queue<int> q;
    q.push(v); // push起点
    visited[v] = 1;
    while (!q.empty())
    {
        int _color = 0;
        for (int i = 0; i < n; i++)
            if (mat[q.front()][i] && color[i] == _color)
            {
                _color++;
                i = 0;
            }
        color[q.front()] = _color;
        for (int i = 0; i < n; i++)               //遍历寻找下一个节点
            if (mat[q.front()][i] && !visited[i]) //如果某节点与当前节点连接且未访问则push该节点
            {
                q.push(i);
                visited[i] = 1; //记录该节点已访问
            }
        q.pop();
    }
    delete[] visited;
}

int main()
{
    int m; // n 节点数 m 边数
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) //输入无向图
    {
        int x, y;
        cin >> x >> y;
        mat[x - 1][y - 1] = 1;
        mat[y - 1][x - 1] = 1;
    }
    memset(color, -1, sizeof(int) * n);  //初始化颜色数组
    memset(visited, 0, sizeof(int) * n); //初始化visited数组
    coloring_dfs(0);                     //深度优先着色
    for (int i = 0; i < n; i++)
        cout << color[i] << " ";
    cout << endl;
    coloring_bfs(0); //广度优先着色
    for (int i = 0; i < n; i++)
        cout << color[i] << " ";
    return 0;
}
/*
7 10
1 2
1 5
1 7
2 4
2 6
3 4
3 7
4 6
4 7
5 7
*/