#include <iostream>
using namespace std;

void 我是(string name)
{
    std::cout << "我是" << name << std::endl;
}


int main()
{
    char myCharacter;
    myCharacter = 'y';
    string 奥特曼 = "奥特曼";
    // std::cout << "You Died!\n";
    // system("pause");
    我是(奥特曼);

    long ll = 1;
    cout << sizeof(ll) << endl;
    return 0;
}
