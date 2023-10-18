#include <bits/stdc++.h>
using namespace std;

/// @brief 搜索二叉树
class st_node
{
protected:
    /// @brief 移除指定节点
    /// @return 替代节点 (右树上的最左节点或者左树上的最右节点, 大于左树上的所有节点,并且小于右树上的所有节点)
    static st_node *erase(st_node *node)
    {
        if (!node->left && !node->right)
        {
            return nullptr;
        }

        // 直接使用左右孩子替换当前节点
        // if (node->right && !node->right->left)
        // {
        //     node->right->left = node->left;
        //     return node->right;
        // }
        // if (node->left && !node->left->right)
        // {
        //     node->left->right = node->right;
        //     return node->left;
        // }

        // 寻找右树上最左的节点(或者左树上的最右节点)替换当前节点
        bool has_right = node->right;
        st_node *cur = has_right ? node->right : node->left;
        st_node **cur_ptr = has_right ? &node->right : &node->left;
        while ((has_right && cur->left) || (!has_right && cur->right))
        {
            cur_ptr = has_right ? &cur->left : &cur->right;
            cur = has_right ? cur->left : cur->right;
        }

        // 删除替换节点
        *cur_ptr = erase(cur);

        // 替换节点替换原节点的位置
        cur->left = node->left;
        cur->right = node->right;

        return cur;
    }

    /// @brief 移除树上值为val的节点
    /// @param root 根节点
    /// @param val
    /// @return 移除之后树的根节点
    static st_node *erase(st_node *root, int val)
    {
        if (root->val == val)
        {
            st_node *cur = erase(root);
            root->left = nullptr;
            root->right = nullptr;
            delete root;
            return cur;
        }

        if (val < root->val)
        {
            if (!root->left)
                return root;
            root->left = erase(root->left, val);
        }
        else
        {
            if (!root->right)
                return root;
            root->right = erase(root->right, val);
        }
        return root;
    }

protected:
    /// @brief 动态创建一个节点
    /// @param val 
    /// @return 创建好的节点
    st_node *allocator(int val)
    {
        return new st_node(val, this);
    }
public:
    int val;
    st_node *parent;
    st_node *left;
    st_node *right;

    st_node(int val, st_node *parent = nullptr, st_node *left = nullptr, st_node *right = nullptr) : val(val), parent(parent), left(left), right(right)
    {
    }

    ~st_node()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }

    /// @brief 插入一个值为val的节点 (val不能与树上已有节点val冲突)
    /// @param val
    st_node *insert(int val)
    {
        if (val < this->val)
        {
            if (!left)
                return left = allocator(val);
            else
                return left->insert(val);
        }
        else
        {
            if (!right)
                return right = allocator(val);
            else
                return right->insert(val);
        }
    }

    /// @brief 寻找值为val的节点
    /// @param val
    /// @return 值为val的节点
    st_node *find(int val)
    {
        if (this->val == val)
            return this;

        if (val < this->val)
            return left ? left->find(val) : nullptr;

        return right ? right->find(val) : nullptr;
    }

    /// @brief 移除树上值为val的节点
    /// @param val
    /// @return 移除之后树的根节点
    st_node *erase(int val)
    {
        return erase(this, val);
    }

    /// @brief 左旋
    /// @return 左旋之后树的根节点
    st_node *rotate_left()
    {
        st_node *cur = right;
        right = cur->left;
        cur->left = this;
        return cur;
    }

    st_node *rotate_right()
    {
        st_node *cur = left;
        left = cur->right;
        cur->right = this;
        return cur;
    }
};