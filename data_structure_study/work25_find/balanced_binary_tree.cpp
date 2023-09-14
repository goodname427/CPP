#include <bits/stdc++.h>
using namespace std;

struct tree_node
{
    int data;
    tree_node *parent;
    tree_node *left;
    tree_node *right;
};
//插入节点

//删除节点
void delete_node(tree_node *&root, int target)
{
    if (root->data == target) //判断是否为要删除节点，如果是则进行删除操作
    {
        if (root->left == NULL && root->right == NULL) //如果为叶子节点
            root = NULL;
        else if (root->left == NULL && root->right != NULL) //只有左子树
            root = root->right;
        else if (root->right == NULL && root->left != NULL) //只有右子树
            root = root->left;
        else
        {
            auto cur = root->left, par = root;
            while (cur->right != NULL) //寻找左子树最大值
            {
                par = cur;
                cur = cur->right;
            }
            root->data = cur->data; //将当前节点值替换为左子树最大值
            if (par != root)
                delete_node(par->right, cur->data); //删除最大值节点
            else
                delete_node(par->left, cur->data);
        }
    }
    else if (target < root->data && root->left != NULL)
        delete_node(root->left, target);
    else if (target > root->data && root->right != NULL)
        delete_node(root->right, target);
}
//搜索节点
tree_node *search_node(tree_node *root, int target)
{
    if (root == NULL)
        return NULL;
    if (target == root->data) //判断当前节点是否为所需节点
        return root;
    if (target < root->data)                    //如果目标数据小于当前数据，则向左子树搜索
        return search_node(root->left, target); //搜索左子树
    return search_node(root->right, target);    //搜索右子树
}
//中序遍历
void in_order_traverse(tree_node *root)
{
    if (root == NULL)
        return;
    in_order_traverse(root->left);
    cout << root->data << " ";
    in_order_traverse(root->right);
}
//获取树的最大高度
int get_max_depth(tree_node *root)
{
    if (root == NULL)
        return 0;
    auto l = get_max_depth(root->left);  //获取左子树的高度
    auto r = get_max_depth(root->right); //获取右子树的高度
    return max(l, r) + 1;                //树的最大高度为左子树和右子树的最大高度+1
}
//判断是否为平衡二叉树如果是返回true
bool is_balanced(tree_node *root)
{
    return root == NULL || (abs(get_max_depth(root->left) - get_max_depth(root->right)) <= 1 && is_balanced(root->left) && is_balanced(root->right));
}

void right_rotate(tree_node *&root)
{
    auto new_root = root->left;
    auto temp = new_root->right;
    root->left = temp;
    temp->parent = root;
    new_root->right = root;
    root->parent = new_root;
    root = new_root;
}

void left_rotate(tree_node *&root)
{
    auto new_root = root->right;
    auto temp = new_root->left;
    root->right = temp;
    temp->parent = root;
    new_root->left = root;
    root->parent = new_root;
    root = new_root;
}

void adjust()
{
}

void insert_node(tree_node *&root, tree_node *new_node)
{
    if (root == NULL)
    {
        root = new_node;
        adjust();
    }
    else if (new_node->data < root->data)
    {
        new_node->parent = root;
        insert_node(root->left, new_node);
    }
    else
    {
        new_node->parent = root;
        insert_node(root->right, new_node);
    }
}

#pragma region 打印二叉树
void output_impl(tree_node *n, bool left, string const &indent)
{
    if (n->right)
    {
        output_impl(n->right, false, indent + (left ? "|     " : "      "));
    }
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->data << endl;
    if (n->left)
    {
        output_impl(n->left, true, indent + (left ? "      " : "|     "));
    }
}

void output(tree_node *root)
{
    if (root->right)
        output_impl(root->right, false, "");
    cout << root->data << endl;
    if (root->left)
        output_impl(root->left, true, "");
}
#pragma endregion

int main()
{
    int nums[] = {1, 4, 2, 12, 24, 7, 18};
    tree_node *root = NULL;
    for (int i = 0; i < 7; i++)
    {
        auto node = new tree_node;
        node->data = nums[i];
        node->left = node->right = node->parent = NULL;
        insert_node(root, node);
    }
    output(root);
    cout << (is_balanced(root) ? "It is balanced" : "It is not balanced");
    return 0;
}
