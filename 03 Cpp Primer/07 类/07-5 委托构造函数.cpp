#include<iostream>
using namespace std;


//01 委托构造函数的定义方法
//所谓委托构造函数，就是通过一个类中的其他的构造函数来实现自己的构造

class myClass
{
public:
	//非委托构造函数
	myClass(int a, int b, int c):_a(a),_b(b),_c(c){}


	//这就是委托构造函数，通过调用其他的构造函数来完成自己的构造
	myClass() :myClass(0, 0, 0){} 
	myClass(int a):myClass(a,0,0){} 

private:
	int _a;
	int _b;
	int _c;
};

//02 委托构造函数的执行顺序
//有时候构造函数中可能会出现其他语句，那么在这种一个调用另外一个构造函数的结构中，其他语句的执行顺序又是怎么样的呢？
//我们可以来实验一下
class testClass
{
public:
	testClass(int a,int b,int c):_a(a),_b(b),_c(c)
	{
		cout << "非委托构造函数" << endl;
	}


	//委托构造函数
testClass():testClass(0, 1, 2)
{
	cout << "委托构造函数1" << endl;
}

testClass(int a) :testClass(a, 1, 2)
{
	cout << "委托构造函数2" << endl;
}


//这个函数委托空值构造函数进行构造，而空值的构造函数又委托三值的构造函数来构造，因此具有两层的委托关系
testClass(istream& is) :testClass()
{
	cout << "委托构造函数3" << endl;
}
private:
	int _a;
	int _b;
	int _c;
};

int main()
{

	//01 委托构造函数的定义
	myClass cls;
	myClass cls2(1);
	myClass cls3(1, 2, 3);


	//02 委托构造函数的执行顺序
	testClass ts(cin);
	//从输出结果来看，先是三值的构造函数执行，然后是空值构造函数执行，最后才是自己执行
	//所以，委托构造函数的执行顺序，其他就是从顶到底的次序执行。先执行初始化受委托函数，然后执行受委托函数
	//函数体内容，然后再将控制权交给委托者。
	return 0;
}


