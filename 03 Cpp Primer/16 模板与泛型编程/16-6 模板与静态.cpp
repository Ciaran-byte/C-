#include<iostream>
using namespace std;

template<typename T>
class A
{
public:
	static int a;
};
template<typename T>
int A<T>::a=1;
int main()
{
	//01 所有的模板实例共有一个静态对象
	A<int> a1;
	a1.a = 5;
	A<int> a2;
	cout << a2.a << endl;

	//02 不同实例的静态对象是独立的
	A<double> a3;
	cout << a3.a << endl;

	//03 在静态变量的定义处指定静态变量的值，会使得所有的类中的静态变量都进行初始化，但是仍然相互独立
	A<double> a4;
	cout << a4.a << endl;
	cout << a2.a << endl;
	return 0;
}

