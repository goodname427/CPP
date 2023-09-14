#include <bits/stdc++.h>
#include "map.cpp"
using namespace std;

void bfs(map_node *node)
{
    if (!node)
        return;

    queue<map_node *> q;
    q.push(node);
    unordered_set<map_node *> visited;
    visited.insert(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        cout << node->id << "->";
        for (auto next : node->nexts)
        {
            if (visited.find(next) == visited.end())
            {
                q.push(next);
                visited.insert(next);
            }
        }
    }
    cout << "NULL" << endl;
}

void dfs_recur(map_node *node, unordered_set<map_node *> &visited)
{
    if(!node)
        return;

    cout << node->id << "->";
    visited.insert(node);

    for (auto next : node->nexts)
    {
        if (visited.find(next) == visited.end())
        {
            dfs_recur(next, visited);
        }
    }
}

void dfs_recur(map_node *node)
{
    if(!node)
        return;

    unordered_set<map_node *> visited;
    dfs_recur(node, visited);
    cout << "NULL" << endl;
}

void dfs(map_node *node)
{
    if(!node)
        return;

    unordered_set<map_node *> visited;
    stack<map_node *> s;

    s.push(node);
    cout << node->id << "->";
    visited.insert(node);

    while(!s.empty())
    {
        node = s.top();
        s.pop();

        for(auto next : node->nexts)
        {
            if(visited.find(next) == visited.end())
            {
                s.push(node);
                s.push(next);
                cout << next->id << "->";
                visited.insert(next);
                break;
            }
        }
    }
    cout << "NULL" << endl;
}

int main()
{
    graph *g = randomly_map(10, 10);
    cout << "matrix:" << endl;
    print(g->to_matrix());
    cout << "bfs:" << endl;
    bfs(g->nodes[0]);
    cout << "dfs recur:" << endl;
    dfs_recur(g->nodes[0]);
    cout << "dfs:" << endl;
    dfs(g->nodes[0]);
}
