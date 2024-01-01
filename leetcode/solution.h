#include <bits/stdc++.h>
using namespace std;

struct node
{
    string val;
    node *parent;
    double weight;
    
    node(string val) : node(val, this, 1)
    {}
    node(string val, node *parent, double weight) : val(val), parent(parent), weight(weight)
    {}
};

class union_find_set
{
private:
    unordered_map<string, node *> _reflect;

    node *get_root(node *n)
    {
        vector<node *> path; 

        while (n->parent != n)
        {
            path.push_back(n);
            n = n->parent;
        }

        for (int i = path.size() - 2; i >= 0; i--)
        {
            path[i]->weight *= path[i]->parent->weight;
            path[i]->parent = n;
        }

        return n;
    }

public:
    void insert(const string &val)
    {
        if (!contains(val))
            _reflect.insert({val, new node(val)});
    }

    bool contains(const string &val)
    {
        return _reflect.count(val);
    }

    bool is_same(const string &a, const string &b)
    {
        if (!contains(a) || !contains(b))
            return false;

        return get_root(_reflect[a]) == get_root(_reflect[b]);
    }

    void union_set(const string &a, const string &b, int weight)
    {
        if (!contains(a) || !contains(b))
            return;
        
        node *a_node = _reflect[a];
        node *a_root = get_root(a_node);
        node *b_node = _reflect[b];
        node *b_root = get_root(b_node);

        if (a_root == b_root)
            return;
        
        a_root->parent = b_root;
        a_root->weight = weight * b_node->weight / a_node->weight;
    }

    double path(const string &val)
    {
        node *n = _reflect[val];
        double res = 1;
        while (n->parent != n)
        {
            res *= n->weight;
            n = n->parent;
        }

        return res;
    }

    void print()
    {
        for (auto p : _reflect)
        {
            cout << p.second->val << " " << p.second->parent->val << " " << p.second->weight << endl;
        }
    }
};

class Solution {
public:
    vector<double> calcEquation(const vector<vector<string>>& equations, const vector<double>& values, const vector<vector<string>>& queries) 
    {
        union_find_set ufs;

        for (int i = 0; i < equations.size(); i++)
        {
            ufs.insert(equations[i][0]);
            ufs.insert(equations[i][1]);
            ufs.union_set(equations[i][0], equations[i][1], values[i]);
            ufs.print();
            cout << endl;
        }


        vector<double> res(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            string a = queries[i][0];
            string b = queries[i][1];

            if (!ufs.is_same(a, b))
            {
                res[i] = -1;
            }
            else
            {
                res[i] = ufs.path(a) / ufs.path(b);
            }
        }
        
       
        return res;
    }
};

