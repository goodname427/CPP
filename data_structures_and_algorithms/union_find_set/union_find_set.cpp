#include <bits/stdc++.h>
using namespace std;

template <typename T>
class union_find_set_element
{
public:
    T val;
    union_find_set_element<T> *parent;
    int size;

    union_find_set_element(T val) : union_find_set_element(val, this)
    {
    }
    union_find_set_element(T val, union_find_set_element<T> *parent) : val(val), parent(parent), size(1)
    {
    }
};

template <typename T>
class union_find_set
{
private:
    typedef union_find_set_element<T> *__element_type;

    unordered_map<T, __element_type> __element_map;

    __element_type __find_head(T val)
    {
        __element_type ele = __element_map[val];
        stack<__element_type> path;

        // 寻找头节点
        while (ele->parent != ele)
        {
            // 记录路径点
            path.push(ele);
            ele = ele->parent;
        }

        // 将路径上的节点直接指向头节点, 使得节点并扁平化
        while (!path.empty())
        {
            path.top()->parent = ele;
            path.pop();
        }

        return ele;
    }

public:
    union_find_set(vector<T> elements)
    {
        for (auto ele : elements)
            __element_map.insert(pair<T, __element_type>(ele, new union_find_set_element<T>(ele)));
    }

    ~union_find_set()
    {
        for (auto ele : __element_map)
            delete ele.second;
    }

    // 查找集合
    bool is_same_set(T val1, T val2)
    {
        if (!__element_map.contains(val1) || !__element_map.contains(val2))
            return false;

        // 头节点相同则认为两个节点属于同一集合
        return __find_head(val1) == __find_head(val2);
    }

    // 合并集合
    void union_set(T val1, T val2)
    {
        if (!__element_map.contains(val1) || !__element_map.contains(val2))
            return;

        __element_type head1 = __find_head(val1);
        __element_type head2 = __find_head(val2);

        if (head1 == head2)
            return;

        // 寻找数量更大的集合
        __element_type bigger = head1->size > head2->size ? head1 : head2;
        __element_type smaller = bigger == head1 ? head2 : head1;

        // 将小集合合并到大集合
        smaller->parent = bigger;
        bigger->size += smaller->size;
        smaller->size = 0;
    }
};
