#include<iostream>
using namespace std;
int main()
{
	//01 定义
	//限定作用域的枚举
	enum class color {red,yellow,blue};


	//不限定作用域的枚举
	enum ppers{red,yellow,blue};


	//02 使用
	//调用的时候必须加上作用域
	color eye = color::red;
	ppers pp = red;


	//03 取值
	int a = ppers::red; //非限定作用域的枚举可以自动转换成int
	//int m = color::red; //限定作用域类型的枚举不能自动转换为int

	



	return 0;
}


