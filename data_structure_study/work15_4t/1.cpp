#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *CreatTree()
{
    string c;
    cin >> c;
    if (c == "#")
        return NULL;

    auto node = new TreeNode;
    node->data = atoi(c.c_str());
    node->left = CreatTree();
    node->right = CreatTree();
    if (node->left != NULL && node->left->data >= node->data)
    {
        cout << "false";
        exit(-1);
    }
    if (node->right != NULL && node->right->data <= node->data)
    {
        cout << "false";
        exit(-1);
    }
    return node;
}

int main()
{    
    CreatTree();
    cout << "true";
    return 0;
}