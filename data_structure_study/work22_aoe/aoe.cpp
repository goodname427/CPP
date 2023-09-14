#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
//边
struct edge
{
    int from;
    int to;
    int weight;
};
//最早最晚开始时间
struct start
{
    int early;
    int late;
};

int mat[MAX][MAX];     //原始矩阵
int to_aoe[MAX];       //拓扑排序后节点对应的顺序 to_aoe[0]对应排序后位于首位的节点编号
int key_mat[MAX][MAX]; //关键活动矩阵
edge edges[MAX];       //边集
int n;                 //节点数
int m;                 //边数

void init(int mat[MAX][MAX])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = -1;
}

void input_map()
{
    cin >> n >> m;
    init(mat);                  //初始化矩阵
    for (int i = 0; i < m; i++) //输入
    {
        int x, y, w;
        cin >> x >> y >> w;
        mat[x - 1][y - 1] = w;
        edges[i] = {x - 1, y - 1, w};
    }
}
//展示开始时间数组
void display(start *array, int n)
{
    cout << "最早时间：";
    for (int i = 0; i < n; i++)
        cout << array[i].early << " ";
    cout << endl
         << "最晚时间：";
    for (int i = 0; i < n; i++)
        cout << array[i].late << " ";
    cout << endl;
}
//获取关键路径
void get_key_path()
{
    int *key_path = new int[m]; //关键路径
    int *visited = new int[n];  //记录节点是否访问
    for (int i = 0; i < n; i++) //初始化
    {
        visited[i] = 0;
        key_path[i] = 0;
    }
    queue<int> q;
    q.push(to_aoe[0]); // push起点
    visited[to_aoe[0]] = 1;
    key_path[to_aoe[0]] = -1;
    while (!q.empty())
    {
        bool has_found = false;
        for (int i = 0; i < n; i++)                    //遍历寻找下一个节点
            if (mat[q.front()][i] > -1 && !visited[i]) //如果某节点与当前节点连接且未访问则push该节点
            {
                q.push(i);
                key_path[i] = q.front();
                visited[i] = 1; //记录该节点已访问
                if (i == to_aoe[n - 1])
                    has_found = true;
            }
        if (has_found)
            break;
        q.pop();
    }
    //输出路径
    int cur = to_aoe[n - 1];
    stack<int> paths;
    while (cur != -1)
    {
        paths.push(cur);
        cur = key_path[cur];
    }
    cout << "path:";
    while (!paths.empty())
    {
        cout << paths.top() + 1 << (paths.size() > 1 ? "->" : "");
        paths.pop();
    }

    delete[] visited;
    delete[] key_path;
}
//拓扑排序
void aov_sort()
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
        to_aoe[count++] = v;        //计数器+1
        for (int i = 0; i < n; i++) //重置其他边的入度
            if (mat[v][i] != -1)
                if ((--in[i]) == 0) //若重置后的节点的入度为0，则节点入栈
                    s.push(i);
    }
    delete[] in;
}

void aoe()
{
    aov_sort();
    start *event = new start[n];    //事件最早最晚开始时间 节点
    start *activity = new start[m]; //活动最早最晚开始时间 边
    int *key_activity = new int[m]; //关键活动
    int key_count = 0;              //关键活动数量

    event[to_aoe[0]].early = 0; //设置初始事件最早时间
    for (int k = 1; k < n; k++) //获取每个事件最早开始时间
    {
        int vmax = 0;               //最大值
        for (int j = 0; j < n; j++) //获取最大值
            if (mat[j][to_aoe[k]] != -1 && event[j].early + mat[j][to_aoe[k]] > vmax)
                vmax = event[j].early + mat[j][to_aoe[k]];
        event[to_aoe[k]].early = vmax;
    }
    event[to_aoe[n - 1]].late = event[to_aoe[n - 1]].early; //设置结束事件最晚开始时间
    for (int k = n - 2; k > -1; k--)                        //获取每个事件最晚开始时间
    {
        int vmin = -1;              //最小值
        for (int j = 0; j < n; j++) //获取最小值
            if (mat[to_aoe[k]][j] != -1 && (event[j].late - mat[to_aoe[k]][j] < vmin || vmin == -1))
                vmin = event[j].late - mat[to_aoe[k]][j];
        event[to_aoe[k]].late = vmin;
    }
    for (int i = 0; i < m; i++) //获取活动最早最晚开始时间并且添加关键活动
    {
        activity[i].early = event[edges[i].from].early;               //活动最早时间为起始时间的最早时间
        activity[i].late = event[edges[i].to].late - edges[i].weight; //活动的最晚时间是结束事件的最晚时间减去活动的时间
        if (activity[i].late == activity[i].early)                    //判断活动是否为关键活动
            key_activity[key_count++] = i;
    }
    cout << "事件开始时间：" << endl;
    display(event, n);
    cout << "活动开始时间：" << endl;
    display(activity, m);
    //获取关键活动矩阵
    cout << "关键活动：" << endl;
    init(key_mat);
    for (int i = 0; i < key_count; i++)
    {
        key_mat[edges[key_activity[i]].from][edges[key_activity[i]].to] = edges[key_activity[i]].weight;
        cout << "(" << edges[key_activity[i]].from + 1 << "," << edges[key_activity[i]].to + 1 << ")" << edges[key_activity[i]].weight << endl;
    }
    get_key_path(); //获取关键路径
    delete[] key_activity;
    delete[] activity;
    delete[] event;
}

int main()
{
    input_map();
    aoe();
    return 0;
}
/*测试用例
1<->2 3<->4 8<->9
9 11
2 1 6
2 4 4
2 3 5
1 5 1
4 5 1
3 6 2
5 7 9
5 9 7
6 9 4
7 8 2
9 8 4

9 11
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
*/
