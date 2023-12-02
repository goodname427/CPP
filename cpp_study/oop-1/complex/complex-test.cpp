#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    complex c1(2, 1);
    complex c2;
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;

    c2 = c1 + 5;
    c2 = 7 + c1;
    c2 = c1 + c2;
    c2 += c1;
    c2 += 3;
    c2 = -c1;

    std::cout << (c1 == c2) << std::endl;
    std::cout << (c1 != c2) << std::endl;
    return 0;
}
