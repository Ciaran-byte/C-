#include<iostream>
using namespace std;



//01这个类来介绍一下对成员函数使用const到底是做什么
class myclass
{
public:
	myclass(int a):_a(a){}
	void display(int a) const //表示
	{
		//_a++; 这句话会报错，因为display函数修改了自己类的成员对象
		cout << _a << endl;
	}
private:
	int _a;
};

//02 接来下来介绍一下，如果不直接在函数内修改成员变量，返回一个成员变量的指针的函数能否被const
//假设有一个类型A，里面有一个成员变量_val
class TestA
{
public:
	TestA(int val):_val(val){}
	int _val;
};
//假设有一个类型B，里面有一个A类型的成员变量
class TestB
{
public:
	TestB(TestA valA):_valA(valA){}

	//下面这个函数如果使用const关键词会报错，因为返回值是个引用，虽然函数不能直接修改成员变量，但是可以通过
	//它传递出去的东西修改成员变量，也是非法的
	/*TestA& val() const
	{
		return _valA;
	}*/

	TestA& val() 
	{
		return _valA;
	}

	void display()
	{
		cout << _valA._val << endl;
	}
private:
	TestA _valA;
};

//03 类成员函数const与否可以当做是一种重载条件
class TestC
{
public:
	TestC(TestA valA) :_valA(valA) {}

	//下面这样写的两组val函数可以当做重载使用
	const TestA& val() const
	{
		return _valA;
	}

	TestA& val()
	{
		return _valA;
	}

	void display()
	{
		cout << _valA._val << endl;
	}
private:
	TestA _valA;
};

int main()
{

	//01 初始化
	//新建一个TestA类型的变量ta
	TestA ta(5);

	//用ta来初始化TestB类型的变量tb
	TestB tb(ta);
	//查看修改前的结结果
	tb.display();

	//02 修改
	//TestA类型的引用绑定tb的成员变量
	TestA &changeTa = tb.val();

	//使用changeTa修改tb的成员变量
	changeTa._val = 10;

	//查看修改后的结结果
	tb.display();
	
	//03 const可以作为重载条件
	TestC tc(ta);
	tc.display();
	
	//重载
	TestA& ta2=tc.val();
	const TestA& ta3 = tc.val();
	return 0;
}


