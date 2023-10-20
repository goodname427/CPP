#include <bits/stdc++.h>
using namespace std;

void handle(int *arr, int n, void (*handler)(int))
{
    for (int i = 0; i < n; i++)
    {
        handler(arr[i]);
    }
}

int main()
{
    int (*f)(int, int) = [](int a, int b) -> int
    {
        return a + b;
    };
    cout << f(1, 2) << endl;
    int arr[] = {1, 23, 12, 35, 90};
    handle(arr, sizeof(arr) / sizeof(int), [](int num) {
        if (num % 2 == 0)
        {
            cout << num << " ";
        }
    });
    return 0;
}
