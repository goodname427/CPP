#include <bits/stdc++.h>
#include "binary_tree.cpp"
using namespace std;


void width_first(tree_node *root)
{
    if (!root)
        return;

    queue<tree_node *> q;
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        cout << root->val << " ";
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}

int get_max_width(tree_node *root)
{
    if (!root)
        return 0;

    int cur_level = 1;
    int cur_level_width = 0;
    int max_width = 0;

    unordered_map<tree_node *, int> level_map;
    level_map.insert(pair<tree_node *, int>(root, 1));

    queue<tree_node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (level_map[root] == cur_level)
        {
            cur_level_width++;
        }
        else
        {
            cur_level++;
            max_width = max(cur_level_width, max_width);
            cur_level_width = 1;
        }

        if (root->left)
        {
            level_map.insert(pair<tree_node *, int>(root->left, cur_level + 1));
            q.push(root->left);
        }
        if (root->right)
        {
            level_map.insert(pair<tree_node *, int>(root->right, cur_level + 1));
            q.push(root->right);
        }
    }

    return max(max_width, cur_level_width);
}

int get_max_width_no_map(tree_node *root)
{
    if (!root)
        return 0;

    tree_node *cur_level_end = root;
    tree_node *next_level_end = NULL;
    int max_width = 0;
    int cur_level_width = 0;

    queue<tree_node *> q;
    q.push(root);

    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->left)
        {
            next_level_end = root->left;
            q.push(root->left);
        }
        if (root->right)
        {
            next_level_end = root->right;
            q.push(root->right);
        }

        cur_level_width++;
        if (root == cur_level_end)
        {
            cur_level_end = next_level_end;
            next_level_end = NULL;
            max_width = max(max_width, cur_level_width);
            cur_level_width = 0;
        }
    }
    return max_width;
}


int main()
{
    tree_node *root = randomly_tree(10, 10);
    width_first(root);
    cout << endl;
    cout << get_max_width(root) << endl;
    cout << get_max_width_no_map(root) << endl;
    free_tree(root);
    return 0;
}
