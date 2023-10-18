#include <bits/stdc++.h>
#include "st.cpp"
#include "../util/crand"
using namespace std;

string get_space(int num)
{
    string space = " ";
    string buf = "";
    for (int i = 0; i < num; i++)
    {
        buf += space;
    }
    return buf;
}

void print_in_order(st_node *root, int height, string to, int len)
{
    if (!root)
    {
        return;
    }
    print_in_order(root->right, height + 1, "v", len);
    string val = to + to_string(root->val) + to;
    int lenM = val.length();
    int lenL = (len - lenM) / 2;
    int lenR = len - lenM - lenL;
    val = get_space(lenL) + val + get_space(lenR);
    cout << get_space(height * len) + val << endl;
    print_in_order(root->left, height + 1, "^", len);
}

void print(st_node *root, string tips = "")
{
    cout << "Binary Tree: " << tips << endl;
    print_in_order(root, 0, "H", 17);
    cout << endl;
}

bool is_st(st_node *root, int &out_min, int &out_max)
{
    if (!root)
    {
        out_max = INT_MAX;
        out_min = INT_MIN;
        return true;
    }

    out_max = root->val;
    out_min = root->val;

    int _max, _min, res;
    if (root->left)
    {
        res = is_st(root->left, _min, _max);
        if (!res || _max > root->val)
            return false;

        out_min = min(_min, out_min);
    }
    if (root->right)
    {
        res = is_st(root->right, _min, _max);
        if (!res || _min < root->val)
            return false;

        out_max = min(_max, out_max);
    }

    return true;
}

bool is_st(st_node *root)
{
    int a, b;
    return is_st(root, a, b);
}

int main()
{
    int temp;
    int node_count = 10;
    st_node *root = new st_node(node_count / 2);
    unordered_set<int> set{node_count / 2};

    // insert
    for (int i = 1; i < node_count; i++)
    {
        do
        {
            temp = random(node_count);
        } while (set.contains(temp));
        set.insert(temp);

        root->insert(temp);
    }
    print(root, "init");

    // find
    // while (cin >> temp)
    // {
    //     st_node *res = root->find(temp);
    //     cout << (res) << endl;
    // }

    // erase
    // while (cin >> temp)
    // {
    //     root = root->erase(temp);
    //     root->print();
    // }
    // while (!set.empty())
    // {
    //     root = root->erase(*set.begin());
    //     if (!is_st(root))
    //     {
    //         print(root, "error");
    //         break;
    //     }
    //     set.erase(set.begin());
    // }

    // rotate
    // while (cin >> temp)
    // {
    root = root->rotate_left();
    print(root);
    root = root->rotate_right();
    print(root);
    // }

    delete root;
    return 0;
}
