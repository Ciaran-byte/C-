#include<iostream>
#include<functional>
#include<map>
using namespace std;
int add(int a, int b) { return a + b; }
auto mod = [](int a, int b) {return a % b; };
class divide
{
public:
	int operator()(int denominator, int divisor)
	{
		return denominator / divisor;
	}
};
int main()
{
	//01 function类型的使用，是个模板类型，通过参数列表和返回值类型来储存相应的可调用对象
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = mod;
	function<int(int, int)> f3 = divide();

	cout << f1(1, 2) << endl;
	cout << f2(4, 2) << endl;
	cout << f3(4, 2) << endl;

	int(*p)(int, int);
	p = add;
	//02 使用map和function构造可调用对象的函数表
	map<string, function<int(int, int)>> binops =
	{
		{"+",add},
		{"-",minus<int>()},
		{"/",divide()},
		{"%",mod},
		{"+2edtion",p}
	};
	cout << endl;
	cout<<binops["+"](1, 2)<<endl;

	//03 当出现函数名相同的重载函数时，不能直接往函数表加入名称，应该取代为函数指针
		
	cout << binops["+2edtion"](3, 4) << endl;
	return 0;
}

