#include<iostream>
using namespace std;
//所谓接口继承是指，继承了函数名字，实现方法是子类重新定义的
//所谓实现继承是指，继承了父类函数的名字和实现方法

class A 
{
public:
	virtual void f1()  = 0;
};
void A::f1() 
{
	cout << "A:f1" << endl;
}

class B:public A
{
public:
	virtual void f1()  { cout << "B:f1" << endl; }
};

class C :public A
{
public:
	virtual void f1() { A::f1(); //作为缺省值进行使用，同时必须手动写出来，才能使用这个缺省函数，避免了不需要的时候
	//不会莫名其妙的定义不需要的缺省函数

	}

};

int main()
{
	//01 纯虚函数有自己的实现方法，并且可以通过明确类名来进行调用
	B b;
	A* a = &b;
	a->f1();
	a->A::f1();

	//02 纯虚函数可以作为缺省函数被派生类进行调用，同时能够保证子类必须调用纯虚函数的时候，才能使用
	//保证了不会莫名其妙的定义不需要的缺省函数
	C c;
	c.f1();


}