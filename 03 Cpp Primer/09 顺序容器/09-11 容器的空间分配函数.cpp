#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//capacity函数 当前最大容量
	//size函数 实际含有元素个数

	//shrink_to_fit 使容器退回多余的内存

	//reserve 函数 更改容器最大容量
	vector<int> a;
	for (int i = 0; i < 505; i++)
	{
		a.push_back(i);
		cout << a.capacity() << endl;
	}
	while (a.size() != a.capacity())
	{
		a.push_back(0);
	}
	cout << a.capacity() << endl; 
	a.push_back(0);
	cout << a.capacity() << endl;
	a.shrink_to_fit();
	cout << a.capacity() << endl;
	a.reserve(3000);
	return 0;
}

