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
	//01 ���е�ģ��ʵ������һ����̬����
	A<int> a1;
	a1.a = 5;
	A<int> a2;
	cout << a2.a << endl;

	//02 ��ͬʵ���ľ�̬�����Ƕ�����
	A<double> a3;
	cout << a3.a << endl;

	//03 �ھ�̬�����Ķ��崦ָ����̬������ֵ����ʹ�����е����еľ�̬���������г�ʼ����������Ȼ�໥����
	A<double> a4;
	cout << a4.a << endl;
	cout << a2.a << endl;
	return 0;
}

