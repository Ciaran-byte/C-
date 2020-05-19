#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
using namespace placeholders;

bool check_size(const string& str, string::size_type sz)
{
	return str.size() > sz;
}

void print(int a, int b, int c, int d,int e)
{
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	cout << "e: " << e << endl;
}
void fun(ostream& os, int a)
{
	os << a << endl;
}
int main()
{
	//01 有时候使用谓词，需要提供一元谓词，比如find_if，但有时候我们很希望输入两个数字，比如输出大于5的数字，这个5
	//如果是个变量就好了。所以出现了参数绑定这种方法，能够通过占位的方法，固定一个值，从而把二元谓词变成一元谓词

	//01-1 bind函数的使用方法
	//bind函数能够实现参数绑定，语法 auto f = bind(funtion,arg_list);
	//bind函数是这样定义的，bind(函数名，占位符，固定值);占位符表示函数中的第几个位置要输入参数，固定值就是我们想固定位置的值
	auto check6 = bind(check_size, _1, 6);
	bool a = check6("hellssssssss0!");
	cout << a << endl;

	//01-2具体应用
	vector<string> s = { "1233333","22222","sadfadf","Qwe" };
	auto iter=find_if(s.begin(), s.end(), bind(check_size, _1, 6));
	cout << *iter << endl;

	//02 bind函数的参数

	//如果使用bind函数生成的函数对象，传入值的时候跟占位符的位置有关系，比如
	int a1 = 1;
	int b2 = 2;
	auto f = bind(print, a1, b2, _3, _2, _1);
	f(5, 6, 7);
	//输入的参数会按照占位符的顺序输入函数，比如5输入到占位符_3,对于print第三个参数;
	// 6输入到占位符_2，对应于print的第四个参数;7输入到占位符_1，对应于print的第五个参数

	//03 传入引用类型
	//通过函数ref可以实现传入引用类型

	auto ff = bind(fun, ref(cout), _1);
	ff(5);
	//比如fun函数第一个参数是一个ostream，只能通过引用传入数值，所以就使用ref函数，将cout作为引用传入
	

	//04 向后兼容

	//bind1st和bind2nd



	return 0;

}

