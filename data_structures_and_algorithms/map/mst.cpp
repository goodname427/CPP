#include <bits/stdc++.h>
#include "map.cpp"
using namespace std;

graph *prim(graph *g)
{
    unordered_set<edge *> mst;
    if (!g->nodes.size())
        return g->rebuild(mst);

    // 记录已经选择的节点
    unordered_set<map_node *> selected;
    selected.insert(g->nodes[0]);

    // 添加 新节点 发散的边
    unordered_set<edge *> edges;
    for (auto e : g->nodes[0]->edges)
        edges.insert(e);

    while (!edges.empty())
    {
        // 获取最小边
        edge *min = *min_element(edges.begin(), edges.end(), edge::compare2);
        edges.erase(min);

        // 判断最小边是否会形成环
        if (selected.contains(min->to))
            continue;

        // 将边从缓冲区移到结果区
        mst.insert(min);

        // 记录新节点
        selected.insert(min->to);
        // 添加新节点发散出的边
        for (auto e : min->to->edges)
        {
            edges.insert(e);
        }
    }
    return g->rebuild(mst);
}

graph *kruskal(graph *g)
{
    unordered_set<edge *> mst;
    if (!g->nodes.size())
        return g->rebuild(mst);

    // 建立连通域, 开始时每个节点为一个单独的连通域
    unordered_map<map_node *, unordered_set<map_node *> *> conn;
    for (auto n : g->nodes)
        conn.insert(pair<map_node *, unordered_set<map_node *> *>(n.second, new unordered_set<map_node *>{n.second}));

    // 添加所有边
    unordered_set<edge *> edges;
    for (auto e : g->edges)
        edges.insert(e);

    while (!edges.empty())
    {
        // 获取最小边
        auto min = *min_element(edges.begin(), edges.end(), edge::compare2);
        edges.erase(min);

        auto from_set = conn[min->from];
        auto to_set = conn[min->to];

        // 判断最小边是否会形成环
        if (from_set == to_set)
            continue;

        // 将边从缓冲区移到结果区
        mst.insert(min);

        // 合并两个连通域
        for (auto n : *to_set)
        {
            conn[n] = from_set;
            from_set->insert(n);
        }
        delete to_set;
    }
    
    delete conn.begin()->second;

    return g->rebuild(mst);
}

void topology_sort(graph *g)
{
    if(!g->nodes.size())
        return;

    unordered_map<map_node *, int> in;
    queue<map_node *> q;

    // 获取所有节点的入度, 并将入度为零的节点入队
    for(auto n : g->nodes)
    {
        in.insert(pair<map_node *, int>(n.second, n.second->in));
        if(!n.second->in)
            q.push(n.second);
    }

    while(!q.empty())
    {
        cout << q.front()->id << " ";
        // 消除出队节点的影响, 然后将入度变为0的节点入队
        for(auto next : q.front()->nexts)
        {
            if(!--in[next])
            {
                q.push(next);
            }
        }
        q.pop();
    }
}

int main()
{
    graph *g = randomly_map(10, 100);

    while (g->nodes.size() < 4)
    {
        delete g;
        g = randomly_map(10, 100);
    }

    cout << "matrix:" << endl;
    print(g);
    
    graph* mst_prim = prim(g);
    cout << "prim:" << endl;
    print(mst_prim);
    
    graph *mst_kruskal = kruskal(g);
    cout << "kruskal:" << endl;
    print(mst_kruskal);

    cout << "topology sort:" << endl;
    topology_sort(mst_prim);

    delete g;
    delete mst_prim;
    delete mst_kruskal;
    return 0;
}
