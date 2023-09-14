#include <bits/stdc++.h>
using namespace std;

//灰度矩阵转灰度直方图
vector<int> get_gray_histogram(vector<vector<int>> &gray_matrix, int l)
{
    vector<int> gray_histogram(l, 0);
    for (auto row : gray_matrix)
        for (auto e : row)
            gray_histogram[e]++;
    return gray_histogram;
}

int main()
{
    int n, m, l;
    //输入
    cin >> n >> m >> l;
    vector<vector<int>> gray_matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> gray_matrix[i][j];
    //输出
    for (auto e : get_gray_histogram(gray_matrix, l))
        cout << e << " ";
    return 0;
}
