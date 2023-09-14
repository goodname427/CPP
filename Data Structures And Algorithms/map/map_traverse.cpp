#include <bits/stdc++.h>
#include "map.cpp"
using namespace std;

void bst(map_node *node)
{
    if(!node)
        return;

    queue<map_node *> q;
    q.push(node);
    unordered_set<map_node *> visited;
    visited.insert(node);
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        cout << node->id << " ";
        for(auto next : node->nexts)
        {
            if(visited.find(next) == visited.end())
            {
                q.push(next);
                visited.insert(node);
            }
        }
    }
}

int main()
{
    graph *g = randomly_map(10, 10);
    cout << "matrix:" << endl;
    print(g->to_matrix());
    cout << "bst:";
    bst(g->nodes[0]);
}
