#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class A
{
public:
	int a;
	int b = 1;
	void f()
	{
		cout << 1 << endl;
	}
	int A::* ff()
	{
		return &A::b;
	}
};

class B
{
public:
	void B1()
	{
		cout << "B1" << endl;
	}
	void B2()
	{
		cout << "B2" << endl;
	}
	void B3()
	{
		cout << "B3" << endl;
	}
	enum element { b1, b2, b3 };

	void move(element a)
	{
		(this->*Menu[a])();
	}

	using Action =void (B::*)();
private:
	static Action Menu[];
	


};
B::Action B::Menu[] = { &B::B1,&B::B2,&B::B3 };
int main()
{
	
	//01 指向类成员的指针定义
	//指向类成员变量的指针
	int A::* p = &A::a;


	//指向类成员函数的指针
	void(A:: * q)() = &A::f;


	//02 指向类成员的指针的使用
	A a;
	int m = a.*p;

	(a.*q)();

	//03 返回数据成员指针的函数
	int A::* pp = a.ff();
	cout << a.*pp << endl;

	//04 函数指针表
	B b;
	b.move(B::b1);


	//05 成员函数作为可调用对象
	vector<string> str;
	
	string s = "123";
	str.push_back(s);
	str.push_back("");
	str.push_back("12344");

	//查找str中第一个空的字符串


	function<bool(const string&)> fp = &string::empty;
	find_if(str.begin(), str.end(), fp);


	
	
	return 0;
}

