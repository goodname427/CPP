#include <iostream>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];

void init(int n)
{
    for (int i = 0; i < n; i++)   
        for (auto j = 0; j < n; j++)
            mat[i][j] = -1;
}

void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int m, n; // n 节点数 m 边数
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        mat[x - 1][y - 1] = w;
        mat[y - 1][x - 1] = w;
    }
    display(n);

    return 0;
}