#include<iostream>
using namespace std;
int main() {
	int numOfBoy;
	cout << "����ӵ�м���С����" << endl;
	cin >> numOfBoy;
	if (numOfBoy <= 0)
	{
		cout << "С��Ӧ�ô���";
		return 0;
	}
	//int n, m, k; //�����������������ڼ�����ʼ
	//cin >> n >> m >> k;
	int* boy = new int[numOfBoy];
	int i; //�������õģ�����������һ����
	for (i = 0; i < numOfBoy; i++)
		boy[i] = i + 1;
	int m; //���
	cout << "��������" << endl;
	cin >> m;
	if (m <= 1) {
		cout << "�����ôҲ����һ��";
		return 0;
	}
	cout << "����ӵڼ�����ʼ����" << endl;
	int k;
	cin >> k; //����ӵڼ�����ʼ�أ�
	if (k > numOfBoy || k <= 0) {
		cout << "��ʼ��������Ӧ����0��" << numOfBoy << "֮��" << endl;
	}
	int kk = k - 1;
	for (i = 0; i < numOfBoy; i++)
		cout << boy[i] << ',';
	cout << endl;
	i = 0;
	int j = 0;//���������Ŀ�������������
	int n = numOfBoy;
	while (n > 1)
	{
		do
		{
			//if (boy[i % 7] != 0)
			if (boy[kk % numOfBoy] != 0)
			{
				j++;
			}
			//i++;
			kk++;
		} while (j < m);
		//����m���ͻ���һ��
		kk--;
		//i--;
		j = 0;
		//cout << "�뿪��С����:" << boy[i % 7] << endl;
		cout << "�뿪��С����:" << boy[kk % numOfBoy] << endl;
		//boy[i % 7] = 0;
		boy[kk % numOfBoy] = 0;

		n--;
	}
	//�����˾�ʣ��һ����
	for (i = 0; i < numOfBoy; i++) {
		if (boy[i] != 0) {
			cout << "С��" << boy[i] << "Ӯ��" << endl;
		}
	}

	return 0;
}