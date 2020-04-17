#include<iostream>
using namespace std;

//01 mutable使用场景，A类有一个成员函数能够修改A的成员变量
//01-1
//定义类A
class A
{
public:
	A(int val):_val(val),outTime(0){}
	void display(void)
	{
		cout << _val << endl;
		outTime++;
		cout << outTime << endl;
	}


private:
	int outTime;
	int _val;
};
//定义传入值为cosnt&的函数

void funA(const A& a)
{
	//a.display(); //会报错，因为display会修改其中的变量，记录输出的次数
}

//01-2
//定义类B
class B
{
public:
	B(int val) :_val(val), outTime(0) {}
	void display(void) const
	{
		cout << _val << endl;
		outTime++;
		cout << outTime << endl;
	}


private:
	mutable int outTime;
	int _val;
};
//定义传入值为cosnt&的函数

void funB(const B& b)
{
	b.display(); //如果把display改成const的，funB就能够调用display不报错了
	//同时，把display修改的参数变成mutable的，说明这个值的修改对类B不构成影响，是可以修改的
}
int main()
{
	


	return 0;
}

