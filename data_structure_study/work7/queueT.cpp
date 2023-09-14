#include <iostream>
#include <queue>
using namespace std;

template <class T>
void Solve(queue<T> *q, int m)
{
    if (q->size() > 1)
    {
        T temp;
        int count = 0;
        while (true)
        {
            temp = q->front();
            q->pop();
            if (++count < m)
                q->push(temp);
            else
                break;
        }
        Solve(q, m);
        
    }
}

int main()
{
    queue<int> *q = new queue<int>;
    for (int i = 0; i < 10; i++)
        q->push(i + 1);
    Solve(q, 4);
    cout << "获胜者是：" << q->front() << endl;
    return 0;
}