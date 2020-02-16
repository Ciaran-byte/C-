
//程序功能：对象是在初始化的时候被构建，离开作用域的时候被释放
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
	cout << "这是构造函数contributor" << endl;
}


A::~A()
{
	cout << "这是析构函数decontributor" << endl;
}

void A::print_size(int a)
{
	size = a;
	cout << "size = " << size << endl;
}



int main()
{
	cout << "进入括号之前" << endl;
	{
     //括号表示类的作用域，出了括号之后，类就没有了
		A a;
		a.print_size(10);


	}
	cout << "进入括号之后" << endl;
	return 0;
}






// 构造函数在对象被创建的时候调用，没有返回类型，但是可以具有参数。析构函数前面有个波浪号~,在对象被释放的时候调用，没有返回类型，同时也不允许有传入参数。
//运行程序之后，可以发现，出了大括号类A的实例a离开了作用域，触发了析构函数