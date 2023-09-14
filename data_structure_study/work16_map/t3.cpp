#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class path_node
{
public:
    int pos;
    list<path_node *> children;
    path_node *parent;
    path_node(int pos) : pos(pos), parent(NULL), children(list<path_node *>()) {}
    path_node() : pos(0), parent(NULL), children(list<path_node *>()) {}
    ~path_node()
    {
        if (children.size() > 0)
            for (auto it = children.begin(); it != children.end(); it++)
                delete *it;
    }
    void add_child(path_node *child)
    {
        children.push_back(child);
        child->parent = this;
    }
    void display()
    {
        stack<int> path;
        path_node *cur = this;
        while (cur != NULL)
        {
            path.push(cur->pos);
            cur = cur->parent;
        }
        cout << "times:" << path.size() - 1 << endl
             << "path:";
        while (!path.empty())
        {
            cout << path.top() + 1 << " ";
            path.pop();
        }
    }
};

int mat[MAX][MAX];
int visited[MAX];

void init_visited(int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}
//非递归广度优先
void BFS(int n, int v)
{
    int *visited = new int[n];  //记录节点是否访问
    for (int i = 0; i < n; i++) //初始化
        visited[i] = 0;
    queue<int> q;
    q.push(v); // push起点
    visited[v] = 1;
    while (!q.empty())
    {
        cout << q.front() + 1 << " ";
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
//非递归深度优先
// n:节点数;v:起始节点
void DFS(int n, int v)
{
    int *visited = new int[n];  //记录节点是否访问
    for (int i = 0; i < n; i++) //初始化
        visited[i] = 0;
    stack<int> s;
    s.push(v); // push起点
    while (!s.empty())
    {
        if (!visited[s.top()]) //如果节点未访问则输出该节点
        {
            cout << s.top() + 1 << " ";
            visited[s.top()] = 1; //记录该节点已访问
        }
        bool flg = false;                       //判断是否有出口
        for (int i = 0; i < n; i++)             //遍历寻找下一个节点
            if (mat[s.top()][i] && !visited[i]) //如果某节点与当前节点连接且未访问则push该节点
            {
                s.push(i);
                flg = true;
                break;
            }
        if (!flg) //如果当前节点没有出口则向上回溯
            s.pop();
    }
    delete[] visited;
}
//递归深度优先
// n:节点数;v:访问节点
void _DFS(int n, int v)
{
    cout << v + 1 << " ";
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && mat[v][i])
            _DFS(n, i);
}
//打印无向图矩阵
void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
//寻路 树型 适用于节点数较多的情况 
void find_way(int n, int start, int end)
{
    int *visited = new int[n];  //记录节点是否访问
    for (int i = 0; i < n; i++) //初始化
        visited[i] = 0;
    queue<path_node *> q;
    path_node* start_node=new path_node(start);
    q.push(start_node); // push起点
    visited[start] = 1;
    while (!q.empty())
    {
        bool has_found = false;
        for (int i = 0; i < n; i++)                    //遍历寻找下一个节点
            if (mat[q.front()->pos][i] && !visited[i]) //如果某节点与当前节点连接且未访问则push该节点
            {
                path_node *node = new path_node(i);
                q.push(node);
                q.front()->add_child(node); //添加子节点
                visited[i] = 1;             //记录该节点已访问
                if (i == end)
                {
                    has_found = true;
                    node->display();
                }
            }
        if (has_found)
            break;
        q.pop();
    }
    delete start_node;
    delete[] visited;
}
//寻路 数组 适用于节点数较少的情况
void _find_way(int n, int start, int end)
{
    int *visited = new int[n]; //记录节点是否访问
    int *path = new int[n];
    for (int i = 0; i < n; i++) //初始化
    {
        visited[i] = 0;
        path[i] = 0;
    }
    queue<int> q;
    q.push(start); // push起点
    visited[start] = 1;
    path[start] = -1;
    while (!q.empty())
    {
        bool has_found = false;
        for (int i = 0; i < n; i++)               //遍历寻找下一个节点
            if (mat[q.front()][i] && !visited[i]) //如果某节点与当前节点连接且未访问则push该节点
            {
                q.push(i);
                path[i] = q.front();
                visited[i] = 1; //记录该节点已访问
                if (i == end)
                    has_found = true;
            }
        if (has_found)
            break;
        q.pop();
    }
    //输出路径
    int cur = end;
    stack<int> paths;
    while (cur != -1)
    {
        paths.push(cur);
        cur = path[cur];
    }
    cout << "times:" << paths.size() - 1 << endl
         << "path:";
    while (!paths.empty())
    {
        cout << paths.top() + 1 << " ";
        paths.pop();
    }

    delete[] visited;
    delete[] path;
}

int main()
{
    int m, n; // n 节点数 m 边数
    cin >> n >> m;
    for (int i = 0; i < m; i++) //输入无向图
    {
        int x, y;
        cin >> x >> y;
        mat[x - 1][y - 1] = 1;
        mat[y - 1][x - 1] = 1;
    }
    cout << endl;
    find_way(n, 0, 4);
    return 0;
}
/*
6 8
1 2
2 3
3 6
1 4
1 5
2 6
4 5
5 6
-----
5 7
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/