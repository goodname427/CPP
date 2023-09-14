#include <bits/stdc++.h>
#include "map.cpp"
using namespace std;

edge *select_min_edge(unordered_set<edge *> &edges, unordered_set<map_node *> &selected)
{
    edge *min = NULL;
    for(auto e : edges)
    {
        if(selected.contains(e->to))
            continue;
        
        if(!min || e->weight < min->weight)
            min = e;
    }

    return min;
}

unordered_set<edge *> prim(graph *g)
{
    unordered_set<edge *> mst;
    if(!g->nodes[0])
        return mst;

    unordered_set<map_node *> selected;
    selected.insert(g->nodes[0]);

    unordered_set<edge *> edges;
    for(auto e : g->nodes[0]->edges)
        edges.insert(e);

    edge *min = select_min_edge(edges, selected);
    while (min)
    {
        // cout << endl;
        // print(g->to_matrix(mst));


        mst.insert(min);
        selected.insert(min->to);
        edges.erase(min); 
        for (auto e : min->to->edges)
        {
            edges.insert(e);
        }

        min = select_min_edge(edges, selected);
    }
    return mst;   
}

int main()
{
    graph *g = randomly_map(7, 100);
    print(g->to_matrix());
    cout << "prim:" << endl;
    print(g->to_matrix(prim(g)));
    return 0;
}
