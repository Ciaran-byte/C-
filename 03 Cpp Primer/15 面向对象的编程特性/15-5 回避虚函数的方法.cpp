#include<iostream>
using namespace std;
class A
{
public:
	virtual void f1() { cout << "A" << endl; }
};

//02 Ӧ�ã����麯�����лرܵ�Ӧ�þ�������������ϣ�����û�����麯��
class B :public A
{
public:
	virtual void f1()
	{
		cout << "B" << endl;
		A::f1();
	}
};

//01 ������������ǲ��붯̬�����麯����������׼ȷ��ʹ���ĸ�����麯����Ӧ��ʹ�������������
void f(A& a)
{
	a.A::f1();
}


void f2(A& a)
{
	a.f1();
}
int main()
{
	B b;
	f(b);
	f2(b);
	return 0;
}

