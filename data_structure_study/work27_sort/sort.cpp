#include <bits/stdc++.h>
using namespace std;

//显示元素
void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
//交换
void swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
//插入排序
void insert_sort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = array[i], j = i;
        while (j > 0 && array[j - 1] > temp)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}
//选择排序
void select_sort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (array[min] > array[j])
                min = j;
        swap(array[i], array[min]);
    }
}
//希尔排序
void shell_sort(int *array, int size)
{
    for (int d = size / 2; d >= 1; d /= 2)
    {
        for (int j = d; j < size; j++)
        {
            int temp = array[j], k = j;
            while (k > 0 && array[k - d] > temp)
            {
                array[k] = array[k - d];
                k -= d;
            }
            array[k] = temp;
        }
    }
}
//快速排序
void quick_sort(int *array, int begin, int end)
{
    if (begin >= end) //空数组或者单元素不排序
        return;
    int key = begin, _begin = begin, _end = end; //以begin位置为基准值
    while (_begin < _end)
        if (array[_end] < array[key]) // end遇到小于基准值的元素时，移动begin直到begin遇到一个大于基准值的元素
        {
            if (array[++_begin] > array[key])
                swap(array[_begin], array[_end]); //交换begin元素与end元素位置
        }
        else
            _end--;
    swap(array[key], array[_end]);      //交换begin与end相遇位置的元素和key元素
    quick_sort(array, begin, _end - 1); //左序列排序
    quick_sort(array, _end + 1, end);   //右序列排序
}
//堆排序
void heap_sort(int *array, int size)
{
    // parent:(i-1)/2 left:2*i+1 right:2*i+2
    for (int j = 1; j < size; j++) //构建大根堆
    {
        int p = (j - 1) / 2, k = j;
        while (p >= 0)
        {
            if (array[p] < array[k])
                swap(array[p], array[k]);
            if (p == 0)
                break;
            k = p;
            p = (p - 1) / 2;
        }
    }
    swap(array[0], array[size - 1]); //将根结点放到末尾
    for (int i = 1; i < size; i++)
    {
        int j = 0;
        //若左右孩子较大值大于根节点，则交换根节点与该节点位置，重复此操作
        while (true)
        {
            int left = 2 * j + 1, right = 2 * j + 2, max;
            if (right <= size - i - 1)
                max = array[left] > array[right] ? left : right;
            else if (left <= size - i - 1)
                max = left;
            else
                break;
            if (array[max] > array[j])
            {
                swap(array[max], array[j]);
                j = max;
            }
            else
                break;
        }
        swap(array[0], array[size - i - 1]);//将根结点放到末尾
    }
}
//归并排序
void merge_sort(int *array,int size)
{

}
int main()
{
    int array[] = {12, 334, 27, 2, 45, 21, 34, 46, 23, 53, 89}, size = sizeof(array) / sizeof(int);
    heap_sort(array, size);
    display(array, size);
    cout << "2 12 21 23 27 34 45 46 53 89 334" << endl;
    return 0;
}
// 2 12 21 23 27 34 45 46 53 89 334
