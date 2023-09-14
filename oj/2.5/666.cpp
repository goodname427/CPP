#include <iostream>
using namespace std;

int get_max(int M, int N)
{
    int re = M % N;
    return (M - re) / N + (re >= 1 ? 1 : re);
}

int get_solution(int max, int M, int N)
{
    if (N == 1 || M == 0)
        return 1;
    int sum = 0, min = get_max(M, N);
    for (int i = M - max <= 0 ? 0 : M - max; min <= M - i; i++)
        sum += get_solution(M - i, i, N - 1);
    return sum;
}

int main()
{
    int n, M, N;
    cin >> n;
    int *slts = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> M >> N;
        slts[i] = get_solution(M, M, N);
    }
    for (int i = 0; i < n; i++)
    {
        cout << slts[i] << endl;
    }
    delete[] slts;
    return 0;
}