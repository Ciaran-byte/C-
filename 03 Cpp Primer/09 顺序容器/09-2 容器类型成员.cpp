#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v1 = { 1,2,3,4 };
	const vector<int> v2 = { 1,2,3,4 };
	//01 ��������
	vector<int>::iterator a1; 
	for (auto it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	cout << endl;

	//02 ��������
	//������������ͨ���������������ڣ���ͬͨ���������޸ı�����ֵ
	vector<int>::const_iterator cit = v2.cbegin();
	vector<int>::const_iterator cd= v2.cend();
	while (cit != cd)
	{
		cout << *cit << endl;
		cit++;
	}
	cout << endl;
	//03 ���������
	//������������Ƿ������
	vector<int>::reverse_iterator rit = v1.rbegin();
	vector<int>::reverse_iterator rd = v1.rend();
	while (rit != rd)
	{
		cout << *rit << endl;
		rit++;
	}
	cout << endl;

	//04 �����������
	vector<int>::const_reverse_iterator crit = v1.crbegin();
	vector<int>::const_reverse_iterator crd = v1.crend();
	while (crit != crd)
	{
		cout << *crit << endl;
		crit++;
	}
	cout << endl;
	//06 �������Ĳ�ֵ
	vector<int>::difference_type dt = v1.end() - v1.begin();
	cout << dt << endl;
	cout << endl;

	//07 ��������
	vector<int>::size_type vsz= v1.size();

	//08 Ԫ������
	vector<int>::value_type tv1 = 5;
	v1.push_back(tv1);

	//09 Ԫ�ص�����
	vector<int>::reference rv1 = v1[0];
	rv1 = 3;
	cout << v1[0] << endl;
	
	return 0;
}

