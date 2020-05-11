#include<iostream>
using namespace std;

//01 函数指针的定义方法
bool (*p) (const string& str1, const string& str2); //必须要用括号，不然就成了返回值为bool*的函数
bool compare(const string& str1, const string& str2)
{
	return str1.size() > str2.size() ? true : false;
}

//04 重载函数的函数指针
void pp(int) { cout << "int" << endl; }
void pp(double) { cout << "double" << endl; }

//05 函数指针作为函数的参数列表
//这个地方可以不写*，会隐式转换为指针
void func(bool(*p)(const string& str1, const string& str2))
{
	cout<<p("hell0", "hi")<<endl;

}

//06 使用别名简化函数的参数列表
typedef bool (FUNC1)(const string& str1, const string& str2);  //定义一个函数类型的别名
typedef decltype(compare) FUNC2;  //定义一个函数类型的别名
void funcA(FUNC1* q)//
{
	cout << q("hell0", "hi") << endl;

}


void funcB(FUNC2 *q)
{
	cout << q("hell0", "hi") << endl;

}
//07 返回函数指针
using FUN3 = bool (*)(const string & str1, const string & str2);//FUNC3是函数指针类型的变量
using FUN4 = bool (const string & str1, const string & str2);//FUNC4是函数类型的变量
FUN3 funC(FUN3 q)
{
	return q;
}
FUN4* funD(FUN4* q)
{
	return q;
}

//08 使用尾置返回类型
auto funE(int)->bool (*)(const string& str1, const string& str2);
int main()
{
	//02 函数指针赋值
	//类型必须完全匹配，不存在类型转换
	p = compare;
	//p = &compare; //两种写法均可

	//03 函数指针的使用
	bool a=p("hell0", "h1");
	//bool b = (*p)("hell0", "h1"); //是否对函数指针使用解引用均可

	//04 重载函数的函数指针
	//必须与其中一种类型完全匹配
	void (*ptr)(int);
	ptr = pp;

	//05 函数指针作为参数列表
	func(compare);
	//可以把函数名直接作为实参传入，实际传递的是指针类型

	//06 使用别名简化函数指针名字
	//typedef bool (FUNC1)(const string& str1, const string& str2);  //定义一个函数类型的别名
	//typedef decltype(compare) FUNC2;  //定义一个函数类型的别名
	

	return  0;

}

