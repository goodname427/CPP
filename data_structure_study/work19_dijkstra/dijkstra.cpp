#include <iostream>
#include <list>
#include <stack>
using namespace std;

#define MAX 1000

struct edge
{
    int from;
    int to;
    int weight;
};

int mat[MAX][MAX];
int mst_mat[MAX][MAX];
int n;

void init(int mat[MAX][MAX])
{
    for (int i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            mat[i][j] = -1;
}

void input_map_name()
{
    int m; // n 节点数 m 边数
    cin >> n >> m;
    init(mat);                  //初始化矩阵
    for (int i = 0; i < m; i++) //输入
    {
        int x, y, w;
        cin >> x >> y >> w;
        mat[x - 1][y - 1] = w;
        mat[y - 1][x - 1] = w;
    }
}

void display_path(int *path, int end)
{
    int cur = end;
    stack<int> paths;
    while (cur != -1)
    {
        paths.push(cur);
        cur = path[cur];
    }
    cout << "path:";
    while (!paths.empty())
    {
        cout << paths.top() + 1 << " ";
        paths.pop();
    }
}

void dijkstra(int v)
{
    init(mst_mat);          //初始化生成树矩阵
    int *dist = new int[n]; //记录最短距离
    int *path = new int[n]; //记录最短路径
    list<edge> map;         //未连接生成树的顶点集map
    path[v] = -1;
    for (int i = 0; i < n; i++) //将图中所有顶点加入到map中
        if (i != v)
        {
            map.push_back({v, i, mat[v][i]});
            path[i] = v;
        }
    while (!map.empty())
    {
        auto it = map.begin();
        auto min = it++;              //记录到生成树距离最短的节点
        for (; it != map.end(); it++) //寻找最短边
            if (it->weight > -1 && (it->weight < min->weight || min->weight == -1))
                min = it;
        for (it = map.begin(); it != map.end(); it++) //重新获取所有节点到生成树的最短边
        {
            int _weight = mat[min->to][it->to] + min->weight;
            if (it != min && mat[min->to][it->to] > -1 && (_weight < it->weight || it->weight == -1))
            {
                path[it->to] = min->to; //记录路径
                it->from = min->to;     //重新记录边
                it->weight = _weight;
            }
        }
        dist[min->to] = min->weight; //记录最小距离
        map.erase(min);              //删除该节点
    }
    for (int i = 0; i < n; i++) //打印最短距离和路径
        if (i != v)
        {
            cout << i + 1 << ":" << dist[i] << "|";
            display_path(path, i);
            cout << endl;
        }

    delete[] dist;
    delete[] path;
}

int main()
{
    input_map_name();
    for (int i = 0; i < 4; i++)
        dijkstra(i);
    return 0;
}
/*
4 5
1 2 2
2 3 3
1 4 6
2 4 2
3 4 2

6 8
1 2 10
2 3 6
1 4 8
1 5 7
2 6 5
3 6 8
4 5 3
5 6 9

4 8
1 2 2
2 3 3
1 3 6
3 1 7
3 4 1
4 3 12
1 4 4
4 1 5
*/