#include<iostream>
#include<map>
#include<algorithm>
#include<utility>
using namespace std;
//����Ҫʵ�ִ�ӡһ�����ߵ�ȫ������

int main()
{
	multimap<string, string> author_books = { {"Mike","A1"},{"Mike","A2"},{"Mike","A3"},{"Mike","A4"} };
	//01 ����һ��ͨ��find������count����
	//��multi�������У�ͬ�ؼ��ֵ�Ԫ�صĴ��������ڵģ����Լ�¼ͬ���ĸ����������ڵ���ЩԪ�ض���ӡ��������
	size_t num = author_books.count("Mike");
	auto it = author_books.find("Mike");
	while (num)
	{
		
		cout << it->second << ends;
		++it;
		--num;
		
	}
	cout << endl;

	//02 ʹ��lower_bound��upper_bound
	auto it1 = author_books.lower_bound("KK");
	auto it2 = author_books.upper_bound("KK");
	cout << it1->second << endl;
	cout << it2->second << endl;
	//���������û�����Ԫ�أ����߻�ָ��ͬһ��λ��

	//������ӡ���ߵ�ȫ������
	//��Ϊlowerboundָ��С��Ԫ�صĵ�һ����Ҳ��������ͬ���ؼ���Ԫ�صĵ�һ��
	//upperboundָ�����Ԫ�صĵ�һ����Ҳ��������Ԫ�ص����һ������һ��λ��
	//���Կ���������Ϊ������Χ
	multimap<string, string>::iterator beg = author_books.lower_bound("Mike");
	multimap<string, string>::iterator ed = author_books.upper_bound("Mike");

	for (; beg!=ed; ++beg)
	{
		cout << beg->second << ends;
	}
	cout << endl;

	//03 ʹ��equal_range����
	//����ֵ�Ǹ�pair,������������������������Ԫ�أ���һ����������Ԫ�صĵ�һ�����ڶ���ֵ��������Ԫ�ص����һ������һ��
	//��upper_bound��lower_boundһ��ԭ������ʵ���������Ӽ�
	for (auto pos = author_books.equal_range("Mike"); pos.first != pos.second; pos.first++)
	{
		cout << pos.first->second << ends;
	}
	cout << endl;


	return 0;
}


