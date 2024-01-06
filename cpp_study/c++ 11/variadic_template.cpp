#include <bits/stdc++.h>
using namespace std;

void print()
{
    cout << endl;
}

void print(int i)
{
    print();
}

template <typename T, typename... Types>
void print(const int &i, const T &firstArg, const Types &...args)
{
    cout << firstArg << " ";
    print(i, args...);
}

template <typename... Types>
void print(const Types &...args)
{
    // print(args...);
    cout << "what's wrong with you? bro?" << endl;
}

int main()
{
    print("ASD", 2, 3, "asdasd", 's', 213.2);
    print(2, 3, "asdasd", 's', 213.2);
    print(2, bitset<16>(132));
    return 0;
}
