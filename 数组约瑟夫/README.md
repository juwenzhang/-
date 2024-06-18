# 数组约瑟夫



## 1.源代码

我这个里面值创建了一个文件：game.cpp

```C++
#include<iostream>
using namespace std;
int main() {
	int numOfBoy;
	cout << "你想拥有几个小孩？" << endl;
	cin >> numOfBoy;
	if (numOfBoy <= 0)
	{
		cout << "小孩应该存在";
		return 0;
	}
	//int n, m, k; //总人数，数到几，第几个开始
	//cin >> n >> m >> k;
	int* boy = new int[numOfBoy];
	int i; //纯计数用的，看数数到哪一个了
	for (i = 0; i < numOfBoy; i++)
		boy[i] = i + 1;
	int m; //间隔
	cout << "请输入间隔" << endl;
	cin >> m;
	if (m <= 1) {
		cout << "间隔怎么也大于一吧";
		return 0;
	}
	cout << "你想从第几个开始数？" << endl;
	int k;
	cin >> k; //你想从第几个开始呢？
	if (k > numOfBoy || k <= 0) {
		cout << "开始数的区间应该在0到" << numOfBoy << "之间" << endl;
	}
	int kk = k - 1;
	for (i = 0; i < numOfBoy; i++)
		cout << boy[i] << ',';
	cout << endl;
	i = 0;
	int j = 0;//来个计数的看数数到哪里了
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
		//数到m个就会走一个
		kk--;
		//i--;
		j = 0;
		//cout << "离开的小孩是:" << boy[i % 7] << endl;
		cout << "离开的小孩是:" << boy[kk % numOfBoy] << endl;
		//boy[i % 7] = 0;
		boy[kk % numOfBoy] = 0;

		n--;
	}
	//都走了就剩下一个了
	for (i = 0; i < numOfBoy; i++) {
		if (boy[i] != 0) {
			cout << "小孩" << boy[i] << "赢了" << endl;
		}
	}

	return 0;
}
```

最后的效果是通过我们的指针和数组来实现的



## 2.显示效果



<a href="../数组约瑟夫.mp4">显示效果</a>