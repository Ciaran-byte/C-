#include<iostream>
using namespace std;

int* (*f)(int* ); //���庯��ָ��

int* fun(int* p)
{
	return p;
}

int main()
{
	//01 ֱ��ʹ�ú���
	int a = 5;
	
	int* c = fun(&a);
	(*c) = 6;
	cout<<a<<endl;

	//02 ʹ�ú���ָ��
	f = fun;
	int* d = f(&a);
	(*d) = 8;
	cout << a << endl;


	return 0;
}

