#include<iostream>
using namespace std;

//01 const_cast与重载的一种典型用法
const string& shorter(const string& str1, const string& str2)
{
	return str1.size() > str2.size() ? str2 : str1;
}

string& shorter(string& str1, string& str2)
{
	//把非常量引用转换为常量引用，调用shorter
	auto& r = shorter(const_cast<const string&> (str1), const_cast<const string&>(str2));


	//把常量引用再变回非常量引用，进行返回
	return const_cast<string&>(r);

}

int main()
{
	//01 const_cast与函数重载
	//const_cast是c++中的一个类型转换函数，能够去掉底层const对象的const属性。
	//比如如果是一个指向常量的指针，但是指向对象本身不是常量，就可以利用const_cast去掉常量特性，
	//让指针能够修改对象。

	//但是，如果指向对象本身是常量，那么利用const_cast去掉常量特性之后，再利用引用或者指针修改原来常量.,
	//这个行为是未定义的,可能会出问题


	//const_cast本身只能去掉底层const特性，而不能对变量类型进行转换

	//01-1 不正确的使用案例，强行通过const_cast去掉const特性，再用引用修改const对象，可能会有问题
	const string str = "123";
	const  string& s = str;
	string& q = const_cast<string&>(s);
	q[0] = '3';
	cout << str << endl;


	//01-2 const_cast与重载行为
	//const_cast可以用于函数重载，比如有一组函数，一个函数需要接受const的引用，返回const的引用
	//而另外一个函数接受非const的引用，返回非const的引用

	//注意，虽然顶层const不能作为重载的条件，但是底层const是可以的

	//比如有这样的一个字符串长短比较函数





	return 0;
}


