#include<iostream>
#include<type_traits>
using namespace std;

template<typename It>
auto fun(It beg, It end)-> typename remove_reference<decltype(*beg)>::type  
//type是类型名，不要忘了在模板类前面加上typename，否则会解析为变量而不是变量类型

{
	return *beg;
}
int main()
{

	//利用decltype解析模板类迭代器的类型，使用remove_reference脱去引用特性，获得值类型
	//最终完成了解析迭代器类型并且返回了值类型



	return 0;
}


