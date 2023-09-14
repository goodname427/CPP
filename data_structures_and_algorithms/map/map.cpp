#include <bits/stdc++.h>
#include "../util/crand"
using namespace std;

#define EDGE_INF -1

class map_node;
class edge;

class map_node
{
public:
    int id;
    int val;
    int in;
    int out;

    vector<map_node *> nexts;
    vector<edge *> edges;

    map_node(int id) : map_node(0, id) {}
    map_node(int val, int id) : val(val), id(id)
    {
        in = 0;
        out = 0;
    }
};

class edge
{
public:
    static bool compare(const edge &e1, const edge &e2)
    {
        return e1.weight < e2.weight;
    }

    static bool compare(const edge *&e1, const edge *&e2)
    {
        return e1->weight < e2->weight;
    }

public:
    map_node *from;
    map_node *to;
    int weight;

    edge(map_node *from, map_node *to, int weight) : from(from),
                                                     to(to),
                                                     weight(weight)
    {
    }
};

class graph
{
public:
    unordered_map<int, map_node *> nodes;
    unordered_set<edge *> edges;

    graph() {}

    ~graph()
    {
        for (auto e : edges)
            delete e;
        for (auto n : nodes)
            delete n.second;
    }

    void insert_edge(int i, int j, int weight)
    {
        edge *e = new edge(nodes[i], nodes[j], weight);
        nodes[i]->out++;
        nodes[i]->edges.push_back(e);
        nodes[i]->nexts.push_back(nodes[j]);
        nodes[j]->in++;
        edges.insert(e);
    }

    vector<vector<int>> to_matrix()
    {
        return to_matrix(edges);
    }

    vector<vector<int>> to_matrix(unordered_set<edge *> edges)
    {
        vector<edge *> _edges;
        for (auto e : edges)
            _edges.push_back(e);
        return to_matrix(_edges);
    }
    
    vector<vector<int>> to_matrix(vector<edge *> edges)
    {
        unordered_map<int, map_node *>::iterator max_ele = max_element(nodes.begin(), nodes.end());
        int size = max_ele == nodes.end() ? 0 : max_ele->first + 1;
        vector<vector<int>> mat(size, vector<int>(size, EDGE_INF));
        for (auto e : edges)
        {
            mat[e->from->id][e->to->id] = e->weight;
        }
        return mat;
    }
};

graph *randomly_map(int max_size, int max_value, bool is_disdirect_map = true)
{
    int size = random(max_size);
    graph *g = new graph;

    // 新建节点
    for (int i = 0; i < size; i++)
        g->nodes.insert(pair<int, map_node *>(i, new map_node(random(max_value) + 1, i)));

    for (int i = 0; i < size; i++)
    {
        for (int j = is_disdirect_map ? i + 1 : 0; j < size; j++)
        {
            if (i == j || random(100) < 50)
                continue;

            // 插入对应的边
            int weight = random(max_value);
            g->insert_edge(i, j, weight);

            if (is_disdirect_map)
            {
                g->insert_edge(j, i, weight);
            }
        }
    }
    return g;
}

void print(const vector<vector<int>> &mat)
{
    string space_head = "  ";
    string p = "%3d ";
    string p2 = "%3s ";
    for (int i = 0; i < mat.size(); i++)
    {
        if (!i)
        {
            printf(p2.c_str(), "");
            for (int j = 0; j < mat[i].size(); j++)
            {
                printf(p.c_str(), j);
            }
            cout << endl;
        }
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (!j)
                printf(p.c_str(), i);

            if(mat[i][j] == EDGE_INF)
                printf("  _ ");
            else
                printf(p.c_str(), mat[i][j]);
        }
        cout << endl;
    }
}
