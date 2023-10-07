#include <bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

void pre_order(tree_node *root)
{
    if (!root)
        return;

    cout << root->val << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(tree_node *root)
{
    if (!root)
        return;

    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

void post_order(tree_node *root)
{
    if (!root)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->val << " ";
}

void pre_order_no_recur(tree_node *root)
{
    if (!root)
        return;

    stack<tree_node *> s;
    s.push(root);
    while (!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root->val << " ";
        if (root->right)
            s.push(root->right);
        if (root->left)
            s.push(root->left);
    }
}

void in_order_no_recur(tree_node *root)
{
    if (!root)
        return;

    stack<tree_node *> s;
    while (!s.empty() || root)
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            cout << root->val << " ";

            root = root->right;
        }
    }
}

void post_order_no_recur(tree_node *root)
{
    if (!root)
        return;

    stack<tree_node *> s1, s2;
    s1.push(root);

    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);

        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

void morris(tree_node *root)
{
    if (!root)
        return;

    tree_node* cur = root;
    tree_node* rightest = NULL;
    while (cur)
    {
        rightest = cur->left;
        if (rightest)
        {
            while (rightest->right != NULL && rightest->right != cur)
            {
                rightest = rightest->right;
            }
            
            if (!rightest->right)
            {
                rightest->right = cur;
                cur = cur->left;
                continue;
            } 
            else
            {
                rightest->right = NULL;
            }
        }
        cout << cur->val << " ";
        cur = cur->right;
    }
    
}

int main()
{
    tree_node *root = randomly_tree(10, 10);

    cout << "先序：" << endl;
    pre_order(root);
    cout << endl;
    pre_order_no_recur(root);
    cout << endl;

    cout << "中序：" << endl;
    in_order(root);
    cout << endl;
    in_order_no_recur(root);
    cout << endl;

    cout << "后序：" << endl;
    post_order(root);
    cout << endl;
    post_order_no_recur(root);
    cout << endl;

    cout << "morris中序：" << endl;
    morris(root);
    cout << endl;

    free_tree(root);
    return 0;
}
