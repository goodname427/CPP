#include <bits/stdc++.h>
using namespace std;

class bit_map
{
private:
    typedef int __bit_contaniner;
    __bit_contaniner* __buff;
    int __capacity;

    int get_bit_contanier_size()
    {
        return sizeof(__bit_contaniner) * 8;
    }

    __bit_contaniner* get_contanier(int flag, int& bit_index)
    {
        int index = flag / get_bit_contanier_size();
        if (index >= __capacity)
            return NULL;

        bit_index = flag % 32;

        return &__buff[index];
    }

public:
    bit_map(int max_flag) : __capacity(max_flag / get_bit_contanier_size() + 1)
    {
        __buff = new __bit_contaniner[__capacity];
    }

    ~bit_map()
    {
        delete __buff;
    }

    void set(int flag, bool val = true)
    {
        int bit_index;
        __bit_contaniner *container = get_contanier(flag, bit_index);
        
        if(!container)
            return;

        if(val)
            *container |= (1 << bit_index);
        else
            *container &= ~(1 << bit_index);
    }

    bool get(int flag)
    {
        int bit_index;
        __bit_contaniner *container = get_contanier(flag, bit_index);

        if(!container)
            throw exception();

        return *container & (1 << bit_index);
    }

    int max_flag()
    {
        return __capacity * get_bit_contanier_size();
    }
};

int main()
{
    bit_map b(1023);
    cout << b.get(1) << endl;
    b.set(1, 1);
    cout << b.get(1) << endl;
    b.set(100);
    cout << b.get(100) << endl;
    b.set(100, 0);
    cout << b.get(100) << endl;
    
    return 0;
}
