#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//01�ж�vector�Ƿ�ǿգ������жϵ�2�������Ƿ�Ϊ2
	vector<int> m = { 1,2,3,4 };
	bool rst;
	if (!m.empty() && m[1] == 2)
	{
		rst = true;
	}
	else
	{
		rst = false;
	}

	cout << rst << endl;

	//02 ָ�����ָ��ʵ������һ������
	vector<int>* p = &m;
	
	//���ʳ�Ա�����ķ���
	bool emp = p->empty();
	cout << emp << endl;
	//�����±�ķ���
	cout << (*p)[2] << endl;

	
	//ע�����ʹ��ָ�룬һ��Ҫ�ж�ָ���Ƿ�Ϊ�ǿգ�ʹ�ö�·����ʵ����һ���̼���
	//����д�����£�
	bool rst2;
	if (p && !p->empty() && (*p)[1] == 2)
	{
		rst2 = true;
	}
	else
	{
		rst2 = false;
	}
	cout << rst2 << endl;
	return 0;
}
