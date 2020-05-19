#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//01 lambda的捕获
	//01 -1 值类型捕获
	//变量的值在lambda创建的时候被拷贝
	int sz = 42;
	auto f = [sz]() {return sz; };
	sz = 5;
	cout << f() << endl; //我们发现lambda捕获的sz是定义时候的sz，而不是后来的那个。
	//所以，lambda捕获的值类型的变量，是在捕获时候就以及把值给转交进去了

	//01 -2 引用类型捕获
	int sz2 = 42;
	auto f2 = [&sz2] {return sz2; };
	sz2 = 5;
	cout << f2() << endl;
	//捕获引用的lambda，sz2的值会跟随外界变化而变化
	

	//02 隐式捕获
	//可以让编译器自己猜测需要捕获哪些对象
	//02 -1 隐式值捕获
	int sz3 = 42;
	auto f3 = [=] {return sz3; };
	sz3 = 5;
	cout << f3() << endl;
	//02-2 隐式引用捕获
	int sz4 = 42;
	auto f4 = [&] {return sz4; };
	sz4 = 5;
	cout << f4() << endl;

	//02 -3 混合捕获
	vector<string> str = { "123","234","456" };
	char c = '\n';
	ostream& os = cout;
	for_each(str.begin(), str.end(), [](const string& str) {cout << str << endl; });//不写捕获的版本
	cout << endl;
	for_each(str.begin(), str.end(), [=, &os](const string& str) {os << str << c; });//第一种混合捕获


	cout << endl;
	for_each(str.begin(), str.end(), [&, c](const string& str) {os << str << c; });//第二种混合捕获

	//03 可变的lambad
	int v = 42;
	auto f5 = [v]()mutable {return ++v; };
	int v1=f5();
	int v2 = f5();
	int v3 = f5();
	cout << v1 << ends << v2 << ends<<v3<<ends << endl;
	



	return 0;
}

