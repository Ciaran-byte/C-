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
	//list��vector�������룬vector��ַ���������ģ�list��ַ���ǲ������ģ�ֱ�ӵ�ַ++������������list
	//�����Ҫ����ַ����һ�㣬�ڵ��������������һ���Ĳ���
	vector<int> vec = { 1,2,3,4,5,6 };
	list<int> lst = { 1,2,3,4,5,6 };
	while (1)
	{
		cout << "�ĸ�����" << endl;
		int val;
		cin >> val;

		if ((find1(lst.begin(), lst.end(), val)) != lst.end())
		{
			cout << "������" << endl;

		}
		else
		{
			cout << "��������" << endl;
		}
		display<vector<int>::iterator>(vec.begin(), vec.end());
	}
	
	return 0;
}