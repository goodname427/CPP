#include <iostream>
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

bool equal(tree_node *root1, tree_node *root2)
{
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;
    if (root1 != NULL && root2 != NULL && root1->val != root2->val)
        return false;
    if (root1 == NULL && root2 == NULL)
        return true;
    return equal(root1->left, root2->left) && equal(root1->right, root2->right);
}

int main()
{
    string pre1, pre2;
    cin >> pre1 >> pre2;
    tree_node *root1 = creat_tree(pre1), *root2 = creat_tree(pre2);
    cout << (equal(root1, root2) ? "true" : "false");
}