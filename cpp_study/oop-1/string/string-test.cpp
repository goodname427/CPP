#include <iostream>
#include "string.h"
using namespace std;

int main()
{
    String s1;
    String s2("hello");

    String s3(s2);
    std::cout << s3 << std::endl;
    
    s3 = s2;
    std::cout << s3 << std::endl;

    s3 = "hello";
    std::cout << s3 << std::endl;

    std::cout << sizeof(double);
    return 0;
}
