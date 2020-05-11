#include<iostream>
using namespace std;
//01 函数变量名与外部函数名同名会引发函数屏蔽
string init()
{
	return "hello";
}

void print()
{
	string s=init();
	cout << s << endl;
}


//void print2()
//{
//	int init = 0;
//	string s = init();
//	cout << s << endl;
//}

//02 同名的局部函数声明，会引发函数屏蔽
void p(int i);
void p(const string& s);
void p(double val);

void foo()
{
	//能够正常构成函数重载
	p(1);
	p("hello");
	p(3.14);
}

void foo2()
{
	void p(int i); //这是一个局部的函数声明

	p(1);   //不构成函数重载，因为局部函数声明把外面的函数声明给屏蔽了
	p(3.14);
	//p("hello");

}
int main()
{
	//01 变量名与外部函数名同名，会引发函数屏蔽

	//函数屏蔽与变量屏蔽现象类似

	print(); //可以正常使用
	//print2(); //不能正常使用，找不到init函数了


	//02 同名的局部函数声明，会引发函数屏蔽

	//重载函数只要被声明在同一个作用域下，才能构成重载，否则就发生了函数屏蔽的现象。
	foo();

	foo2(); //p函数无法构成重载，发生了函数屏蔽
	return 0;
}


void p(int i)
{
	cout << i << endl;
}
void p(const string& s)
{
	cout << s << endl;
}
void p(double val)
{
	cout << val << endl;
}