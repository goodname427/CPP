#include <bits/stdc++.h>
#include "map.cpp"
using namespace std;

unordered_map<map_node *, int> dijkstra(graph *g, map_node *node)
{
    unordered_map<map_node *, int> distance;
    if (!g->nodes.size() || !node)
        return distance;

    unordered_set<map_node *> selected;
    distance.insert(pair<map_node *, int>(node, 0));

    map_node *min_node = NULL;
    int min_distance = 0;
    while (1)
    {
        // 选取距离最近且没有被选择的点
        min_node = NULL;
        for (auto n : distance)
        {
            if (!selected.contains(n.first) && (!min_node || n.second < min_distance))
            {
                min_node = n.first;
                min_distance = n.second;
            }
        }

        if (!min_node)
            break;

        selected.insert(min_node);

        // 更新该节点相邻节点的最小距离
        for (auto e : min_node->edges)
        {
            int next_distance = min_distance + e->weight;
            // 如果节点不存在则说明其当前距离为无限远, 直接插入, 否则则新的距离与当前距离选择最小值
            if (!distance.contains(e->to))
                distance.insert(pair<map_node *, int>(e->to, next_distance));
            else if (next_distance < distance[e->to])
                distance[e->to] = next_distance;
        }
    }

    return distance;
}

int main()
{
    graph *g = randomly_map(7, 30);
    cout << "matrix:" << endl;
    print(g);

    if (g->nodes.size())
    {
        map_node *node = g->nodes[random(g->nodes.size())];
        auto distance = dijkstra(g, node);
        for (auto dis : distance)
        {
            cout << node->id << " -> " << dis.first->id << " = " << dis.second << endl;
        }
    }

    delete g;
    return 0;
}
