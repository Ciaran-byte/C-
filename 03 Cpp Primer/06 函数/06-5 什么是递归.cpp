#include<iostream>
using namespace std;

//01 �ݹ������-�Լ������Լ�
void �����̽�����()
{
	cout << "��ǰ����ɽ��ɽ�������������и�С�����ڽ����£�" << endl;
	�����̽�����();
}

//02 �׳�
int �׳�(int val)
{
	if (val == 0)
		return 1;
	else
		return val * �׳�(val - 1);
}
int main()
{
	//01 �ݹ������ �Լ������Լ�
	//�����̽�����();

	//02 �׳�
	cout << �׳�(5) << endl;

	//�ݹ���ŵ㣺�������
	//�ݹ��ȱ�㣺 ռ�ô�������
	return 0;
}

