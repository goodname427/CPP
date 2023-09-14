#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];
string names[MAX];
int n;

void init()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = -1;
}

int get_index(string name)
{
    for (int i = 0; i < n; i++)
        if (names[i] == name)
            return i;
    return -1;
}

void input_map_name()
{
    int m; // n 节点数 m 边数
    cin >> n >> m;
    init();                     //初始化矩阵
    for (int i = 0; i < n; i++) //记录名称与节点的键值对
    {
        string name;
        cin >> name;
        names[i] = name;
    }
    for (int i = 0; i < m; i++) //输入边
    {
        string name1, name2;
        cin >> name1 >> name2;
        mat[get_index(name1)][get_index(name2)] = 1;
    }
}

void input_map()
{
    int m; // n 节点数 m 边数
    cin >> n >> m;
    init();                     //初始化矩阵
    for (int i = 0; i < m; i++) //输入
    {
        int x, y;
        cin >> x >> y;
        mat[x - 1][y - 1] = 1;
    }
}

void aov_sort(bool is_name)
{
    int *in = new int[n]; //记录入度
    stack<int> s;
    int count = 0;                   //计数器
    for (int i = n - 1; i >= 0; i--) //初始化入度
    {
        in[i] = 0;
        for (int j = 0; j < n; j++)
            if (mat[j][i] != -1)
                in[i]++;
        if (in[i] == 0) //如果入度为0则入栈
            s.push(i);
    }
    while (!s.empty())
    {
        int v = s.top(); //获取栈顶元素
        s.pop();
        if (is_name)
            cout << names[v] << " "; //输出
        else
            cout << v + 1 << " ";   //输出
        count++;                    //计数器+1
        for (int i = 0; i < n; i++) //重置其他边的入度
            if (mat[v][i] != -1)
                if ((--in[i]) == 0) //若重置后的节点的入度为0，则节点入栈
                    s.push(i);
    }
    if (count < n) //如果计数器小于总节点数则说明有回路
        cout << endl
             << "有回路" << endl;
    delete[] in;
}

int main()
{
    input_map();
    aov_sort(false);
    return 0;
}
/*
6 8
1 2
1 4
1 5
5 6
2 3
2 6
6 3
4 5

12 16
程序设计基础
离散数学
数据结构
汇编语言
语言的设计与分析
计算机原理
编译原理
操作系统
高等数学
线性代数
普通物理
数值分析
程序设计基础 离散数学
程序设计基础 数据结构
离散数学 数据结构
程序设计基础 汇编语言
数据结构 语言的设计与分析
汇编语言 语言的设计与分析
普通物理 计算机原理
数据结构 编译原理
语言的设计与分析 编译原理
数据结构 操作系统
计算机原理 操作系统
高等数学 线性代数
高等数学 普通物理
程序设计基础 数值分析
高等数学 数值分析
线性代数 数值分析

7 10
3 1
4 1
4 2
6 2
5 3
5 4
7 4
6 4
7 5
7 6
*/
