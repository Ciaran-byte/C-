#include<iostream>
#include<vector>
using namespace std;

//01 返回值为void函数的return语句
void swap(int& a, int& b)
{
	if (a == b)
		return;
	int swap;
	swap = a;
	a = b;
	b = swap;
}
//02 引用在函数列表和返回值时候的举例
int add_one1(int a)
{
	a++;
	return a;
}
int add_one2(int &a)
{
	a++;
	return a;
}

int& add_one3(int& a)
{
	a++;
	return a;
}

//03 千万不能返回局部对象的引用
int& test()
{
	int a=10;
	return a;
}

//04 返回值为左值
char& get_val(string& str, size_t index)
{
	return str[index - 1];
}
//05 返回值是初始化列表
vector<string> ff(int a, int b)
{
	if (a == b)
		return { "1","2","3" };
	else
		return { "1","2" };

}
int main()
{
	//01 返回值为void函数的return 语句
	//对于返回值为void的函数来说，结尾默认隐藏了一个return;如果需要提前返回就把这句话写出来
	//比如交换函数
	int a = 10, b = 5;
	cout << "交换前" << "a= " << a << ",b= " << b << endl;
	swap(a, b);
	cout << "交换后" << "a= " << a << ",b= " << b << endl;

	//02 引用在函数列表和返回值时候的举例
	//假设有一个add_one的函数用于给变量+1，会定义多个变量

	//02-1 参数列表和返回值都不是引用类型
	cout << endl;
	int A1 = 0;
	int B1= 1;
	add_one1(A1);
	cout << "这个是A! "<<A1 << endl; //从输出结果看，a并没改变，说明函数内部仅仅发生了数值的复制

	//02-2 参数列表是引用类型，返回值不是引用类型
	cout << endl;
	int A2 = 0;
	int B2 = 1;
	B2=add_one2(A2);
	cout << "这个是A! " << A2 << endl;
	cout << "这个是B! " << B2 << endl;
	B2++;
	cout << "这个是A! " << A2 << endl;
	cout << "这个是B! " << B2 << endl;
	//从结果来看，函数中A2发生了+1，而B2++后对A2没有影响，说明返回值仅仅是数值的复制，而函数中是
	//把对象给传过去了

	//02-3 参数列表和返回值都是引用类型
	cout << endl;
	int A3 = 0;
	int& B3 = add_one3(A3);
	cout << "这个是A! " << A3 << endl;
	cout << "这个是B! " << B3 << endl;
	B3++;
	cout << "这个是A! " << A3 << endl;
	cout << "这个是B! " << B3 << endl;
	//从结果来看，函数中A3发生了+1，而B3++后A3也++，说明返回值和参数列表都发生对象的传递，而不是值传递。

	//03 千万不能返回局部对象的引用
	//int& Test = test();
	//返回的引用是个局部对象，会出错的

	//cout << Test << endl;
	//类似的，返回局部的指针也是肯定不可以的


	//04 返回左值,一般是通过返回值为引用的函数实现的
	string str = "helo";
	get_val(str, 2) = 'i'; //因为返回值是引用，所以函数可以做左值
	cout << str << endl;

	//05 返回值是初始化列表
	vector<string> s = ff(1, 2);

	return 0;
}

