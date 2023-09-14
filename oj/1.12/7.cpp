#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N, word, count = 0;
    vector<int> memory;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> word;
        if (find(memory.begin(), memory.end(), word) == memory.end())
        {
            if (memory.size() >= M)
                memory.erase(memory.begin());
            memory.push_back(word);
            count++;
        }
    }
    cout << count;
    return 0;
}
