#include <bits/stdc++.h>
using namespace std;

#define MAX 105

int m;
int n;
char mat[MAX][MAX];
bool visited[MAX][MAX];

struct point
{
    pair<int, int> pos;
    int g; //移动代价
    int h; //预估代价
    int f; //总代价
};

struct node
{
    point data;              //存储点
    node *parent;            //父节点
    vector<node *> children; //孩子节点
};

//判断指定点p是否符合评估条件
bool is_valid(point p)
{
    //可以评估的条件为 点p没有访问过，点p不是障碍物，点p在地图内
    return !(visited[p.pos.first][p.pos.second] || mat[p.pos.first][p.pos.second] == '#' || p.pos.first < 0 || p.pos.first >= n || p.pos.second < 0 || p.pos.second >= m);
}
//获取指定点p的预估代价
int get_h(point p, point end)
{
    int x = end.pos.first - p.pos.first;
    int y = end.pos.second - p.pos.second;
    return (int)sqrt(x * x + y * y); //预估代价为点p与终点的直线距离
}
//获取父节点parent指定方向d的点child，如果该点满足评估条件则返回true，否则返回false
bool get_point(point parent, point &child, point end, int d)
{
    child.pos = parent.pos;
    switch (d) //将点child的位置向指定方向移动
    {
    case 0:
        child.pos.second++;
        break;
    case 1:
        child.pos.second--;
        break;
    case 2:
        child.pos.first--;
        break;
    case 3:
        child.pos.first++;
        break;
    }
    if (!is_valid(child)) //判断点child是否可以评估
        return false;
    //评估点child的代价
    child.g = parent.g + 1;      //移动代价，表示从起点移动到该点所付出的代价
    child.h = get_h(child, end); //获取预估代价
    child.f = child.g + child.h; //总代价为两者之和
    return true;
}

int find(point start, point end)
{
    node *current = new node; //表示当前节点
    vector<node *> open_list; //待评估节点列表
    //初始化起点
    current->data = start;
    current->parent = NULL;
    visited[start.pos.first][start.pos.second] = true;
    //不断移动当前节点直到当前节点的位置与终点重合
    while (current->data.pos != end.pos)
    {
        for (int i = 0; i < 4; i++) //分别朝四个方向获取子节点
        {
            point child;
            if (get_point(current->data, child, end, i)) //获取子节点
            {
                //初始化子节点
                node *new_node = new node;
                new_node->data = child;
                new_node->parent = current;
                current->children.push_back(new_node);
                open_list.push_back(new_node);
            }
        }
        //获取当前待评估节点中总代价最小的节点min
        vector<node *>::iterator min = open_list.begin();
        for (vector<node *>::iterator it = min + 1; it != open_list.end(); it++)
        {
            if ((*it)->data.f < (*min)->data.f)
                min = it;
        }
        //将当前节点移动到该节点min
        current = *min;
        open_list.erase(min);
        visited[current->data.pos.first][current->data.pos.second] = true;
    }
    //显示最终结果路径
    int sum = 0;
    while (current->parent != NULL)
    {
        printf("(%d,%d)<-", current->data.pos.first, current->data.pos.second);
        sum++;
        current = current->parent;
    }
    return sum;
}

int main()
{
    point start, end;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            //获取起点和终点
            if (mat[i][j] == 'S')
                start.pos = pair(i, j);
            else if (mat[i][j] == 'T')
                end.pos = pair(i, j);
        }
    }
    cout << find(start, end);
    return 0;
}
/*
3 3
S#T
.#.
...
6

10 10
S#........
.#........
..........
##........
...#######
#.........
#.#######.
#.#.......
#.#.#####.
###......T
*/