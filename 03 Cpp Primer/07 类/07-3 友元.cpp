#include<iostream>
using namespace std;

class A
{
	friend class B;
	friend void print2(A a);
private:
	int a = 3;
};

//01 把外部类定义为友元
class B
{
public:
	void print(A a)
	{
		cout << a.a << endl;
	}
};

//02 把外部函数定义为友元
void print2(A a)
{
	cout << a.a << endl;
}

//03 把外部类的成员函数定义为友元
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


	//01 把类定义为友元
	A a;
	B b;
	b.print(a);

	//02 把外部函数定义为友元
	print2(a);
	//03 *把类内函数定义为友元的方法
	//这种定义方法一定要考虑好类的结构，知道定义顺序谁先谁后
	D d;
	C c;
	c.print3(d);
	
}