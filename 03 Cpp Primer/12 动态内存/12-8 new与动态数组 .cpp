#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 动态数组的定义与初始化
	int* p1 = new int[5]();
	int* p2 = new int[5];
	int* p3 = new int[5]{ 1,2,3,4 }; //没给的地方会进行值初始化，变成0
	

	int* p4 = new int[0];  //合法的，但是不能进行解引用

	//02 动态数组的访问
	for (int* q = p3; q != p3 + 5; q++)
	{
		cout << *q << endl;
	}
	
	//03 动态数组的释放
	delete []p1;
	delete []p2;
	delete[]p3;
	delete[]p4;

	//04 使用智能指针管理动态数组
	//unique_ptr能够直接管理动态数组，支持下标操作
	cout << endl;
	unique_ptr<int[]> up(new int[10]);
	for (int i = 0; i < 10; i++)
	{
		up[i] = i;
		cout << up[i] << endl;
	}

	//使用shared_ptr必须定义自己的删除器，而且不支持下标操作
	cout << endl;
	shared_ptr<int> sp(new int[10], [](int* p) {delete[]p; });

	for (int i = 0; i < 10; i++)
	{
		*(sp.get() + i) = i;
		cout << *(sp.get() + i) << endl;
	}
	sp.reset();
	return 0;
}

