#include<iostream>
using namespace std;
class base
{
public:
	virtual void out()
	{
		cout << "base" << endl;
	}
	virtual ~base(){}

};

class A:public base
{
public:
	virtual void out()
	{
		cout << "A" << endl;
	}
	virtual ~A(){}
};
int main()
{
	//对static_cast和dynamic_cast做对比
	//01 不安全的向上造型中，dynamic返回空指针，而static实现了，但是父类不能调用子类特化的东西
	base b;
	A a;
	base* p = &b;
	A* pa = dynamic_cast<A*>(p);
	cout << (pa == nullptr) << endl;
	
	A* pa1 = static_cast<A*>(p);
	cout << (pa1 == nullptr) << endl;

	//02 向下造型
	A* p2 = &a;
	base* pb = dynamic_cast<base*>(p2);
	cout << (pb == nullptr) << endl;

	base* pb2 = static_cast<base*>(p2);
	cout << (pb2 == nullptr) << endl;
	return 0;
}




