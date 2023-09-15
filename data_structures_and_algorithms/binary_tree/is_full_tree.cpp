#include <bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

int is_full_tree(tree_node *root, int &height)
{
    if(!root)
    {
        height = 0;
        return 0;
    }

    int lh, rh;
    int lc = is_full_tree(root->left, lh);
    int rc = is_full_tree(root->right, rh);
    height = max(lh, rh) + 1;
    return lc + rc + 1;
}

bool is_full_tree(tree_node *root)
{
    int height = 0;
    return is_full_tree(root, height) == ((1 << height) - 1);
    // bool res = count ;
    // if(res)
    //     cout << count << " " << height << endl;
    // return res;
}


int main()
{
    // int t = 1000000;
    // while(t--)
    // {
    //     tree_node *root = randomly_tree(10, 10);
    //     bool res = is_full_tree(root);
    //     if(res && root && root->left)
    //         print_tree(root);
    // }
    tree_node *root = new_tree_node(1);
    root->left = new_tree_node(2);
    root->right = new_tree_node(3);
    root->left->left = new_tree_node(4);
    root->left->right = new_tree_node(5);
    root->right->left = new_tree_node(6);
    root->right->right = new_tree_node(7);
    print_tree(root);
    cout << is_full_tree(root) << endl;
    free_tree(root);
    return 0;
}
