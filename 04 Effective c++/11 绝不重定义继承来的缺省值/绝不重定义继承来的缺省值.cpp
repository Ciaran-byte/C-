#include<iostream>
using namespace std;
class A
{
public:
	virtual void f1(int x = 5) {
		cout << x << endl;
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	virtual void f1(int x = 7)
	{
		cout << x << endl;
		cout << "B" << endl;
	}
};

class AA
{
public:
	void f1(int x = 5)const
	{
		f(x); //����Ϊvirtual����ȱʡֵ�ĺô��ǣ�һ����Ҫ�޸ģ�ֻ�޸�no-virtual��������
	}
private:
	virtual void f(const int& x) const
	{
		cout << x << endl;
		cout << "AA" << endl;
	}
};
class BB :public AA
{
public:
private:
	virtual void f(const int& x)const
	{
		cout << x << endl;
		cout << "BB" << endl;
	}
};
int main()
{
	//01 ��Ҫ���¶���̳�����ȱʡֵ
	B b;
	A* p = &b;
	p->f1();
	//����������У�f1�Ƕ�̬�ģ�p�Ķ�̬������B������f1�����B�ĺ���������f1��ȱʡֵ�Ǿ�̬��
	//p�ľ�̬������A����˼̳���A�е�ȱʡֵ5����˻����5��B

	//02 ʹ��NVI��Ʒ���������ʹ��virtual������ͳһ�ġ����಻������Ĭ��ֵ
	//(NVI no virtual interface)���е�no-virtual��������˽�е�virtual����
	cout << endl;
	BB bb;
	AA* pa = &bb;
	pa->f1();
	AA aa;
	aa.f1();
	return 0;
}


