#include <bits/stdc++.h>
using namespace std;

struct tree_node
{
    tree_node *left;
    tree_node *right;
    int val;
};

int sum;

tree_node *creat()
{
    string c;
    cin >> c;
    if (c[0] == '#')
        return NULL;

    tree_node *root = new tree_node;
    root->val = atoi(c.c_str());
    root->left = creat();
    root->right = creat();
    return root;
}

bool path(tree_node *root, int _sum)
{
    if (root == NULL)
        return false;
    _sum += root->val;
    if (_sum == sum)
        return true;
    if (_sum > sum)
        return false;
    return path(root->left, _sum) || path(root->right, _sum);
}

int main()
{
    tree_node *root = creat();
    cin >> sum;
    cout << (path(root, 0) ? "true" : "false");
    return 0;
}
