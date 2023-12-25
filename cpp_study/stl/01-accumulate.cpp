#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int max(const int &l, const int &r)
{
    return l < r ? r : l;
}

class myfunc
// : public binary_operation<int, int, int>
{
public:
    int operator()(const int &l, const int &r) const
    {
        return l * r;
    }
};

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    // 默认 init = init + *it;
    cout << accumulate(nums, nums + 5, 0) << endl;           // 15
    cout << accumulate(nums, nums + 5, 1, myfunc()) << endl; // 120
    cout << accumulate(nums, nums + 5, 0, ::max) << endl;    // 5
    return 0;
}

/*参考代码
template <class InputIterator,
          class T>
T accumulate(InputIterator first,
             InputIterator last,
             T init)
{
    for (; first != last; ++first)
        init = init + *first;
    return init;
}

template <class InputIterator,
          class T,
          class BinaryOperation>
T accumulate(InputIterator first,
             InputIterator last,
             T init,
             BinaryOperation binary_op)
{
    for (; first != last; ++first)
        init = binary_op(init, *first);
    return init;
}
*/