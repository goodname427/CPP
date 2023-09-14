#include <bits/stdc++.h>
using namespace std;

struct tree
{
    tree *left;
    tree *right;
    int val;
};

tree *creat(string &pre)
{
    if (pre.length() <= 0)
        return NULL;
    int index = pre.find(' ');
    string c = index == -1 ? pre : pre.substr(0, index);
    pre = index == -1 ? "" : pre.substr(index + 1, pre.length() - index - 1);

    if (c[0] == '#')
        return NULL;
    tree *root = new tree;
    root->val = atoi(c.c_str());
    root->left = creat(pre);
    root->right = creat(pre);
    return root;
}

bool equal(tree *left, tree *right)
{
    if (left != NULL && right == NULL)
        return false;
    if (left == NULL && right != NULL)
        return false;
    if (left != NULL && right != NULL && left->val != right->val)
    {
        cout<<left->val<<" "<<right->val<<endl;
        return false;
    }
    if (left == NULL && right == NULL)
        return true;
    return equal(left->left, right->right) && equal(left->right, right->left);
}

int main()
{
    string str;
    getline(cin ,str);
    tree *root = creat(str);
    cout << (root == NULL ? "true" : (equal(root->left, root->right) ? "true" : "false"));
    return 0;
}
