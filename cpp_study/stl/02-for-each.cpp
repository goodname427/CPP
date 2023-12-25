#include <bits/stdc++.h>
using namespace std;

void print(const int &i)
{
    cout << ' ' << i;
}

struct plus
{
    void operator()(int &i) const
    {
        ++i;
    }
};

int
main()
{
    int nums[] = {1, 2, 3, 4, 5};

    for_each(nums, nums + 5, print);    // 1 2 3 4 5
    cout << endl;

    for_each(nums, nums + 5, ::plus());
    for_each(nums, nums + 5, print);    // 2 3 4 5 6
    cout << endl;

    // 2 3 4 5 6
    for (int &i : nums)
    {
        print(i);
    }

    return 0;
}

/*
template <class InputIterator,
          class Function>
Function for_each(InputIterator first,
                  InputIterator last,
                  Function f)
{
    for (; first != last; ++first)
        f(*first);
    return f;
}
*/
