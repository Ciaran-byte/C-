#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main()
{
	//01 ��ֵ
	//array֧�ָ�ֵ���㣬���Ǳ�����������ֵ��ͬ
	vector<int> v1 = { 1,2,3 };
	vector<int> v2;
	//ֱ�Ӹ�ֵ
	v2 = v1;
	//ʹ���б�ֵ
	v2 = { 1,2,3,4,5 };
	
	array<int, 10> ar = { 0 };
	array<int, 10> ar2;
	ar2 = ar;
	//02 swap
	//�������������еı���

	//ԭʼ��ֵ
	vector<int> v3 = { 1,2,3,4,5 };
	vector<int> v4 = { 2,3,4,6,7,8 };
	for (auto& i : v3)
	{
		cout << i << endl;
	}
	cout << endl;

	for (auto& i : v4)
	{
		cout << i << endl;
	}
	cout << endl;

	//����һ��
	swap(v3, v4);
	for (auto& i : v3)
	{
		cout << i << endl;
	}
	cout << endl;

	for (auto& i : v4)
	{
		cout << i << endl;
	}
	cout << endl;

	//�ٽ���һ��
	v3.swap(v4);
	for (auto& i : v3)
	{
		cout << i << endl;
	}
	cout << endl;

	for (auto& i : v4)
	{
		cout << i << endl;
	}
	cout << endl;
	//03 assign
	//��һ��������������滻��ǰ������������
	vector<int> v5 = { 1,2,3,4,5 };
	vector<int> v6 = { 0,1,2,3,4 };

	//��v6�е�Ԫ��ȡ��ԭ��v5��ֵ
	v5.assign(v6.begin(), v6.end());
	for (auto& i : v5)
	{
		cout << i << endl;
	}
	cout << endl;

	//���б�ȡ��v5��ֵ
	v5.assign({ 6,7,8,9 });
	for (auto& i : v5)
	{
		cout << i << endl;
	}
	cout << endl;

	//��5��6������v5��ֵ
	v5.assign(5, 6);
	for (auto& i : v5)
	{
		cout << i << endl;
	}
	cout << endl;
	return 0;
}


