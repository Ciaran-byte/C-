//程序功能说明：这个程序用来说明，在A类中，认为函数fa和类B是A的friend,这样的话，函数fa和类B就可以直接访问类A的实例a中的变量i了

#include<iostream>
using namespace std;

class A  //定义了一个类A，有一个私有的变量i，一个构造函数A用来赋予初值。通过给予了f函数fa和类B访问A类私有类型的权限
{
private:
	int i;
public:
	A(int i)
	{
		this->i = i;
	}
	friend class B;
	friend void fa(A* a);
};
void fa(A* a)   //定义了全局的函数fa，fa获取类A的实例a的指针，并且能够访问实例a中的变量i，如果类A中没有friend的定义，这里会报错
{
	cout << a->i<<endl;
}

class B   //定义了一个类B，类B可以接受类A的指针，并且修改A的实例a中的变量i。如果没有friend的定义，这里也会报错
{

public:
	A* a;
	B(A* a)
	{
		this->a = a;
	};
	void  fb(int i)
	{
		a->i = i;
		cout << a->i << endl;

	}

};




int main()
{
	
	A a(0);
	fa(&a);

	B b(&a);
	b.fb(5);



	return 0;
}



 //注解1：c++里面有一个关键词叫做friend,被类声明为friend的其他类，或者函数等，可以直接访问它的私有对象。不过，因为friend只能在类定义中写，所以，只要
 //类被写好了发布了，其实就不能再重新增加friend的定义了。
 //注解2  structure和class在c++里面基本是差不多的，structure在c语言中，内部可能只能定义变量，不能定义函数，但是在c++中写法跟class是完全一样的。
 //除了可以定义变量，也可以定义函数。而且也可以定了访问级别。唯一的一点区别在于，class中，你定义一个函数或者变量，没有写访问级别，默认是private
 //而在structure中，如果你没有定义访问级别，默认会是public