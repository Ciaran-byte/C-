#include<iostream>
using namespace std;
void func(int& x) //����������
{
	x += 1;
}
int main()
{
	int c = 47;
	int& r = c;  //&��ʾ����

	const int& m = c;//ǰ�����const��˼�ǣ����ǲ���ͨ��m�޸�c�����ǿ���ͨ��c���޸�m
	func(c);
	cout << c << endl << r << endl << m << endl;
	return 0;
}

//�����ֿ��Խ������������ڱ�������ԣ���˼���ǣ�ʹ��r����ʹ��c��ֻ�����ֲ�ͬ



