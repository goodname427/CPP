#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
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

void display(int mat[MAX][MAX])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

bool compare(const edge &l, const edge &r)
{
    return l.weight < r.weight;
}

void kruskal_mst()
{
    init(mst_mat); //初始化生成树矩阵
    vector<edge> edges;//记录图中的所有边
    int *conn = new int[n];//记录每个顶点的连通分量
    for (int i = 0; i < n; i++) //设置每个顶点的联通分量
        conn[i] = i;
    for (int i = 1; i < n; i++) //获取所有边
        for (int j = 0; j < i; j++)
            if (mat[i][j] > -1)
                edges.push_back({i, j, mat[i][j]});
    sort(edges.begin(), edges.end(), compare); //排序
    int total_edges = 0;//生成树中的总边数
    for (auto it = edges.begin(); it != edges.end(); it++)
    {
        if (conn[it->from] != conn[it->to]) //如果两个顶点属于不同的连通分量，则添加该边
        {
            int _conn = conn[it->to];
            for (int i = 0; i < n; i++) //合并两个连通分量
                if (_conn == conn[i])
                    conn[i] = conn[it->from];
            mst_mat[it->to][it->from] = it->weight;//记录生成树
            mst_mat[it->from][it->to] = it->weight;
            total_edges++;//总边数增加
        }
        if (total_edges >= n - 1)//判断生成树中是否已有n-1条边
            break;
    }
    delete[] conn;
}

void test1()
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
    kruskal_mst();
    display(mst_mat);
}
void test2()
{
    init(mat);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 0)
                mat[i][j]--;
        }
    kruskal_mst();
    int cost = 0;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            if (mst_mat[i][j] > -1)
                cost += mst_mat[i][j];
        }
    cout << cost;
}

int main()
{
    test2();
    return 0;
}
/*
6 8
1 2 10
2 3 6
1 4 8
1 5 7
2 6 5
3 6 8
4 5 3
5 6 9

4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0



-1
-1 6
-1 -1 -1
7 -1 -1 3
-1 5 -1 -1 9

30

-1
-1 6
-1 -1 -1
7 -1 -1 3
-1 5 -1 -1 9

30
*/