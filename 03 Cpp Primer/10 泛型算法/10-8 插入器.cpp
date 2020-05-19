#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main()
{
	//�������������� back_inserter,front_inserter,inserter
	//����back_inserter����������룬front_inserter����ǰ����룬inserter�����м����
	//01 back_inserter
	//ʹ��back_inserter�������������push_back����

	list<int> a = { 1,2,3 };
	auto it1 = back_inserter(a);
	*it1 = 5;
	for (auto i : a)
	{
		cout << i << endl;
	}
	//���Կ���5�ŵ������

	//02 front_inserter
	//ʹ��front_inserter�����������ܹ�ʹ��push_front
	cout << endl;
	list<int> b = { 1,2,3 };
	auto it2 = front_inserter(b);
	*it2 = 6;
	for (auto i : b)
	{
		cout << i << endl;
	}

	//03 inserter
	//���м����
	cout << endl;
	list<int>c = { 1,2,3,4 };
	auto iter = find(c.begin(), c.end(), 3);

	auto it = inserter(c, iter);
	*it = 0;
	for (auto i : c)
	{
		cout << i << endl;
	}
	//�ȼ���
	cout << endl;
	c.insert(iter, 0);
	it++;
	for (auto i : c)
	{
		cout << i << endl;
	}
	return 0;
}

