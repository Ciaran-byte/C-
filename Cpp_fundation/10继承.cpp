//程序功能：与04基本一样，不过加了一个B继承

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
	cout << "这是A构造函数contributor" << endl;
}


A::~A()
{
	cout << "这是A析构函数decontributor" << endl;
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
		cout << "这是构造B函数contributor" << endl;
	}
	~B()
	{
		cout << "这是B析构函数decontributor" << endl;
	}
};


int main()
{
	cout << "进入括号之前" << endl;
	{
    // 括号表示类的作用域，出了括号之后，类就没有了
		B b;
		b.print_size(10);


	}
	cout << "进入括号之后" << endl;
	return 0;
}



//注解1：从程序中可以看出，B继承了A之后，就拥有了A的所有结构，但是对于private属性的变量或者函数，A的子类B仍然是无权调用的。