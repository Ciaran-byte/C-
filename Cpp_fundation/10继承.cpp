//�����ܣ���04����һ������������һ��B�̳�

#include<iostream>
using namespace std;

class A
{
private:
	int size;
public:
	A();
	~A();
	void print_size(int a);
};

A::A()
{
	cout << "����A���캯��contributor" << endl;
}


A::~A()
{
	cout << "����A��������decontributor" << endl;
}

void A::print_size(int a)
{
	size = a;
	cout << "size = " << size << endl;
}

class B :public A
{
public:
	B()
	{
		cout << "���ǹ���B����contributor" << endl;
	}
	~B()
	{
		cout << "����B��������decontributor" << endl;
	}
};


int main()
{
	cout << "��������֮ǰ" << endl;
	{
    // ���ű�ʾ��������򣬳�������֮�����û����
		B b;
		b.print_size(10);


	}
	cout << "��������֮��" << endl;
	return 0;
}



//ע��1���ӳ����п��Կ�����B�̳���A֮�󣬾�ӵ����A�����нṹ�����Ƕ���private���Եı������ߺ�����A������B��Ȼ����Ȩ���õġ�