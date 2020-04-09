#include<iostream>
#include<vector>
#include<list>
using namespace std;

template<typename IteratorType> 
void display(IteratorType it,IteratorType end)
{
	
	for (; it != end; it++)
	{
		cout << (*it) << endl;
	}
}

template<typename IteratorType,typename elemType>
IteratorType find1(IteratorType it, IteratorType end, const elemType& value)
{
	for (; it != end; it++)
	{
		if ((*it) == value)return (it);
	}
	return end;
}
int main()
{
	//list和vector区别在与，vector地址上是连续的，list地址上是不连续的，直接地址++不能连续访问list
	//因此需要将地址抽象一层，在迭代器层面进行下一个的操作
	vector<int> vec = { 1,2,3,4,5,6 };
	list<int> lst = { 1,2,3,4,5,6 };
	while (1)
	{
		cout << "哪个数？" << endl;
		int val;
		cin >> val;

		if ((find1(lst.begin(), lst.end(), val)) != lst.end())
		{
			cout << "在里面" << endl;

		}
		else
		{
			cout << "不在里面" << endl;
		}
		display<vector<int>::iterator>(vec.begin(), vec.end());
	}
	
	return 0;
}