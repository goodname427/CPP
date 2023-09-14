#include <bits/stdc++.h>
using namespace std;

int binary_search(int *array, int min, int max, int target)
{
    if (min > max)
        return -1;
    int mid = (max + min) / 2;
    if (array[mid] == target)
        return mid;
    if (array[mid] < target)
        return binary_search(array, mid + 1, max, target);
    return binary_search(array, min, max - 1, target);
}

int main()
{
    int n, target;
    cin >> n >> target;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    cout << binary_search(array, 0, n - 1, target);
    return 0;
}
