#include <bits/stdc++.h>
#include "../util/cvectorop"
using namespace std;

struct tree_node
{
    int val;
    tree_node *left;
    tree_node *right;
    // 为了兼容，经典二叉树没有父节点
    tree_node *parent;
};

tree_node *new_tree_node(int val = 0, tree_node *left = NULL, tree_node *right = NULL, tree_node *parent = NULL)
{
    tree_node *node = new tree_node;
    node->val = val;
    node->left = left;
    node->right = right;
    node->parent = parent;
    return node;
}

tree_node *build_tree(queue<int> &q)
{
    if (q.empty() || !q.front())
        return NULL;

    tree_node *root = new_tree_node(q.front() - 1);
    q.pop();
    queue<tree_node *> bq;
    bq.push(root);

    tree_node *cur = NULL;
    while (!bq.empty())
    {
        cur = bq.front();
        bq.pop();

        if (q.empty())
            break;
        if (q.front())
        {
            cur->left = new_tree_node(q.front() - 1);
            cur->left->parent = cur;
            bq.push(cur->left);
        }
        q.pop();

        if (q.empty())
            break;
        if (q.front())
        {
            cur->right = new_tree_node(q.front() - 1);
            cur->right->parent = cur;
            bq.push(cur->right);
        }
        q.pop();
    }
    return root;
}

tree_node *randomly_tree(int max_size, int max_value)
{
    vector<int> vec = randomly_vec(max_size, max_value);
    queue<int> q;
    for (auto node : vec)
    {
        if (random(100) < 10)
            node = 0;
        q.push(node);
    }
    return build_tree(q);
}

void free_tree(tree_node *root)
{
    if (!root)
        return;

    free_tree(root->left);
    free_tree(root->right);

    delete root;
}

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

void print_in_order(tree_node *root, int height, string to, int len)
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

void print_tree(tree_node *root)
{
    cout << "Binary Tree:" << endl;
    print_in_order(root, 0, "H", 17);
    cout << endl;
}
