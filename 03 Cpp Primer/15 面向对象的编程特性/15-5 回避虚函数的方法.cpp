#include<iostream>
using namespace std;
class A
{
public:
	virtual void f1() { cout << "A" << endl; }
};

//02 应用：对虚函数进行回避的应用就是在派生类中希望调用基类的虚函数
class B :public A
{
public:
	virtual void f1()
	{
		cout << "B" << endl;
		A::f1();
	}
};

//01 方法：如果我们不想动态调用虚函数，而是向准确的使用哪个类的虚函数，应该使用作用域运算符
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

