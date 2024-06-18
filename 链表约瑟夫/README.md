# 链表约瑟夫



## 1.首先创建了一个game.h

进行创建这个头文件，里面用于存储了我们的链表的结点的基本结构

其中含有链表的数据域和指针域

```C++
#ifndef GAME_H
#define GAME_H

struct Boy {
    int code;
    Boy* pNext;
};

void playGame(int numOfBoys, int m, int k);

#endif
```



## 2.然后进行创建game.cpp

在这个里面我们实现了约瑟夫游戏的一些链表的基本功能

```C++
#include <iostream>
#include <iomanip>
#include "game.h"
using namespace std;
//定义指针
Boy* pFirt = 0; //第一个小孩指针
Boy* pCurrent = 0;//当前小孩指针
Boy* pivot = 0;//前一个小孩指针
void playGame(int numOfBoys, int m, int k) {
	pFirt = new Boy;
	pFirt->code = 1;
	pFirt->pNext = NULL;
	pCurrent = pFirt;
	for (int i = 1; i < numOfBoys; i++)
	{
		pivot = pCurrent;//前一个小孩变成之前的当前小孩
		pCurrent = new Boy;
		pCurrent->code = i + 1;//小孩编号
		pivot->pNext = pCurrent;//接到前一个小孩后面
	}
	pCurrent->pNext = pFirt; //最后一个小孩的后一个是第一个
	//输出圆圈中所有的小孩
	// 从第几个开始数，就把pFirt变成第几个就行

	for (int i = 1; i < k; i++) {
		pFirt = pFirt->pNext;
	}
	pCurrent = pFirt;
	cout << setw(4) << pFirt->code; // 输出当前小孩
	pCurrent = pFirt->pNext;
	while (pCurrent != pFirt)
	{
		cout << setw(4) << pCurrent->code;
		pCurrent = pCurrent->pNext;
	}
	cout << endl;
	//ok小孩可以走了
	//当前位置设置为第一个小孩
	pCurrent = pFirt;
	int j;
	while (pCurrent->pNext != pCurrent)
	{//数到第m个小孩离开
		j = m;
		do {
			pivot = pCurrent;
			pCurrent = pCurrent->pNext;
			j--;
		} while (j > 1);
		//第m个小孩走了
		cout << setw(4) << pCurrent->code;
		pivot->pNext = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pivot->pNext;

	}
	cout << "\n\nthe winner is:"
		<< pCurrent->code << endl;
	delete pCurrent;
}
```



## 3.最后进行创建一个入口函数main.cpp

```C++
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
```



## 4.运行效果

<video src="../链表约瑟夫.mp4"></video>

