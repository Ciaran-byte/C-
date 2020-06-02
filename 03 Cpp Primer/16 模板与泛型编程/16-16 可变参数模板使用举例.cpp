#include<iostream>

using namespace std;

template<typename T,typename...Args> //模板参数包,表示0-n个模板参数类型
void foo(const T& t, Args... rest)//函数参数包，表示0-n个函数参数
{
	cout << sizeof...(Args) << endl; //计算参数包和函数包参数的数量
	cout << sizeof...(rest) << endl;
}  
int main()
{
	int a = 1;
	double b = 0.1;
	string s = "123";
	foo(a, b, s);//会进行自动类型解析

	
	return 0;
}

