#include <iostream>
#include <list>
#include <stack>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];
int mst_mat[MAX][MAX];
int dist[MAX][MAX];
int path[MAX][MAX];
int n;

void init(int mat[MAX][MAX], int init_val = -1)
{
    for (int i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            mat[i][j] = init_val;
}

void init(int tar_mat[MAX][MAX], int sour_mat[MAX][MAX])
{
    for (int i = 0; i < n; i++)
        for (auto j = 0; j < n; j++)
            tar_mat[i][j] = sour_mat[i][j];
}

void input_map_name()
{
    int m; // n 节点数 m 边数
    cin >> n >> m;
    init(mat, -1);              //初始化矩阵
    for (int i = 0; i < m; i++) //输入
    {
        int x, y, w;
        cin >> x >> y >> w;
        mat[x - 1][y - 1] = w;
    }
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

/*枚举顶点k ∈ [1,n]
    以顶点k为中介点，枚举所有顶点对i和j（i ∈ [1,n],j ∈1[1,n]）
        如果dis[i][k] + dis[k][j] <dis[i][j]成立
            赋值dis[i][j] = dis[i][k] + dis[k][j]
*/
void floyd()
{
    init(dist, mat);            //初始化dist数组
    for (int i = 0; i < n; i++) //初始化path数组
        for (int j = 0; j < n; j++)
            path[i][j] = i;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (i != j && dist[i][k] != -1 && dist[k][j] != -1 && (dist[i][k] + dist[k][j] < dist[i][j] || dist[i][j] == -1))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
}

void select_center()
{
    floyd();
    int *max_dist = new int[n];   //单行最大距离
    int *total_dist = new int[n]; //单行总距离
    for (int i = 0; i < n; i++)
    {
        max_dist[i] = dist[i][0]; //初始化
        total_dist[i] = dist[i][0];
        //获取总距离和最大距离
        for (int j = 1; j < n; j++)
        {
            if (max_dist[i] < dist[i][j])
                max_dist[i] = dist[i][j];
            if (i != j)
                total_dist[i] += dist[i][j];
        }
    }
    int center = 0;
    for (int i = 1; i < n; i++) //获取center
        if (max_dist[i] < max_dist[center] || (max_dist[i] == max_dist[center] && total_dist[i] < total_dist[center]))
            center = i;
    cout << "center:" << center + 1 << endl; //显示结果
    delete[] max_dist;
    delete[] total_dist;
}

int main()
{
    input_map_name();
    select_center();
    cout << "dist:" << endl;
    display(dist);
    cout << "path:" << endl;
    display(path);
    return 0;
}
/*
5 10
1 2 13
1 4 4
2 1 13
2 3 15
2 5 5
3 4 12
4 1 4
4 3 12
5 3 6
5 4 3


测试用例
4 8
1 2 2
2 3 3
1 3 6
3 1 7
3 4 1
4 3 12
1 4 4
4 1 5
dist
-1 2 5 5
2 -1 3 7
5 3 -1 10
5 7 10 -1
path
0 0 1 0
1 1 1 0
1 2 2 0
3 0 1 3
*/