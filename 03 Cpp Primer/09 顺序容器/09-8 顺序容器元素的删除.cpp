#include<iostream>
#include<list>
#include<vector>
using namespace std;


int main()
{
	list<int> lst = { 0,1,2,3,4,5,6 };

	//01 删除首尾元素
	lst.pop_back();
	lst.pop_front();
	for (auto i : lst)
	{
		cout << i << endl;
	}

	//02 删除内部的一个元素
	//erase删除给定迭代器位置上的元素，并且返回删除元素的下一个元素的迭代器
	//比如我们删除全部的奇数
	cout << endl;
	auto it = lst.begin();
	while( it != lst.end())
	{
		if ((*it) & 1)
		{
			it=lst.erase(it);
		}
		else
		{
			it++;
		}
	}
	for (auto i : lst)
	{
		cout << i << endl;
	}

	//03 删除内部多个元素
	cout << endl;
	vector<int> vec = { 1,2,3,4,5,6,7,8,8 };
	vec.erase(vec.begin() + 2, vec.end() - 2); //删除区间左闭右开。并且会返回删除最后元素的下一个元素的迭代器地址
	for (auto i : vec)
	{
		cout << i << endl;
	}

	//04 删除全部元素
	vec.clear();
	//或者 vec.erase(vec.begin(),vec.end());
	
	return 0;
}

