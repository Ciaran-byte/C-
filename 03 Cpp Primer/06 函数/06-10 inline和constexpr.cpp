#include<iostream>
using namespace std;

//01 inline函数的使用
inline const string& shorter(const string& str1, const string& str2)
{
	return str1.size() > str2.size() ? str2 : str1;
}



//02 constexpr函数
constexpr int num(int i)
{
	return i;
}


int main()
{
	//01 inline函数
	//		（1）作用：inline函数能够在函数调用处进行展开，直接拷贝到原来函数的位置，因此与普通函数相比，省去了很多
	//内存调用过程，更加高效，是一种空间换取时间的方法。

	//		（2）特性：inline修饰符对编译器只是一种建议，编译器可以拒绝这个建议，不把他用作inline函数。
	//必须定义在头文件中，否则链接过程会出错。编译过程不会出错。

	//		（3）inline函数使用场景
	//多次调用、函数只要十几行、中间没有出现递归
			

	//02 constexpr函数
	//（1）作用： constexpr 函数是用于常量表达式的赋值。
	//(2)特性：具有隐藏的inline属性，必须定义在头文件中
	//（3）要求：返回值和参数列表必须是字面值
	//(4) 注意：参数列表是常量，返回值就是常量表达式；参数列表不是常量，返回值就不是常量表达式

	constexpr int i = num(2);//参数列表是字面值常量，所以返回值也是常量表达式
	int p = 5;
	//constexpr int q = num(p);  //p不是个常量表达式，所以返回值也不是个常量表达式

	const int m = 5;
	constexpr int n = num(m);//可以使用，因为输入是一个常量，输出就是一个常量表达式
	return 0;
}

