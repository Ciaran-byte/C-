#include<iostream>
using namespace std;

int* (*f)(int* ); //定义函数指针

int* fun(int* p)
{
	return p;
}

int main()
{
	//01 直接使用函数
	int a = 5;
	
	int* c = fun(&a);
	(*c) = 6;
	cout<<a<<endl;

	//02 使用函数指针
	f = fun;
	int* d = f(&a);
	(*d) = 8;
	cout << a << endl;


	return 0;
}

