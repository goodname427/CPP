#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

struct edge
{
    int from;
    int to;
    int weight;
};

int n, m;
edge e[MAX];

bool compare(const edge &l, const edge &r)
{
    return l.weight < r.weight;
}

void creat_mst()
{
    int i, j, *lt = new int[n], cost = 0;
    vector<edge> ve;
    for (i = 0; i < m; i++)
        ve.push_back(e[i]);
    for (i = 0; i < n; i++)
        lt[i] = i;
    sort(ve.begin(), ve.end(), compare);
    for (i = 0; i < n; i++)
    {
        vector<edge>::iterator edge = ve.begin();
        if (lt[edge->from] != lt[edge->to])
        {
            cost += edge->weight;
            int _lt = lt[edge->to];
            for (j = 0; j < n; j++)
                if (lt[j] == _lt)
                    lt[j] = lt[edge->from];
            ve.erase(edge);
        }
    }
    cout<<cost;
    delete[] lt;
}

int main()
{
    int i, j;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        e[i].from = x-1;
        e[i].to = y-1;
        e[i].weight = v;
    }
    creat_mst();
    return 0;
}
