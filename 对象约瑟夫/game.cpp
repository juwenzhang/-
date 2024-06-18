#include <iostream>
using namespace  std;

//1.定义小朋友节点
class Child
{

public:
	int childNo;
	Child* leftchild;
	Child* rightchild;


public:
	//构造函数
	Child(int num = 0)
	{
		childNo = num;
		leftchild = NULL;
		rightchild = NULL;
	}

};

//2.定义圆圈游戏
class Circle
{
public:
	int scale;
	Child children[1000];

public:
	// 构造函数：初始化每个小孩对象节点的编号
	Circle(int num = 1000)
	{
		scale = num;


		for (int i = 0; i < num; i++)
		{
			children[i] = Child(i);
		}
	};

	//构建节点的循环链表函数：确立每个小孩的左右邻居
	void Build()
	{
		for (int i = 0; i < scale; i++)
		{
			if (i == 0)
			{
				children[i].rightchild = &children[1];
				children[i].leftchild = &children[scale - 1];
			}
			else if (i == (scale - 1))
			{
				children[i].rightchild = &children[0];
				children[i].leftchild = &children[scale - 2];
			}
			else
			{
				children[i].rightchild = &children[i + 1];
				children[i].leftchild = &children[i - 1];
			}
		}

	}
	//游戏运行函数：从当前节点顺时针循环开始数num个数
	void Run(int T)
	{
		int count = 1;
		Child* current = &children[0];
		while (scale > 1)
		{
			//quit the circle
			if (count == T)
			{
				// 当前数到T的小孩退出游戏，参与游戏人数减少1个
				scale = scale - 1;

				//把当前的这个小孩的左右邻居用链表连接起来(相当于删除改结点)
				current->leftchild->rightchild = current->rightchild;
				current->rightchild->leftchild = current->leftchild;
				current = current->rightchild;
				count = 1;
			}
			else  //count the next                          
			{
				count = count + 1;
				current = current->rightchild;
			}

		}

		//打印最后一个小孩的编号
		cout << " 最后胜利的小孩是： " << current->childNo << endl;
	}
};

// 开始书写测试函数
void test() {
	while (true)
	{
		int select;
		cout << "请输入是否开始游戏（1--继续游戏； 2--结束游戏）:" << endl;
		cin >> select;
		switch (select) {
		case 1:
		{
			int m, n;
			cout << "请输入参与的总人数m的值：" << endl;
			cin >> m;
			cout << "请输入淘汰的铭感数字n的值：" << endl;
			cin >> n;
			if (m > n) {
				// 开始对前面的内容进行删除
				system("cls");

				Circle nodes(m); // 圆圈类内有100个节点对象（小孩）

				nodes.Build();

				nodes.Run(n);     // 开始循环运行数“7”的游戏，输出最后的获胜者
			}

			else {
				cout << "输入的内容不满足游戏开展要求，请重新输入...";
				continue;
			}
		}
		break;
		case 2:
			system("pause");
			return;
			break;
		}
	}
}

// 入口函数的实现
int main()
{

	test();
	return 0;

}