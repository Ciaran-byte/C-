#include<iostream>
using namespace std;
class A
{
public:
	virtual void f1(){}
	virtual void f2() {}
	virtual void f3()final{}
};

class B:A
{
public:
	virtual void f1(int)override{} //��override�ĺ����ᱨ�������ų�����

	virtual void f2(int) {} //û��override���麯������ʹ����ȫƥ�䣬�̳��ຯ�����ܸ��ǻ��ຯ����Ҳ������
	                       //�ᵼ���ų�����

	virtual void f3(); //�����麯��f3���������¶���
};

int main()
{

	return 0;
}

