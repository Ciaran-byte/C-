#include<iostream>
using namespace std;

int main()
{
	// 01 bad����ֻҪ�ǳ����ص�ϵͳ������ʱ���Żᱨ��
	if (cin.bad())
	{
		cout << "cin is bad" << endl;
	}
	else
	{
		cout << "cin is not bad" << endl;
	}
	//02 fail��һ�ֶ�ȡʧ�ܵ�״̬��������Ҫһ��int������һ��char���޷�ת�������ܹ�ʹfailΪtrue
	int i;
	cin >> i;
	if (cin.fail())
	{
		cout << "cin is fail" << endl;
	}
	else
	{
		cout << "cin is not fail" << endl;
	}

	//03 eof �Ƿ񵽴��ļ����,���� ctrl+z���ǽ�����
	int m;
	cin >> m;
	if (cin.eof())
	{
		cout << "������" << endl;
	}
	else
	{
		cout << "û����" << endl;
	}

	//04 good״̬���ǳ�ȥbad,fail,eof�����״̬
	int n;
	cin >> n;
	if (cin.good())
	{
		cout << "�ã�" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
	return 0;
}

