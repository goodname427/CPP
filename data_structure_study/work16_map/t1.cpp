#include <iostream>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];

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
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x - 1][y - 1] = 1;
        mat[y - 1][x - 1] = 1;
    }
    display(n);

    return 0;
}