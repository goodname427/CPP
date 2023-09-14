#include <bits/stdc++.h>
using namespace std;

struct tree_node
{
    char val;
    tree_node *left;
    tree_node *right;
};

tree_node *creat_tree()
{
    char c;
    cin >> c;
    if (c == '#')
        return NULL;
    auto root = new tree_node;
    root->val = c;
    root->left = creat_tree();
    root->right = creat_tree();
    return root;
}

void post(tree_node *root)
{
    if (root == NULL)
        return;
    post(root->left);
    post(root->right);
    cout << root->val;
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        tree_node *root = creat_tree();
        post(root);
    }
    return 0;
}
/*
1
A B # D # # C # #
DBCA
*/
