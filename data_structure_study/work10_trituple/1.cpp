#include <iostream>
using namespace std;

#define M 4
#define N 4
#define MaxSize 100

template <class T>
struct TupNode
{
    int col;
    int row;
    T data;
};
template <class T>
class TSMatrix
{
public:
    int width;
    int height;
    int count;
    T _default;
    TupNode<T> nodes[MaxSize];
    //创建三元组
    TSMatrix(T matrix[M][N], T _default) : _default(_default)
    {
        width = M;
        height = N;
        count = 0;
        for (int row = 0; row < height; row++)
            for (int col = 0; col < width; col++)
                if (matrix[row][col] != _default)
                    nodes[count++] = {col, row, matrix[row][col]};
    }
    TSMatrix(){}

    //在三元组指定位置插入值
    bool Value(T value, int col, int row)
    {
        int index = 0, _index;
        if (col >= width || row >= height)
            return false;
        while (index < count && col > nodes[index].col)
            index++;
        while (index < count && col == nodes[index].col && row > nodes[index].row)
            index++;
        if (nodes[index].row == row && nodes[index].col == col)
            nodes[index].data = value;
        else
        {
            for (_index = count - 1; _index >= index; _index--)
                nodes[_index + 1] = nodes[_index];
            nodes[index] = {col, row, value};
            count++;
        }
        return true;
    }
    //获取三元组指定位置的值
    bool Assign(T &value, int col, int row)
    {
        int index = 0;
        if (col >= width || row >= height)
            return false;
        while (index < count && col > nodes[index].col)
            index++;
        while (index < count && col == nodes[index].col && row > nodes[index].row)
            index++;
        if (nodes[index].row == row && nodes[index].col == col)
            value = nodes[index].data;
        else
            value = _default;
        return true;
    }
    //转换三元组
    void TransformTo(TSMatrix<T> &target)
    {
        int i, j, k;
        target.width = height;
        target.height = width;
        target.count = count;
        if (count != 0)
            for (i = 0; i < width; i++)
                for (j = 0; j < count; j++)
                    if (nodes[j].col == i)
                        target[k++] = {nodes[j].row, nodes[j].col, nodes[j].data};
    }

    //打印三元组数据
    void Display()
    {
        if (count <= 0)
            return;
        printf("\t%d\t%d\t%d\n", width, height, count);
        printf("\t-----------------\n");
        for (int i = 0; i < count; i++)
            printf("\t%d\t%d\t%d\n", nodes[i].col, nodes[i].row, nodes[i].data);
    }
    void Display(string info)
    {
        cout << info << endl;
        Display();
    }
    //以矩阵形式打印数据
    void Print()
    {
        int k = 0;
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
                if (nodes[k].col == i && nodes[k].row == j)
                    cout << "\t" << nodes[k++].data;
                else
                    cout << "\t" << _default;
            cout << endl;
        }
    }
    void Print(string info)
    {
        cout << info << endl;
        Print();
    }

    //返回指定下标节点
    TupNode<T> &operator[](int index)
    {
        return nodes[index];
    }
    //返回指定位置的值
    T &operator()(int col, int row)
    {
        int k = 0;
        while (k < count && (nodes[k].row != row || nodes[k].col != col))
            k++;
        if (k < count)
            return (nodes[k].data);
        else
            return (_default);
    }
    //矩阵加法
    TSMatrix<T> operator+(TSMatrix<T> &right)
    {
        if (width != right.width || height != right.height || _default != right._default)
            throw exception();
        int i = 0, j = 0, k = 0;
        T val;
        TSMatrix<T> result;
        result.height = height;
        result.width = width;
        result._default = _default;
        while (i < count && j < right.count)
        {
            if (nodes[i].row == right[j].row)
            {
                if (nodes[i].col < right[j].col)
                    result[k++] = nodes[i++];
                else if (nodes[i].col > right[j].col)
                    result[k++] = right[j++];
                else
                {
                    val = nodes[i].data + right[j++].data;
                    if (val != _default)
                        result[k++] = {nodes[i].col, nodes[i].row, val};
                    i++;
                }
            }
            else if (nodes[i].row < right[j].row)
                result[k++] = nodes[i++];
            else
                result[k++] = right[j++];
            result.count = k;
        }
        return result;
    }
    //矩阵乘法
    TSMatrix<T> operator*(TSMatrix<T> &right)
    {
        if (width != right.height || _default != right._default)
            throw exception();
        int i, j, k, p = 0;
        T val;
        TSMatrix<T> result;
        for (i = 0; i < height; i++)
            for (j = 0; j < right.width; j++)
            {
                val = 0;
                for (k = 0; k < width; k++)
                    val += (*this)(k, i) * right(j, k);
                if (val != _default)
                    result[p++] = {j, i, val};
            }
        result.width = right.width;
        result.height = height;
        result.count = p;
        return result;
    }
};

int main()
{
    int A[M][N] =
        {
            {1, 0, 0, 0},
            {1, 0, 0, 1},
            {0, 0, 0, 1},
            {0, 0, 0, 0}},
        val = -1;
    auto t = TSMatrix<int>(A, 0);
    auto _t = TSMatrix<int>(A, 0);
    auto t_ = TSMatrix<int>(A, 0);
    TSMatrix<int> _t_;

    t.Display("原始：");

    t.Value(2, 0, 1);
    t.Display("操作后：");

    if (t.Assign(val, 0, 1))
        cout << "取值（0，1）：" << val << endl;
    if (t.Assign(val, 5, 1))
        cout << "取值（0，1）：" << val << endl;

    t.TransformTo(_t);
    _t.Value(5, 3, 3);
    _t.Display("转换后：");

    cout << "取值（1，1）：" << _t_(1, 1) << endl;
    cout << "取值（0，1）：" << _t_(0, 1) << endl;
    
    _t_ = t_ + _t;
    _t_.Display("相加后：");
    _t_.Print("");
    _t_ = _t_ + t;
    _t_.Display("相加后：");
    _t_.Print("");

    _t_ = t_ * _t;
    _t_.Display("相乘后：");
    _t_.Print("");
    _t_ = _t_ * t;
    _t_.Display("相乘后：");
    _t_.Print("");
    
    return 0;
}