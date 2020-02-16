#include<iostream>
using namespace std;
class A
{	
public:
	int i;
	A(int ii):i(ii){}
	//（3）重构==和！=
	bool operator==(const A& a)
	{
		return a.i == this->i;
	}
	bool operator!=(const A& a)
	{
		return !(*this == a);
	}
	//（4）重构++a和a++
	//a++和++a的区别在于，返回值是++之前的数还是++之后的数字,a++运算符后面缺个孔，++a运算符后面有a，没有空缺。所以a++重载需要加一个int，与++a区别开
	//++a
	const A& operator++()
	{
		//++a返回的是修改之后的数字，可以直接返回引用，但是因为返回的是引用，可以通过返回值做左值的手段修改变量a，为了禁止返回值左左值的方法修改变量，做成const的

		this->i++;
		return *this;

	}
	//括号里的int是用来与前面的函数区分开的
	//a++
	const A operator++(int)
	{
		//a++如果返回的话，会返回修改之前的数字，所以直接返回引用是没有效果的，所以要返回一个重新定义的A
		A b=*this;//调用默认的拷贝构造函数，不过最好自己定义拷贝构造函数，防止出现内存冲突
		++(*this);
		return b;


	}
};

//（1）加减乘除等普通运算符的函数原型:输入变量不需要变，输出变量仅仅需要值
int operator+(const A& a, const A& b)
{
	return a.i + b.i;
}

//（2） ><等逻辑运算符:从这里我们可以看出，下面的四个函数其实只要<访问了具体类的变量，其他函数都是调用的小于号的重构，这样的好处在于，如果后面需要修改函数，就修改小于号的一个函数即可
//非常方法。同样道理==和！=也可以用同样方法定义 ,他们定义在了类A中，因此只需要一个变量，另外一个变量是this
bool operator<(const A& a, const A& b)
{
	return a.i < b.i;
}
bool operator>(const A& a, const A& b)
{
	return a < b;
}
bool operator<=(const A& a, const A& b)
{
	return !(b < a);
}

bool operator>=(const A& a, const A& b)
{
	return !(a < b);
}





int main()
{
	A a1(10),a2(10);
	A b = a1++;
	A c = ++a2;
	cout << b.i << " " << c.i << endl;
	
	


	return 0;
}



//    注解1：在20中，我们知道了运算符重载函数的存在意义、分类和使用方法。这里我们先讨论一下运算符重载的输入和返回类型应该是什么样子的。
//（1）对于输入变量，我们要考虑的一个问题就是输入变量在函数体内部是不是应该被修改的，比如单目运算符++，会修改自身变量，所以传入参数不能是const的应该是 T&
//而对于加减等，我们不需要修改传入变量的值，就使用const T&
//（2）对于输出变量而言，我们要考虑的是，返回值允不允许做左值，如果返回类型为 T&这种，是可以做左值的，如果不允许做左值，防止函数出口处通过引用修改原来变量
//返回值就应该做成const的

