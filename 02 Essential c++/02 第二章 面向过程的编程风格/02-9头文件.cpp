#include<iostream>
using namespace std;
extern int a  ;
extern int b;
extern int c;
int main()
{
	cout << a << endl;  //��ͨ���������ڴˣ������������ط�������ʹ��
	//cout << b << endl;//const���������ڴˣ������������ط�������ʹ�ã���Ϊconst����file��ʧЧ
	//cout << c << endl;//static ���������ڴˣ������������ط�������ʹ�ã�static������������
	return 0;
}

