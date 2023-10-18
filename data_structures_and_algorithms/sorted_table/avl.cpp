#include <bits/stdc++.h>
#include "st.cpp"

/// @brief avl实现有序表
class avl_node : public st_node
{
private:
    void rebalance()
    {
        // 更新高度
        int left_height = avl_left()->height;
        int right_height = avl_right()->height;
    }

protected:
    st_node *allocator(int val)
    {
        return new avl_node(val, this);
    }

public:
    int height;

    avl_node(int val, st_node *parent = nullptr, st_node *left = nullptr, st_node *right = nullptr) : st_node(val, parent, left, right),
                                                                                                      height(1)
    {
    }

    avl_node *avl_left()
    {
        return (avl_node *)left;
    }

    avl_node *avl_right()
    {
        return (avl_node *)right;
    }

    avl_node *avl_parent()
    {
        return (avl_node *)parent;                 
    }

    void insert(int val)
    {
        avl_node *cur = (avl_node *)st_node::insert(val);
        cur = cur->avl_parent();
        while (cur)
        {                   
            cur->rebalance();
            cur = cur->avl_parent();
        }
    }
};