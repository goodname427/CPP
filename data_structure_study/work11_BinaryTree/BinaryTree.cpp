#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    int depth;
    TreeNode(T data) : data(data), left(NULL), right(NULL) {}
    ~TreeNode()
    {
        if (right != NULL)
            right->~TreeNode();
        if (left != NULL)
            right->~TreeNode();
        delete left;
        delete right;
    }

    static TreeNode<char> *CreatTree(int depth)
    {
        char c;
        cin >> c;
        if (c == '#')
            return NULL;

        auto node = new TreeNode<char>(c);
        node->depth = depth;
        node->left = CreatTree(depth + 1);
        node->right = CreatTree(depth + 1);
        return node;
    }

    static TreeNode<char> *CreatTree(int depth, string *pre, string in)
    {
        auto root = new TreeNode<char>(pre->at(0));
        root->depth = depth;
        if (pre->length() == 1)
            return root;
        int rindex = in.find(pre->at(0));
        if (rindex > 0)
        {
            pre->erase(pre->begin());
            root->left = CreatTree(depth + 1, pre, in.substr(0, rindex));
        }
        if (rindex < in.length() - 1)
        {
            pre->erase(pre->begin());
            root->right = CreatTree(depth + 1, pre, in.substr(rindex + 1, in.length() - rindex - 1));
        }
        return root;
    }

    //显示当前节点数据以及层数
    void Print()
    {
        cout << data << " " << depth << endl;
    }
    //获取树的最大深度
    int GetMaxDepth()
    {
        int l = 0, r = 0;
        if (left != NULL)
            l = left->GetMaxDepth();
        if (right != NULL)
            r = right->GetMaxDepth();
        return (l > r ? l : r) + 1;
    }
    //前序遍历
    void PreOrderTraverse()
    {
        Print();
        if (left != NULL)
            left->PreOrderTraverse();
        if (right != NULL)
            right->PreOrderTraverse();
    }
    //中序
    void InOrderTraverse()
    {
        if (left != NULL)
            left->InOrderTraverse();
        Print();
        if (right != NULL)
            right->InOrderTraverse();
    }
    //后序
    void PostOrderTraverse()
    {
        if (left != NULL)
            left->PostOrderTraverse();
        if (right != NULL)
            right->PostOrderTraverse();
        Print();
    }
    //层序
    void FloorOrderTraverse()
    {
        queue<TreeNode<T> *> q;
        q.push(this);

        while (!q.empty())
        {
            q.front()->Print();
            if (q.front()->left != NULL)
                q.push(q.front()->left);
            if (q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
    }
};

int main()
{
    TreeNode<char> *root = NULL;
    string pre = "ABCDEF";
    root = TreeNode<char>::CreatTree(1, &pre, "CBDAEF");
    //root= TreeNode<char>::CreatTree(1);
    cout << "前序:" << endl;
    root->PreOrderTraverse();
    cout << "中序:" << endl;
    root->InOrderTraverse();
    return 0;
}
/**
 *      A
 *   +------+
 *   B      C
 * +---+  +---+
 * D   E  F   G
 *+-+ +-+
 *H I J K
 */
