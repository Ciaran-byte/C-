#include<iostream>
using namespace std;

//01 技巧一，通过数据类型，限制输入的内容，防止用户输入错误

struct  Month
{
	explicit Month(int m) :val(m) {}
	int val;
};

struct Day
{
	explicit Day(int d) :val(d) {}
	int val;
};

struct Year
{
	explicit Year(int y) :val(y) {}
	int val;
};

class Date
{
public:
	//Date(int month, int day, int year); //这样设计非常的不好，因为用户随时可能输入错误

	Date(const Month& m, const Day& d, const Year& y):month(m.val),day(d.val),year(y.val){}
	//这样设计就比较好，因为每个类都是explicit的构造函数，必须进行显示的定义，不容易出问题。
	
private:
	int month;
	int day;
	int year;

private:
};


//02 技巧二，通过限制数据值，进一步强化数据类型
class MONTH
{
public:
	static MONTH Jan() { return MONTH(1); }
	static MONTH Feb() { return MONTH(2); }
	int val;

private:
	explicit MONTH(int m) :val(m) {} //防止该数据类型被用户创建
};

class DATE
{
public:
	
	//MONTH仅仅提供了static的接口
	DATE(const MONTH& m, const Day& d, const Year& y) :month(m.val), day(d.val), year(y.val) {}
	

private:
	int month;
	int day;
	int year;

private:
};
int main()
{
	//01 技巧一
	// Date d(2,24,1980); //不能正确被编译，因为不能发生隐式转换
	Date d(Month(2),Day(24),Year(1980));

	//技巧二
	DATE dd(MONTH::Jan(), Day(24), Year(1980));
	return 0;
}