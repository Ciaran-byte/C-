#include<iostream>
using namespace std;

class A
{
public:
	void f1() { cout << "f1" << endl; }
	void f1(int) { cout << "f1(int)" << endl; }
private:
};

class B:public A
{
public:
	using A::f1;
	void f1(double) { cout << "f1(double)" << endl; }
};
int main()
{
	B b;
	b.f1(int());
	b.f1();
	b.f1(double());
	return 0;
}

