#include <bits/stdc++.h>
using namespace std;
//关系矩阵
int mat[16][16];
//获取指定位
int get_bit(int offset, int val)
{
    return ((1 << (3 - offset)) & val) >> (3 - offset);
}
//建立当前节点与其他节点的边
void get_edge(int val)
{
    //判断是否合法
    if (get_bit(0, val) != get_bit(2, val) && (get_bit(1, val) == get_bit(2, val) || get_bit(2, val) == get_bit(3, val)))
        return;
    mat[val][8 ^ val] = 1;                      //农夫不带东西过河
    for (int i = 1; i < 4; i++)                 //农夫选择携带一样东西过河
        if (get_bit(i, val) == get_bit(0, val)) //判断这个东西是否和农夫在同一岸
            mat[val][8 ^ ((1 << (3 - i)) ^ val)] = 1;
}
//初始化边
void init_edge()
{
    for (int i = 0; i < 16; i++)
        get_edge(i);
}
//寻路
void find_way(int n, int start, int end)
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
        cout << bitset<4>(paths.top()) << (paths.size() > 1 ? "->" : "");
        paths.pop();
    }
    delete[] visited;
    delete[] path;
}

int main()
{
    init_edge();
    find_way(16, 0, 15);
    return 0;
}
