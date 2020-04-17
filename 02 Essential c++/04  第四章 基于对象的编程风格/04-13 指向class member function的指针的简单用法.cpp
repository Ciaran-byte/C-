#include<iostream>
using namespace  std;

class myClass
{
public:
	myClass(void) {}
	//01 对指向类的成员函数的指针进行简化
	typedef void (myClass::* Ptr)(void);
	//02 定义两个与函数指针具有相同类型的函数
	void print1()
	{
		cout << "1" << endl;
	}
	void print2()
	{
		cout << "2" << endl;
	}
	//03 类内调用函数指针
	void print(int num)
	{
		if (num == 1)
		{
			 p = &myClass::print1;
		}
		else
		{
			p = &myClass::print2;
		}
		(*this.*p)();

	}
	Ptr p;
private:
	
};
//因为Ptr只在类中能被找到，使用时候需要有类区域符号，为了简便，为其定义别名

typedef myClass::Ptr Ptr;
int main()
{
	//类内调用函数指针举例
	myClass cs1;
	cs1.print(1);

	//05 类外引用函数指针
	myClass cs2;
	Ptr q=&myClass::print2;
	(cs2.*q)();
	//等价于 cs2.print2();

	//06 指向类的指针调用指向类的成员函数举例
	myClass* cs3=&cs2;
	Ptr m = &myClass::print1;
	(cs3->*m)();
	//等价于 cs3->print1();

}