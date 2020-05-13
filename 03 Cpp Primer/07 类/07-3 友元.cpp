#include<iostream>
using namespace std;

class A
{
	friend class B;
	friend void print2(A a);
private:
	int a = 3;
};

//01 ���ⲿ�ඨ��Ϊ��Ԫ
class B
{
public:
	void print(A a)
	{
		cout << a.a << endl;
	}
};

//02 ���ⲿ��������Ϊ��Ԫ
void print2(A a)
{
	cout << a.a << endl;
}

//03 ���ⲿ��ĳ�Ա��������Ϊ��Ԫ
class D;
class C
{
public:
	void print3(D d);
};
class D
{
	friend void C::print3(D d);
private:
	int d = 3;
};

void C::print3(D d)
{

	cout << d.d << endl;

}

int main()
{


	//01 ���ඨ��Ϊ��Ԫ
	A a;
	B b;
	b.print(a);

	//02 ���ⲿ��������Ϊ��Ԫ
	print2(a);
	//03 *�����ں�������Ϊ��Ԫ�ķ���
	//���ֶ��巽��һ��Ҫ���Ǻ���Ľṹ��֪������˳��˭��˭��
	D d;
	C c;
	c.print3(d);
	
}