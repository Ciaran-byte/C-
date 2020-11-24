#include<iostream>
using namespace std;

//不能构造和析构函数中调用虚函数
//01 构造函数中，派生类创建之前，基类必须先进行创建，假设在基类的构造函数调用了虚函数，目前后面的派生类没有定义，
//虚函数指代不明确，没有办法进行允许，因此会编译失败
//02 在虚构函数中，基类释放之前，派生类会先释放，虚函数也会出现指代不明确的情况，无法正编译。
//基类
class Transaction
{
public:
	Transaction();
	virtual void Log() = 0;

};

Transaction::Transaction()
{
	Log();
}


//派生类
class BuyTransaction:public Transaction
{
public:
	
	virtual void Log(){}

};


int main()
{
	BuyTransaction b; //因为基类的构造函数有虚函数，指代不明确，无法运行
	return 0;
}