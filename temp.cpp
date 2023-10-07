#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int happy;
    vector<node *> sub;

    node(int happy) : happy(happy)
    {

    }

    ~node()
    {
        for (auto s : sub)
        {
            delete s;
        }
        
    }
};

class info
{
public:
    int max_happy;
    int dont_come_max_happy;

    info(int max_happy, int dont_come_max_happy) : max_happy(max_happy), dont_come_max_happy(dont_come_max_happy)
    {
    }
};

info get_max_happy(node *root)
{
    if (root->sub.empty())
        return info(root->happy, 0);

    int come = root->happy;
    int dont_come = 0;

    for (auto s : root->sub)
    {
        info res = get_max_happy(s);
        come += res.dont_come_max_happy;
        dont_come += res.max_happy;
    }

    return info(max(come, dont_come), dont_come);
}

int main()
{
    int n, root;
    cin >> n >> root;
    vector<node *> nodes(n + 1);
    nodes[0] = NULL;
    for (int i = 1; i <= n; i++)
    {
        int happy;
        cin >> happy;
        nodes[i] = new node(happy);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        nodes[u]->sub.push_back(nodes[v]);
    }

    cout << get_max_happy(nodes[root]).max_happy << endl;

    delete nodes[root];
}
