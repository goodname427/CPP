#include <bits/stdc++.h>
using namespace std;

struct link_node
{
    int val;
    link_node *next;
};
//开散列表
class hash_table
{
private:
    int capacity;     //容量
    link_node *array; //散列表
    int p;            //哈希值取模值
    //获取哈希值
    int get_hash_code(int key)
    {
        return key % p;
    }
    void delete_link(link_node *link)
    {
        if (link == NULL)
            return;
        if (link->next != NULL)
            delete_link(link->next);
        delete link;
    }

public:
    hash_table(int capacity, int p) : p(p), capacity(capacity)
    {
        array = new link_node[capacity];
        for (int i = 0; i < capacity; i++)
            array[i] = {0, NULL};
    }
    ~hash_table()
    {
        for (int i = 0; i < capacity; i++)
        {
            delete_link(array[i].next);
        }
        delete[] array;
    }
    void insert(int key)
    {
        auto code = get_hash_code(key);
        auto cur = array + code;
        while (true)
        {
            if (cur->val == 0)
            {
                cur->val = key;
                break;
            }
            if (cur->next == NULL)
            {
                auto link = new link_node;
                link->val = 0;
                link->next = NULL;
                cur->next = link;
            }
            cur = cur->next;
        }
    }
    int find(int key)
    {
        auto code = get_hash_code(key);
        auto cur = array + code;
        while (cur != NULL)
        {
            if (cur->val == key)
                return code;
            cur = cur->next;
        }
        return -1;
    }
};
//闭散列表
class _hash_table
{
private:
    int capacity;
    int *array;
    int p;
    int get_hash_code(int key)
    {
        return key % p;
    }

public:
    _hash_table(int capacity, int p) : p(p), capacity(capacity)
    {
        array = new int[capacity];
        for (int i = 0; i < capacity; i++)
            array[i] = 0;
    }
    ~_hash_table()
    {
        delete[] array;
    }
    bool insert(int key)
    {
        auto code = get_hash_code(key);
        for (int i = 0; i < capacity; i++)
            if (array[(i + code) % capacity] == 0)
            {
                array[(i + code) % capacity] = key;
                return true;
            }
        return false;
    }
    int find(int key)
    {
        auto code = get_hash_code(key);
        for (int i = 0; i < capacity; i++)
        {
            auto index = (i + code) % capacity;
            if (array[index] == 0)
                return -1;
            if (array[index] == key)
            {
                array[index] = key;
                return index;
            }
        }
        return -1;
    }
};

int main()
{
    int nums[] = {1, 34, 56, 57, 843, 234, 64, 6, 87, 24}, len = sizeof(nums) / sizeof(int), tar;
    _hash_table ht(11, 11);
    for (int i = 0; i < len; i++)
        ht.insert(nums[i]);
    while (cin >> tar)
    {
        tar = ht.find(tar);
        if (tar == -1)
            cout << "没找到！" << endl;
        else
            cout << tar << endl;
    }
    return 0;
}
