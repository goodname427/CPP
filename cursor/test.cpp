#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "欢迎来玩猜数字游戏!" << endl;
    
    // 初始化随机数生成器
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guess;
    int tries = 0;
    
    do {
        cout << "请猜一个1到100之间的数字: ";
        cin >> guess;
        tries++;
        
        if (guess > secretNumber) {
            cout << "太大了!" << endl;
        } else if (guess < secretNumber) {
            cout << "太小了!" << endl;
        } else {
            cout << "恭喜你猜对了!" << endl;
            cout << "你总共猜了 " << tries << " 次" << endl;
        }
    } while (guess != secretNumber);
    
    return 0;
}
