#include <iostream>
#include <iomanip>
#include "game.h"
using namespace std;
//����ָ��
Boy* pFirt = 0; //��һ��С��ָ��
Boy* pCurrent = 0;//��ǰС��ָ��
Boy* pivot = 0;//ǰһ��С��ָ��
void playGame(int numOfBoys, int m, int k) {
	pFirt = new Boy;
	pFirt->code = 1;
	pFirt->pNext = NULL;
	pCurrent = pFirt;
	for (int i = 1; i < numOfBoys; i++)
	{
		pivot = pCurrent;//ǰһ��С�����֮ǰ�ĵ�ǰС��
		pCurrent = new Boy;
		pCurrent->code = i + 1;//С�����
		pivot->pNext = pCurrent;//�ӵ�ǰһ��С������
	}
	pCurrent->pNext = pFirt; //���һ��С���ĺ�һ���ǵ�һ��
	//���ԲȦ�����е�С��
	// �ӵڼ�����ʼ�����Ͱ�pFirt��ɵڼ�������

	for (int i = 1; i < k; i++) {
		pFirt = pFirt->pNext;
	}
	pCurrent = pFirt;
	cout << setw(4) << pFirt->code; // �����ǰС��
	pCurrent = pFirt->pNext;
	while (pCurrent != pFirt)
	{
		cout << setw(4) << pCurrent->code;
		pCurrent = pCurrent->pNext;
	}
	cout << endl;
	//okС����������
	//��ǰλ������Ϊ��һ��С��
	pCurrent = pFirt;
	int j;
	while (pCurrent->pNext != pCurrent)
	{//������m��С���뿪
		j = m;
		do {
			pivot = pCurrent;
			pCurrent = pCurrent->pNext;
			j--;
		} while (j > 1);
		//��m��С������
		cout << setw(4) << pCurrent->code;
		pivot->pNext = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pivot->pNext;

	}
	cout << "\n\nthe winner is:"
		<< pCurrent->code << endl;
	delete pCurrent;
}