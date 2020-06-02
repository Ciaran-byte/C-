#include<iostream>
using namespace std;

template<typename T = double>
void f()
{
	T t;
	cout << typeid(t).name() << endl;
}
template<typename T=int,typename Q =double>
class A
{

};
int main()
{
	//01 模板函数使用默认值
	f();

	//02 模板类使用默认值
	A<> a;
	return 0;
}

