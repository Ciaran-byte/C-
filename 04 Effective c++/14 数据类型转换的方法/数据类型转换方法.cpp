#include<iostream>
using namespace std;

// 类型转换
//01 显式类型转换
// static_cast//不能用于两个不相关类型的转换
//const_cast 消除const特性的转换
//dynamic_cast 如果转换的类型合适，会返回空指针，static_cast如果类型不合适也会转
//reinterpret_cast //两个不相关类型也能转，不安全。跟强制类型转换效果是一样的

//02 隐式类型转换

// int a = 5; double m = 1*1.0/2;
//隐式类型转换能够进行数据类型的提升

//03 强制类型转换与自定义类型转换
// double b = 0.5; (int)b

//自定义类型转换 operator int(){return xx;}
class A
{
public:
	 operator int()
	{
		return 5;
	}
	 operator double()
	 {
		 return 5.2;
	 }
};
int main()
{
	
	
	A a;
	cout << (int)a << endl;
	cout << (double)a << endl;
	return 0;
}

