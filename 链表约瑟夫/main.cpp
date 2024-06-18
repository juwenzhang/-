#include <iostream>
#include "game.h"
using namespace std;

int main() {
    int numOfBoys, m, k;
    cout << "please input the number of boys and m of counting:" << endl;
    cin >> numOfBoys >> m;
    if (numOfBoys <= 0 || m > numOfBoys || m <= 0) {
        cout << "Please input reasonable values" << endl;
        return 0;
    }
    cout << "请输入从第几个小孩开始数：" << endl;
    cin >> k;
    if (k <= 0 || k > numOfBoys) {
        cout << "起始位置不合法！" << endl;
        return 0;
    }
    playGame(numOfBoys, m, k);
    return 0;
}