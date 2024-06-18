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