#include<iostream>
#include<array>
#include<vector>
#include<string>
#include<list>
#include<deque>
using namespace std;
int main()
{

	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 2,3,4 };
	//01 insert����ʹ�÷���
	v1.insert(v1.begin(), 1); //��ĳ��λ�ò���ֵ
	v1.insert(v1.begin(), v2.begin(), v2.end()); //��Χ��ֵ
	v1.insert(v1.begin(), 10, 5);//����̶�����
	v1.insert(v1.begin(), { 1,2,3,4,5 });//�����б�

	//02 ʹ��insert����ֵʵ����������
	int i;
	auto it = v1.begin();
	while (cin >> i)
	{
		it = v1.insert(it, i);//insert����ֵ�ǲ������ֵ�ĵ�һ��λ��
	}
	

	return 0;
}

