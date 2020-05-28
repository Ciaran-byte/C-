#include<iostream>
using namespace std;
class B;
class A
{
public:
	friend class B;
	A(int a):_a(a){}
	A(const B& b); 
private:
	int _a;
};

class B
{
public:
	friend class A;
	B(int b):_b(b){}
	operator A()const { return A(_b); }
private:
	int _b;
};
A::A(const B& b) { _a = b._b; }
A f(const A& a)
{
	return a;
}

class C
{
public:
	C(int a) :_a(a) { cout << "int" << endl; }
	C(double a) :_a(a) { cout << "double" << endl; }

	operator int() { return _a; }
	operator double() { return _a * 1.0; }
private:
	double _a;
};
void f2(long double m)
{

}
int main()
{
	
	//01 第一种二义性情况，两个不同的类同时定义了同一种类型转换
	B b(6);
	//A a = f(b); //从b转换为a有两条途径，一种是A的构造函数，一种是B的类型转换函数，二者等同，因此系统不知道该调用谁了
	A m = f(A(b)); //避免方法，明确使用的是哪个函数，是A的构造函数，还是B的类型转换函数
	A n = f(b.operator A());

	//02 多重类型转换
	//比如类c，支持两个int和double两种类型的输入，并且能够转换为int和double，那么
	long db = 10;
	//C c(db);  //都属于二义性，因此有多个函数能够成功匹配，并且他们中没有最优的
	//f2(c);
	return 0;
}

