#include <bits/stdc++.h>
#include "../util/crand"
using namespace std;

//#define TEST_HASH_TABLE

template <typename T>
class hash_node
{
public:
    pair<string, T> val;
    hash_node *next;

    hash_node(pair<string, T> val) : hash_node(val, NULL)
    {
    }
    hash_node(pair<string, T> val, hash_node *next) : val(val), next(next)
    {
    }

    ~hash_node()
    {
        if (next)
            delete next;
    }
};

template <typename T>
class hash_table
{
private:
    typedef int __hash_val_type;

    hash_node<T> **__buff;
    int __capacity;
    int __node_capacity;
    int __power;

private:
    // 以capacity为模求hash值
    __hash_val_type hash(string s)
    {
        return hash(s, __capacity);
    }
    // 以给定值为模求hash值
    __hash_val_type hash(string s, int modulo)
    {
        __hash_val_type base = 1;
        __hash_val_type hash_val = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (!i)
            {
                base *= __power;
                base %= modulo;
            }

            hash_val += s[i] * base;
        }

        return hash_val % modulo;
    }

    // 扩容
    void enlarge()
    {
        int capacity = __capacity * 2;
        hash_node<T> **buff = new hash_node<T> *[capacity];

        for (int i = 0; i < capacity; i++)
            buff[i] = NULL;

        // 数据迁移
        for (int i = 0; i < __capacity; i++)
        {
            if (!__buff[i])
                continue;

            hash_node<T> *cur = __buff[i];
            hash_node<T> *next = NULL;

            while (cur)
            {
                next = cur->next;
                insert(cur->val, buff, cur);
                cur->next = NULL;
                cur = next;
            }
        }

        __buff = buff;
        __capacity = capacity;
    }

    // 朝指定缓冲区插入节点
    int insert(pair<string, T> &pair, hash_node<T> **buff, hash_node<T> *node)
    {
        int node_length = 0;
        hash_node<T> **set = find_node(pair.first, &node_length);

        if (node)
        {
            *set = node;
            return node_length;
        }

        if (*set)
        {
            (*set)->val.second = pair.second;
        }
        else
        {
            *set = new hash_node(pair);
            node_length++;
        }

        return node_length;
    }

    // 寻找指定节点的地址或者指定节点应该放的地址
    hash_node<T> **find_node(string key, int *node_length = NULL)
    {
        __hash_val_type hash_val = hash(key);

        hash_node<T> **set = &__buff[hash_val];

        if(node_length)
            *node_length = 0;

        while (*set && (*set)->val.first != key)
        {
            set = &(*set)->next;
            if(node_length)
                node_length++;
        }

        return set;
    }

public:
    hash_table() : __capacity(2), __node_capacity(5)
    {
        __power = random(1, 1000);
        __buff = new hash_node<T> *[__capacity];
        for (int i = 0; i < __capacity; i++)
            __buff[i] = NULL;
    }
    ~hash_table()
    {
        for (int i = 0; i < __capacity; i++)
        {
            if (__buff[i])
                delete __buff[i];
        }
    }

    // 插入键值对
    void insert(string key, T val)
    {
        insert(pair<string, T>(key, val));
    }
    // 插入键值对
    void insert(pair<string, T> pair)
    {
        if (insert(pair, __buff, NULL) > __node_capacity)
            enlarge();

        __test_print_buff();
    }

    // 移除键值对
    void erase(string key)
    {
        hash_node<T> **set = find_node(key);

        if (!*set)
            return;

        hash_node<T> *cur = *set;
        *set = cur->next;

        cur->next = NULL;
        delete cur;
    }

    // 判断是否包含指定键值对
    bool contains(string key)
    {
        return *find_node(key) != NULL;
    }

    // 查找指定键对应的值
    T find(string key)
    {
        hash_node<T> **cur = find_node(key);

        if (!*cur)
            throw exception();

        return (*cur)->val.second;
    }

    void __test_print_buff()
    {
        cout << endl
             << "buff:" << endl;
        for (int i = 0; i < __capacity; i++)
        {
            hash_node<T> *cur = __buff[i];
            cout << i << " -> ";
            while (cur)
            {
                cout << cur->val.first << ":" << cur->val.second << " -> ";
                cur = cur->next;
            }

            cout << "NULL" << endl;
        }
    }
};

#ifdef TEST_HASH_TABLE
int main()
{
    hash_table<int> t;
    t.insert("1", 1);
    t.insert("2", 2);
    t.insert("3", 3);
    t.insert("4", 4);
    t.insert("5", 5);
    t.insert("6", 6);
    t.insert("6", 666);
    t.erase("1");
    t.__test_print_buff();
    t.erase("6");
    t.__test_print_buff();
    t.erase("5");
    t.__test_print_buff();

    cout << endl;
    // t.insert("7", 7);
    // t.insert("8", 8);
    // t.insert("9", 9);
    // t.insert("10", 10);
    // t.insert("100", 10);
    // cout << t.find("1") << endl;
    // cout << t.find("2") << endl;
    // cout << t.find("3") << endl;
    // cout << t.find("4") << endl;
    // cout << t.find("5") << endl;
    // cout << t.find("6") << endl;
    cout << t.find("3") << endl;
    cout << t.find("2") << endl;
    // cout << t.find("100") << endl;
    cout << t.contains("1") << endl;
    cout << t.contains("5") << endl;
    cout << t.contains("4") << endl;
    return 0;
}
#endif
