#include <iostream>
#include <list>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;  //左孩子节点
    TreeNode *right; //右孩子节点
    TreeNode *parent;
    int weight; //权重
    //创建一个叶子节点
    TreeNode(int weight) : left(NULL), right(NULL), parent(NULL), weight(weight) {}
    //以左右孩子创建一个节点
    TreeNode(TreeNode *left, TreeNode *right) : parent(NULL), left(left), right(right), weight(left->weight + right->weight)
    {
        left->parent = this;
        right->parent = this;
    }
    ~TreeNode()
    {
        if (left != NULL)
            left->~TreeNode();
        if (right != NULL)
            right->~TreeNode();
        delete left;
        delete right;
    }
    //获取当前节点的编码
    string GetEncode()
    {
        string path = "";
        TreeNode *cur = this;
        while (cur->parent != NULL)
        {
            if (cur->parent->left == cur)
                path = "0" + path;
            else
                path = "1" + path;
            cur = cur->parent;
        }
        return path;
    }
    //获取树的WPL
    int GetWPL(int depth)
    {
        int l = 0, r = 0;
        if (left == NULL && right == NULL)
            return depth * weight;
        if (left != NULL)
            l = left->GetWPL(depth + 1);
        if (right != NULL)
            r = right->GetWPL(depth + 1);
        return l + r;
    }
    //打印对应权值对应的编码
    void PrintEncode()
    {
        if (left == NULL && right == NULL)
        {
            cout << weight << ": " << GetEncode() << endl;
            return;
        }
        if (left != NULL)
            left->PrintEncode();
        if (right != NULL)
            right->PrintEncode();
    }
    //打印树
    void PrintTree()
    {
        cout << weight << endl;
        if (left != NULL)
            left->PrintTree();
        else
            cout << "#" << endl;
        if (right != NULL)
            right->PrintTree();
        else
            cout << "#" << endl;
    }
};

int main()
{
    int weights[] = {5, 2, 9, 11, 8, 3, 7}; //各叶子节点的权重
    list<TreeNode *> buff;                  //缓冲区
    for (int i = 0; i < sizeof(weights) / sizeof(int); i++)
        buff.push_back(new TreeNode(weights[i])); //添加对应的树
    while (buff.size() > 1)
    {
        auto it = buff.begin();
        auto min1 = it++, min2 = it++;
        //寻找缓冲区中根节点权值最小的两棵二叉树
        for (; it != buff.end(); it++)
        {
            if ((*it)->weight < (*min1)->weight)
            {
                if ((*min1)->weight < (*min2)->weight)
                    min2 = min1;
                min1 = it;
                continue;
            }
            if ((*it)->weight < (*min2)->weight)
                min2 = it;
        }
        //拼凑成一个新的二叉树
        auto root = new TreeNode(*min1, *min2);
        //以新的二叉树替换旧的两棵二叉树
        buff.erase(min1);
        buff.erase(min2);
        buff.push_back(root);
    }
    buff.back()->PrintEncode();
    cout << "WPL:" << buff.back()->GetWPL(1); //显示各叶子节点的编码
}