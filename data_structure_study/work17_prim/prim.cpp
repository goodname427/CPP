#include <iostream>
#include <list>
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
/*
1.将连通网中的所有顶点分为两类（假设为 A 类和 B 类）。初始状态下，所有顶点位于 B 类；
2.选择任意一个顶点，将其从 B 类移动到 A 类；
3.从 B 类的所有顶点出发，找出一条连接着 A 类中的某个顶点且权值最小的边，将此边连接着的 A 类中的顶点移动到 B 类；
4.重复执行第 3  步，直至 B 类中的所有顶点全部移动到 A 类，恰好可以找到 N-1 条边。
*/
void prim_mst()
{
    init(mst_mat);              //初始化生成树矩阵
    list<int> map, mst;         //未连接生成树的顶点map,连接生成树的节点mst
    for (int i = 0; i < n; i++) //将图中所有顶点加入到map中
        map.push_back(i);
    mst.push_back(map.front()); //从map取出一个顶点至mst中
    map.pop_front();
    while (!map.empty())
    {
        list<int>::iterator from, to;                      //记录两个节点
        int weight = -1;                                   //记录边的权值
        for (auto it = map.begin(); it != map.end(); it++) //寻找权值最小的连接mst与map中某两个节点的边
            for (auto _it = mst.begin(); _it != mst.end(); _it++)
            {
                int _weight = mat[*it][*_it];
                if (_weight > -1 && (_weight < weight || weight == -1))
                {
                    from = it;
                    to = _it;
                    weight = _weight;
                }
            }
        mst_mat[*from][*to] = weight; //记录在mst矩阵
        mst_mat[*to][*from] = weight;
        mst.push_back(*from); //将from节点从map中移至mst中
        map.erase(from);
    }
}
//优化版
void _prim_mst(int v = 0)
{
    init(mst_mat);              //初始化生成树矩阵
    list<edge> map;             //未连接生成树的顶点集map
    for (int i = 0; i < n; i++) //将图中所有顶点加入到map中
        if (i != v)
            map.push_back({i, v, mat[i][v]});
    while (!map.empty())
    {
        auto it = map.begin();
        auto min = it++;              //记录到生成树距离最短的节点
        for (; it != map.end(); it++) //寻找最短边
            if (it->weight > -1 && (it->weight < min->weight || min->weight == -1))
                min = it;
        for (it = map.begin(); it != map.end(); it++) //重新获取所有节点到生成树的最短边
        {
            int _weight = mat[it->from][min->from];
            if (it != min && _weight > -1 && (_weight < it->weight || it->weight == -1))
            {
                it->to = min->from;
                it->weight = _weight;
            }
        }
        mst_mat[min->from][min->to] = min->weight; //记录
        mst_mat[min->to][min->from] = min->weight;
        map.erase(min); //删除该节点
    }
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
    _prim_mst();
    display(mst_mat);
    cout << endl;
    _prim_mst(3);
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
    _prim_mst();
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
    test1();
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
*/