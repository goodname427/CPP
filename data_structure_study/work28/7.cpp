#include <bits/stdc++.h>
using namespace std;

struct tree_node
{
    tree_node *left;
    tree_node *right;
    int val;
};

tree_node *creat_tree(string &pre)
{
    if (pre.length() <= 0)
        return NULL;
    int index = pre.find(',');
    string c = index == -1 ? pre : pre.substr(0, index);
    pre = index == -1 ? "" : pre.substr(index + 1, pre.length() - index - 1);
    if (c[0] == '#')
        return NULL;

    tree_node *root = new tree_node;
    root->val = atoi(c.c_str());
    root->left = creat_tree(pre);
    root->right = creat_tree(pre);
    return root;
}

int get_depth(tree_node *root)
{
    if (root == NULL)
        return 0;
    int l = get_depth(root->left);
    int r = get_depth(root->right);
    return max(l, r) + 1;
}

bool is(tree_node *root)
{
    return root == NULL || (abs(get_depth(root->left) - get_depth(root->right)) <= 1 && is(root->left) && is(root->right));
}

int main()
{
    string pre;
    cin >> pre;
    tree_node *root = creat_tree(pre);
    cout << (is(root) ? "true" : "false");
    return 0;
}
