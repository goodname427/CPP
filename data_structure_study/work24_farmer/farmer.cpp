#include <bits/stdc++.h>
using namespace std;

class tree_node
{
public:
    char state; //记录当前节点代表的状态
    tree_node *parent;
    vector<tree_node *> children;

    tree_node(char _state) : state(_state), parent(NULL) {}
    ~tree_node()
    {
        for (auto it = children.begin(); it != children.end(); it++)
            delete *it;
    }
    //插入孩子节点
    tree_node *insert_child(char _state)
    {
        auto child = new tree_node(_state);
        child->parent = this;
        children.push_back(child);
        return child;
    }
    //获取对应位上的位置 0号位代表农夫，1狼，2羊，3菜
    char get_bit(char offset)
    {
        return ((1 << (3 - offset)) & state) >> (3 - offset);
    }
    //该节点是否有效
    bool valid()
    {
        //判断农夫不在的情况下，狼和羊，羊和菜是否在同一个位置
        return !(get_bit(0) != get_bit(2) && (get_bit(1) == get_bit(2) || get_bit(2) == get_bit(3)));
    }
    //该节点是否与之前节点状态重复
    bool progressive()
    {
        auto cur = this->parent;
        while (cur != NULL)
        {
            if (cur->state == state)
                return false;
            cur = cur->parent;
        }
        return true;
    }
    //打印节点路径
    void display_path()
    {
        auto cur = this;
        while (cur != NULL)
        {
            cout << bitset<4>(cur->state) << (cur->parent == NULL ? "" : "<-");
            cur = cur->parent;
        }
        cout << endl;
    }
    //创建状态树
    void creat_tree()
    {
        if (!valid() || !progressive()) //判断是否需要继续往下创建
            return;
        if (state == 15) //如果为终点则打印路径
        {
            display_path();
            return;
        }
        insert_child(0b1000 ^ state)->creat_tree(); //农夫不带东西过河
        for (int i = 1; i < 4; i++)                 //农夫选择携带一样东西过河
            if (get_bit(i) == get_bit(0))           //判断这个东西是否和农夫在同一岸
                insert_child(0b1000 ^ ((1 << (3 - i)) ^ state))->creat_tree();
    }
};

int main()
{
    auto root = new tree_node(0);
    root->creat_tree();
    delete[] root;
    return 0;
}

/*
一个农夫带着一只狼，一棵白菜和一只山羊要从一条河的南岸到北岸，农夫每次只能带一样东西过过河，
但是任意时刻如果农夫不在场时，狼要吃羊、羊要吃菜，请为农夫设计过河方案。
提示： 要求解农夫过河问题，首先要选择一个对问题中每个角色的位置进行描述的方法。
态0000，终结状态顶点为1111，即开始时农夫、狼、羊和白菜都在北岸，顶点状态为0000，
运用深度优先遍历h或广度优先搜索图，从开始状态顶点到结束状态顶点遍历，输出过河情况。
*/