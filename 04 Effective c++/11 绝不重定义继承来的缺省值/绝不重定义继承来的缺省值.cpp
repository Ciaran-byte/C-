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
		f(x); //这样为virtual定义缺省值的好处是，一旦需要修改，只修改no-virtual函数即可
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
	//01 不要重新定义继承来的缺省值
	B b;
	A* p = &b;
	p->f1();
	//在这个例子中，f1是动态的，p的动态类型是B，所以f1会调用B的函数，但是f1的缺省值是静态的
	//p的静态类型是A，因此继承了A中的缺省值5，因此会输出5和B

	//02 使用NVI设计方法，可以使得virtual函数有统一的、互相不依赖的默认值
	//(NVI no virtual interface)公有的no-virtual函数调用私有的virtual函数
	cout << endl;
	BB bb;
	AA* pa = &bb;
	pa->f1();
	AA aa;
	aa.f1();
	return 0;
}


