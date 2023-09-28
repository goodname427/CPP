#include <bits/stdc++.h>
using namespace std;

class window_max
{
private:
    vector<int> vec;
    int l;
    int r;
    queue<int> q;

public:
    window_max(const vector<int> &vec) : vec(vec), l(-1), r(-1)
    {
    }

    void move_r()
    {
        r++;
        if (r >= vec.size())
            return;

        // 将单调队列中小于当前元素的元素全部弹出
        while (!q.empty() && vec[q.front()] < vec[r])
            q.pop();
    
        q.push(r);
    }

    void move_l()
    {
        l++;
        if (l >= vec.size())
            return;

        // 如果最大元素为当前元素则弹出该元素
        if (q.front() == l)
            q.pop();
    }

    int get_max()
    {
        if(q.empty())
            throw exception();

        return vec[q.front()];
    }
};

int main()
{
    window_max w({1, 2, 4, 5, 1, 2});
    w.move_r();
    w.move_r();
    w.move_r();
    // [1, 2, 4] -> 4
    cout << w.get_max() << endl;
    w.move_l();
    w.move_l();
    // [4] -> 4
    cout << w.get_max() << endl;
    w.move_r();
    w.move_r();
    // [4, 5, 1] -> 5
    cout << w.get_max() << endl;
    w.move_l();
    w.move_l();
    // [1] -> 1
    cout << w.get_max() << endl;
    return 0;
}
