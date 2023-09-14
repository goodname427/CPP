#include <bits/stdc++.h>
using namespace std;

class tree_node
{
public:
    int data;
    tree_node *left;
    tree_node *right;
    tree_node() : data(0), left(NULL), right(NULL){};
    tree_node(int data) : data(data), left(NULL), right(NULL) {}
    ~tree_node()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }
    //插入节点
    static tree_node *insert_node(tree_node *root, tree_node *s)
    {
        if (root == NULL)
            root = s;
        else if (s->data < root->data)
            root->left = insert_node(root->left, s);
        else
            root->right = insert_node(root->right, s);
        return root;
    }
    //删除节点并返回true如果删除成功
    static tree_node *delete_node(int target, tree_node *root)
    {
        if (root->data == target) //判断是否为要删除节点，如果是则进行删除操作
        {
            if (root->left == NULL && root->right == NULL) //如果为叶子节点
                return NULL;
            else if (root->left == NULL && root->right != NULL) //只有左子树
                return root->right;
            else if (root->right == NULL && root->left != NULL) //只有右子树
                return root->left;
            else
            {
                auto cur = root->left, par = root;
                while (cur->right != NULL) //寻找左子树最大值
                {
                    par = cur;
                    cur = cur->right;
                }
                root->data = cur->data;            //将当前节点值替换为左子树最大值
                cur = delete_node(cur->data, cur); //删除最大值节点
                if (par == root)
                    root->left = cur;
                else
                    par->right = cur;
                return root;
            }
        }
        if (target < root->data && root->left != NULL)
            root->left = delete_node(target, root->left);
        else if (target > root->data && root->right != NULL)
            root->right = delete_node(target, root->right);
        return root;
    }
    //中序遍历
    void in_order_traverse()
    {
        if (left != NULL)
            left->in_order_traverse();
        cout << data << " ";
        if (right != NULL)
            right->in_order_traverse();
    }
    //搜索指定数据并返回包含该数据的节点，如果没有找到则返回NULL
    tree_node *search_node(int target)
    {
        if (target == data) //判断当前节点是否为所需节点
            return this;
        if (target < data) //如果目标数据小于当前数据，则向左子树搜索
        {
            if (left == NULL) //判断是否有左子树，没有则返回空
                return NULL;
            return left->search_node(target); //搜索左子树
        }
        if (right == NULL) //判断右子树
            return NULL;
        return right->search_node(target); //搜索右子树
    }
};

int main()
{
    int n;
    cin >> n;
    tree_node *s = new tree_node[n], *root = NULL, *temp = NULL;
    //建树
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].data;
        root = tree_node::insert_node(root, s + i);
    }
    root->in_order_traverse();
    cout << endl;
    //查找
    if ((temp = root->search_node(32)) != NULL)
        cout << temp->data << endl;
    if ((temp = root->search_node(19)) != NULL)
        cout << temp->data << endl;
    if ((temp = root->search_node(100)) != NULL)
        cout << temp->data << endl;
    //删除
    root = tree_node::delete_node(54, root);
    root->in_order_traverse();
    cout << endl;
    root = tree_node::delete_node(1, root);
    root->in_order_traverse();
    cout << endl;
    root = tree_node::delete_node(89, root);
    root->in_order_traverse();
    cout << endl;
    return 0;
}
/*
10
1 22 12 54 32 21 31 14 19 25
*/