#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nums[] {1, 13, 44, 21, 145, 87};
    sort(nums, nums + 7, [](const int &l, const int &r) {
        return l > r;
    });

    for (int i = 0; i < 7; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    []{
        cout << "Hello World!" << endl;
    }();

    cout << [](int l, int r){
        return l + r;
    }(1, 2) << endl;

    

    return 0;
}
