#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    complex c1(2, 1);
    complex c2;
    std::cout << c1.real() << std::endl;
    std::cout << c1.imag() << std::endl;
    return 0;
}
