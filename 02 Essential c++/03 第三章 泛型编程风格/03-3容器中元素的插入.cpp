#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> ilist = { 1,2,3,4,5,6,7 };

	//01 ��һ�ֲ��뷽������ָ����ַǰ����
	list<int>::iterator it = find(ilist.begin(), ilist.end(), 7);
	ilist.insert(it, 5);
	//02 �ڶ��ַ�������ָ����ַǰ����n����ͬ����
	ilist.insert(it, 3, 5);//��it�ĵ�ַǰ�����3��5
	//03 �����ַ�������ָ����ַǰ�����һ������������
	int a1[] = { 2,3,4,5,6 };
	list<int>add(a1, a1 + 5); //�����ȡ��[left,right) �����ұ��Ǹ�����ѡ���ʱ��Ӧ��������ȡһ����ַ
	ilist.insert(it, add.begin(), add.end());
	//���Ӧ���� 1,2,3,4,5,6,5,5,5,5,2,3,4,5,6,7
	it = ilist.begin();
	list<int>::iterator end = ilist.end();
	for (; it != end; it++)
	{
		cout << (*it) << endl;
	}



	return 0;
}

