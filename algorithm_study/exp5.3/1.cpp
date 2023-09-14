#include <bits/stdc++.h>
using namespace std;

//微小浮点值,两数差值小于该值时认为其相等
#define EPSILON 1e-2

double a, b, c, d;

//获取函数值
double func(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
//判断两个浮点数是否相等
bool equal(double n1, double n2, double els = EPSILON)
{
    return fabs(n1 - n2) < els;
}
//尝试将根添加到集合中
void try_push_back_root(vector<double> &root, double val)
{
    for (int i = 0; i < root.size(); i++)
    {
        if (equal(val, root[i]))
            return;
    }
    root.push_back(val);
}
//二分搜索求解
void binary_s(double begin, double end, vector<double> &root)
{
    //终止条件
    if (root.size() >= 3 || begin > end || equal(begin, end, 1e-3))
        return;
    //获取y值
    double y_begin = func(begin);
    double y_end = func(end);
    // y值为0则直接返回改x
    if (equal(y_begin, 0))
        try_push_back_root(root, begin);
    if (equal(y_end, 0))
        try_push_back_root(root, end);
    //获取中值
    double mid = (begin + end) / 2;
    double y_mid = func(mid);
    //两y值异号且接近则返回x中值
    if (y_begin * y_end < 0)
    {
        if (equal(begin, end))
            try_push_back_root(root, mid);
        //深度优先搜索
        else
        {
            if (y_begin * y_mid < 0)
                binary_s(begin, mid, root);
            if (y_mid * y_end < 0)
                binary_s(mid, end, root);
        }
    }
    //继续搜索
    binary_s(begin, mid, root);
    binary_s(mid, end, root);
}

int main()
{
    cin >> a >> b >> c >> d;
    vector<double> root;
    binary_s(-100, 100, root);
    for (int i = 0; i < root.size(); i++)
    {
        printf("%.2lf ", root[i]);
    }
    return 0;
}
