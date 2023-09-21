#include <bits/stdc++.h>
#include "../util/cvectorop"
using namespace std;

// 选择排序
// 从i~n中选择一个最小的数与i交换位置
void selection_sort(vector<int> &vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[minIndex])
                minIndex = j;
        }
        swap(vec[i], vec[minIndex]);
    }
}

// 冒泡排序
// i 与 i+1 比较, 如果 i 大则交换位置
void bubble_sort(vector<int> &vec)
{
    for (int i = vec.size() - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

// 插入排序
// i从0~i中选择一个位置插入
void insertion_sort(vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; j--)
            swap(vec[j], vec[j + 1]);
    }
}

// 归并排序
// 将数组分为[0, mid]以及[mid + 1,r]分别进行归并排序， 然后再将两个子数组按序合并
#pragma region merge_sort
void __merge(vector<int> &vec, int l, int m, int r)
{
    vector<int> help(r - l + 1);
    int i = 0;
    int p1 = l;
    int p2 = m + 1;

    while (p1 <= m && p2 <= r)
        help[i++] = vec[p1] <= vec[p2] ? vec[p1++] : vec[p2++];
    while (p1 <= m)
        help[i++] = vec[p1++];
    while (p2 <= r)
        help[i++] = vec[p2++];

    for (int i = 0; i < help.size(); i++)
        vec[i + l] = help[i];
}

void merge_sort(vector<int> &vec, int l, int r)
{
    if (l == r)
        return;

    int mid = l + ((r - l) >> 1);

    // 分队排序
    merge_sort(vec, l, mid);
    merge_sort(vec, mid + 1, r);

    // 合并
    __merge(vec, l, mid, r);
}

void merge_sort(vector<int> &vec)
{
    if (vec.size() < 2)
        return;

    merge_sort(vec, 0, vec.size() - 1);
}
#pragma endregion

// 快速排序
// 等概率选择一个数作为比较器, 将小于比较器的数放在数组的左边,等于比较器的数放在数组的中间,大于比较器的数放在数组的右边,然后再将小于和大于比较器的子数组重复此操作
#pragma region
void quick_sort(vector<int> &vec, int l, int r)
{
    if (l >= r)
        return;

    // 选取随机数作为比较器
    swap(vec[random(l, r + 1)], vec[r]);

    // 将数组以比较器分为小于等于大于三部分
    int lp = l;
    int rp = r - 1;
    int i = l;

    while (i <= rp)
    {
        if (vec[i] < vec[r])
            swap(vec[lp++], vec[i++]);
        else if (vec[i] > vec[r])
            swap(vec[rp--], vec[i]);
        else
            i++;
    }

    swap(vec[i], vec[r]);

    // 对左右区域重新排序
    quick_sort(vec, l, lp - 1);
    quick_sort(vec, i + 1, r);
}

void quick_sort(vector<int> &vec)
{
    if (vec.size() < 2)
        return;

    quick_sort(vec, 0, vec.size() - 1);
}
#pragma endregion

// 堆排序
// 使用大根堆对数组进行排序
#pragma region heap_sort
// 堆化
void heapify(vector<int> &vec, int index, int heap_size)
{
    auto left = 2 * index + 1;
    while (left < heap_size)
    {
        auto larger = left + 1 < heap_size && vec[left + 1] > vec[left] ? left + 1 : left;

        if (vec[index] > vec[larger])
            break;

        swap(vec[index], vec[larger]);
        index = larger;
        left = 2 * index + 1;
    }
}
// 堆插入
void heap_insert(vector<int> &vec, int index)
{
    while (vec[index] > vec[(index - 1) / 2])
    {
        swap(vec[index], vec[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heap_sort(vector<int> &vec)
{
    if (vec.size() < 2)
        return;

    // 使用堆插入构建大根堆
    // int heap_size = 1;
    // for (; heap_size < vec.size(); heap_size++)
    // {
    //     heap_insert(vec, heap_size);
    // }

    // 使用堆化构建大根堆. 效率更好
    int heap_size = vec.size();
    for (int i = heap_size - 1; i >= 0; i--)
        heapify(vec, i, heap_size);

    // 大根堆出堆
    while (heap_size > 1)
    {
        swap(vec[0], vec[--heap_size]);
        heapify(vec, 0, heap_size);
    }
}
#pragma endregion

//基数排序
//先找到数组中的最大元素,获取其位数,准备好0-10号桶,依次按1-最大位,对所有元素分类放进对应的桶中,分类后再出桶
#pragma region radix_sort
int get_max_bits(vector<int> &vec)
{
    auto max_n = *max_element(vec.begin(), vec.end());

    auto bits = 0;
    while (max_n)
    {
        bits++;
        max_n /= 10;
    }

    return bits;
}

int get_bits(int num, int bits)
{
    return (num / (int)pow(10, bits - 1)) % 10;
}

void radix_sort(vector<int> &vec)
{
    auto max_bits = get_max_bits(vec);
    vector<int> bucket(vec.size());

    for (int bits = 1; bits <= max_bits; bits++)
    {
        vector<int> count(10);
        // 对对应位上的数进行计数
        for (auto num : vec)
        {
            count[get_bits(num, bits)]++;
        }
        // 计数数组化为前缀和数组
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }
        // 出桶
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            auto num_bits = get_bits(vec[i], bits);
            bucket[count[num_bits] - 1] = vec[i];
            count[num_bits]--;
        }
        // 平移数据
        for (int i = 0; i < vec.size(); i++)
        {
            vec[i] = bucket[i];
        }
    }
}

#pragma endregion

int main()
{
    int times = 10000;
    int maxSize = 1000;
    int maxValue = 10000;
    void (*sort_func)(vector<int> &) = radix_sort;
    while (times--)
    {
        auto vec = randomly_vec(maxSize, maxValue);
        sort_func(vec);
        if (!is_ordered(vec))
        {
            cout << "error" << endl;
            print(vec);
        }
    }
    return 0;
}
