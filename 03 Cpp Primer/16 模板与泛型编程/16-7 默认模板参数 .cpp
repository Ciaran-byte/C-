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
	//01 ģ�庯��ʹ��Ĭ��ֵ
	f();

	//02 ģ����ʹ��Ĭ��ֵ
	A<> a;
	return 0;
}

