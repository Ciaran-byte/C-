#include<iostream>
using namespace std;

//01 initializer_list 的方法解决函数中需要传入不同数量的参数
void f(initializer_list<string> str)
{
	auto it = str.begin();
	for (;it != str.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main()
{
	//01 使用initialize_list 形参传递变量，可以实现函数中能够传入不同数量的参数
	//注意传递变量的时候一定要加花括号，不然没有办法作为初始化值传递给函数f，同时，可以在参数列表中增加initializer_list
	//以外的参数
	f({ "hell0","hi","how are you" });
	

	return 0;
}