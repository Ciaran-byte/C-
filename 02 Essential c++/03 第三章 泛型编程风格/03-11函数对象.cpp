#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//01 函数对象
template <typename inputIterator>
class myOutput
{
public:
	void operator()(inputIterator first, inputIterator last)
	{
		for (; first != last; first++)
		{
			cout << (*first) << endl;
		}
	}



};

//02 一元谓词
template<typename num>
class multiple
{

public:
	int val;
	//因为需要指定要找谁的倍数，所以类中需要一个额外的变量
	
	//构造函数
	multiple(int val):val(val){}

	//函数对象
	bool operator()(num a)
	{
		return (a % val == 0);
	}
};

//03 transform
template<typename T>
class multiply
{
public:
	T operator()(T a, T b)
	{
		return a * b;
	}
};
int main()
{
	//01 什么是函数对象
	//函数对象实质就是运算符()的重载，在一个类中重载了函数调用符。
	//因为函数对象是在类中的，因此可以当做变量进行定义，也可以是一个匿名的函数。函数名传递的是地址
	//函数对象和函数是非常相似的，但是因为函数对象具有类的特性，里面可以有数据变量，能够保存一些信息
	//下面让我们来看一个简单的函数对象。打印vector的输出

	//01-1定义了类myOutput，在里面重载了()，因此定义了类的实例a之后，使用运算符()，就可以当函数使用
	//这就是函数对象
	vector<int> ivec = { 1,2,3,8,5,6 };
	myOutput<vector<int>::iterator> a;
	a(ivec.begin(), ivec.end());
	cout << endl;

	//01-2 也可以通过下面这种方法，匿名调用函数对象
	myOutput<vector<int>::iterator>()(ivec.begin(), ivec.end());
	cout << endl;

	//02 谓词-返回值为bool的函数对象，被称为谓词。
	//参数列表为一个变量时，叫做一元谓词，参数列表为两个变量时，叫做二元谓词，容器类很多函数都使用谓词作为参数传入
	//下面一个例子要介绍如果在一个数列中找到第一个4的倍数

	//02-1这个例子使用了含有构造函数的函数对象
	cout<<*(find_if(ivec.begin(), ivec.end(), multiple<int>(4)))<<endl;

	//02-2含有构造函数的函数对象的使用
	multiple<int> mul(4);//需要往构造函数里面加入一个数
	mul(8);//调用构造函数

	//02-3 匿名的
	multiple<int>(4)(8);//返回8是否为4的倍数

	//03 transform的使用
	vector<int> t1 = { 1,2,3,4 };
	vector<int> t2 = { 2,3,4,5 };
	vector<int> t3(4);
	transform(t1.begin(), t1.end(), t2.begin(),t3.begin(), multiply<int>());
	for (int i = 0; i < t3.size(); i++)
	{
		cout << t3[i] << endl;
	}
	return 0;
}