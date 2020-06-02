#include<iostream>
using namespace std;

//01 普通的包扩展
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template<typename T, typename ...Args>
ostream& print(ostream& os, const T& t, const Args&...rest) //不同模板参数扩展定义变量
{
	os << t << ",";
	return print(os, rest...); //把变量集合扩展等价于 print(os,rest1,rest2...)等等
}

//02 高级扩展
//return print(os,func(rest)...); 等价于 print(os,func(rest1),func(rest2))

//return print(os,func(rest...)); 等价于print(os,func(rest1,rest2,rest3....));

int main()
{

	return 0;
}

