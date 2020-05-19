#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main()
{
	//插入器包括三种 back_inserter,front_inserter,inserter
	//其中back_inserter是往后面插入，front_inserter是往前面插入，inserter是往中间插入
	//01 back_inserter
	//使用back_inserter的容器必须具有push_back函数

	list<int> a = { 1,2,3 };
	auto it1 = back_inserter(a);
	*it1 = 5;
	for (auto i : a)
	{
		cout << i << endl;
	}
	//可以看到5放到了最后

	//02 front_inserter
	//使用front_inserter的容器必须能够使用push_front
	cout << endl;
	list<int> b = { 1,2,3 };
	auto it2 = front_inserter(b);
	*it2 = 6;
	for (auto i : b)
	{
		cout << i << endl;
	}

	//03 inserter
	//往中间插入
	cout << endl;
	list<int>c = { 1,2,3,4 };
	auto iter = find(c.begin(), c.end(), 3);

	auto it = inserter(c, iter);
	*it = 0;
	for (auto i : c)
	{
		cout << i << endl;
	}
	//等价于
	cout << endl;
	c.insert(iter, 0);
	it++;
	for (auto i : c)
	{
		cout << i << endl;
	}
	return 0;
}

