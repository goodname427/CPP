#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int _map[MAX + 7][MAX + 7];
int n;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            _map[i][j] = 0;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> _map[i][j];
}

int main()
{
    init();
    input();
    int start;
    int minDistance = 250; //暂时给一个最大的不可能通过计算而出现的距离当作无穷大
    cin >> start;
    int min_i = 0; //三个用于保存路径名的变量
    int min_j = 0;
    int min_k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (i != start && j != i && j != start && k != j && k != start && k != i) //排除已经走过的点，避免重复
                {
                    int distance = _map[start][i] + _map[i][j] + _map[j][k] + _map[k][start];
                    if (minDistance > distance) //记录最短距离
                    {
                        minDistance = distance;
                        min_i = i;
                        min_j = j;
                        min_k = k;
                    }
                    cout << start << "->" << i << "->" << j << "->" << k << "->" << start << ",distance=" << distance << endl;
                }
            }
        }
    }
    cout << "最短路径为：" << start << "->" << min_i << "->" << min_j << "->" << min_k << "->" << start << ",distance=" << minDistance << endl;
    return 0;
}
/*
4
0 2 5 7
2 0 8 3
5 8 0 1
7 3 1 0
1
*/