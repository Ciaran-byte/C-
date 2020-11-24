#include<iostream>
using namespace std;
//01 B类说明，继承中，子类的同名函数会覆盖父类函数
//02 C类说明，使用using，可以开放A中的同名函数，重新构成重载
//03 D类说明，通过private继承，加上转交函数的方法A::f1()，可以实现只重载父类中部分函数
class A
{
public:
	void f1() { cout << "A::f1" << endl; }
	void f1(int x) { cout << "A::f1" << endl; }
	void f1(string x) { cout << "A::f1" << endl; }
	void f2() { cout << "A::f2" << endl; }
	
private:

};
class B:public A
{
public:
	void f1(int x) { cout << "B::f1" << endl; }
};

class C:public A
{
public:
	using A::f1;
	void f1(int x) { cout << "C::f1" << endl; }
};


class D :private A
{
public:
	void f1(int x) { cout << "D::f1" << endl; }
	void f1() { A::f1(); }
};
int main()
{
	B b;
	//b.f1(); //不能允许，同名函数被覆盖了
	b.f1(5);
	b.f2();
	cout << endl;

	C c;
	c.f1(); //c可以调用，因为通过using语句，使得A中的所有f1都可见了
	c.f1(5);
	c.f1("12");
	c.f2();
	cout << endl;

	D d;
	d.f1();
	d.f1(5);
	//d.f1(("12"); //不能调用，因为通过private继承，A中的函数都不能继承，通过转交函数的方法，可以实现只继承部分A中的函数
	return 0;
}

