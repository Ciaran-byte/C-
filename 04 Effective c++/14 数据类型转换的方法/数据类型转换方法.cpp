#include<iostream>
using namespace std;

// ����ת��
//01 ��ʽ����ת��
// static_cast//��������������������͵�ת��
//const_cast ����const���Ե�ת��
//dynamic_cast ���ת�������ͺ��ʣ��᷵�ؿ�ָ�룬static_cast������Ͳ�����Ҳ��ת
//reinterpret_cast //�������������Ҳ��ת������ȫ����ǿ������ת��Ч����һ����

//02 ��ʽ����ת��

// int a = 5; double m = 1*1.0/2;
//��ʽ����ת���ܹ������������͵�����

//03 ǿ������ת�����Զ�������ת��
// double b = 0.5; (int)b

//�Զ�������ת�� operator int(){return xx;}
class A
{
public:
	 operator int()
	{
		return 5;
	}
	 operator double()
	 {
		 return 5.2;
	 }
};
int main()
{
	
	
	A a;
	cout << (int)a << endl;
	cout << (double)a << endl;
	return 0;
}

