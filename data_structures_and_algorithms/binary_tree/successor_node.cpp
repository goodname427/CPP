#include <bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;

int get_in_order_index(tree_node *root, tree_node *node, vector<tree_node *> &in_order)
{
    if (!root || !node)
        return -1;

    int l_index = get_in_order_index(root->left, node, in_order);

    in_order.push_back(root);
    int res = root == node ? in_order.size() - 1 : -1;

    int r_index = get_in_order_index(root->right, node, in_order);
    return res != -1 ? res : l_index != -1 ? l_index : r_index;
}

tree_node *get_successor_node(tree_node *root, tree_node *node)
{
    vector<tree_node *> in_order;
    int index = get_in_order_index(root, node, in_order);
    if (index == -1 || index == in_order.size() - 1)
        return NULL;
    return in_order[index + 1];
}

tree_node *get_successor_node_no_travese(tree_node *node)
{
    if (!node)
        return NULL;

    tree_node *cur = NULL;

    // 有右子树则说明该节点的后继节点为它右子树的最左节点
    if (node->right)
    {
        cur = node->right;
        while (cur->left)
        {
            cur = cur->left;
        }
        return cur;
    }
    // 无右子树说明该节点为其子树上的最右节点,则说明它的后继节点是 第一个左子树包含该节点 的节点
    cur = node;
    tree_node *parent = cur->parent;
    while (parent && parent->left != cur)
    {
        parent = parent->parent;
        cur = cur->parent;
    }
    return parent;
}

int get_tree_node_count(tree_node *root)
{
    if (!root)
        return 0;

    return get_tree_node_count(root->left) + get_tree_node_count(root->right) + 1;
}

tree_node *get_randomly_node(tree_node *root, int &random_count)
{
    if (!root || random_count == -1)
        return NULL;

    if (random_count == 0)
    {
        random_count = -1;
        return root;
    }

    random_count--;

    tree_node *left = get_randomly_node(root->left, random_count);
    tree_node *right = get_randomly_node(root->right, random_count);

    return left ? left : right;
}

tree_node *get_randomly_node(tree_node *root)
{
    if (!root)
        return NULL;

    int random_count = random(get_tree_node_count(root));
    return get_randomly_node(root, random_count);
}

void in_order(tree_node *root)
{
    if (!root)
        return;

    in_order(root->left);
    cout << root->val << " ";
    in_order(root->right);
}

int main()
{
    tree_node *root = randomly_tree(10, 100);
    tree_node *r_node = get_randomly_node(root);

    print_tree(root);

    cout << "node:";
    if (r_node)
        cout << r_node->val << endl;
    else
        cout << "NULL" << endl;

    tree_node *res = get_successor_node(root, r_node);

    cout << "successor node:";
    if (res)
        cout << res->val << endl;
    else
        cout << "NULL" << endl;

    res = get_successor_node_no_travese(r_node);

    cout << "successor node:";
    if (res)
        cout << res->val << endl;
    else
        cout << "NULL" << endl;

    cout << "in order:";
    in_order(root);
    return 0;
}
