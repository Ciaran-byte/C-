#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//01 Ĭ�ϳ�ʼ��
	vector<int> v1;

	//02 ������ʼ��
	vector<int> v2(v1);
	vector<int> v3 = v2;

	//03 ��ʼ���б�
	vector<int> v4 = { 1,2,3 };
	vector<int> v5{ 1,2,3 };

	//04 ���峤�ȳ�ʼ��
	vector<int> v6(5);
	vector<int> v7(5, 1);
	//05 ʹ�õ�������ֵ
	vector<int> v8(v7.begin(), v7.end());
	
	return 0;
}

