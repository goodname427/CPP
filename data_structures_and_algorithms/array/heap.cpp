#include <bits/stdc++.h>
#include "../util/crand"
using namespace std;

class heap
{
private:
    int *__buff;
    int __heap_size;
    int __capacity;

private:
    void enlarge()
    {
        // 容量倍增
        auto capacity = __capacity;
        __capacity = __capacity ? 2 * __capacity : 2;

        // 数组数据迁移
        auto new_buff = new int[__capacity];
        for (int i = 0; i < capacity; i++)
            new_buff[i] = __buff[i];

        delete __buff;
        __buff = new_buff;
    }

    // 堆插入
    void heap_insert(int index)
    {
        // 当前节点与其父节点进行对比, 如果大于其父节点则二者交换位置
        while (__buff[index] > __buff[(index - 1) / 2])
        {
            swap(__buff[index], __buff[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // 堆化
    void heapify(int index)
    {
        // 当前节点从左右子节点中选择最大的节点进行比较, 如果小于最大节点则二者交换位置
        auto left = 2 * index + 1;
        while (left < __heap_size)
        {
            int larger = left + 1 < __heap_size && __buff[left + 1] > __buff[left] ? left + 1 : left;
            if (__buff[index] > __buff[larger])
                break;

            swap(__buff[index], __buff[larger]);
            index = larger;
            left = 2 * index + 1;
        }
    }

public:
    heap() : __capacity(0), __heap_size(0)
    {
        __buff = new int[0];
    }

    ~heap()
    {
        delete __buff;
    }

    void add(int val)
    {
        if (__heap_size >= __capacity)
            enlarge();

        __buff[__heap_size++] = val;
        heap_insert(__heap_size - 1);
    }

    int poll()
    {
        int val = *__buff;
        *__buff = __buff[--__heap_size];
        heapify(0);
        return val;
    }

    bool empty()
    {
        return __heap_size == 0;
    }

    int heap_size()
    {
        return __heap_size;
    }
};

int main()
{
    heap h;
    for (int i = 0; i < 5; i++)
        h.add(random(10));

    while (!h.empty())
    {
        cout << h.poll() << " ";
    }
}
