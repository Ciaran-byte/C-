#include<iostream>
#include<list>
#include<vector>
using namespace std;


int main()
{
	list<int> lst = { 0,1,2,3,4,5,6 };

	//01 ɾ����βԪ��
	lst.pop_back();
	lst.pop_front();
	for (auto i : lst)
	{
		cout << i << endl;
	}

	//02 ɾ���ڲ���һ��Ԫ��
	//eraseɾ������������λ���ϵ�Ԫ�أ����ҷ���ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
	//��������ɾ��ȫ��������
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

	//03 ɾ���ڲ����Ԫ��
	cout << endl;
	vector<int> vec = { 1,2,3,4,5,6,7,8,8 };
	vec.erase(vec.begin() + 2, vec.end() - 2); //ɾ����������ҿ������һ᷵��ɾ�����Ԫ�ص���һ��Ԫ�صĵ�������ַ
	for (auto i : vec)
	{
		cout << i << endl;
	}

	//04 ɾ��ȫ��Ԫ��
	vec.clear();
	//���� vec.erase(vec.begin(),vec.end());
	
	return 0;
}

