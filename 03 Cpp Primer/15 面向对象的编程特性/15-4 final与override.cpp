#include<iostream>
using namespace std;
class A
{
public:
	virtual void f1(){}
	virtual void f2() {}
	virtual void f3()final{}
};

class B:A
{
public:
	virtual void f1(int)override{} //有override的函数会报错，便于排除错误

	virtual void f2(int) {} //没加override的虚函数，即使不完全匹配，继承类函数不能覆盖基类函数，也不报错
	                       //会导致排除困难

	virtual void f3(); //报错，虚函数f3不允许被重新定义
};

int main()
{

	return 0;
}

