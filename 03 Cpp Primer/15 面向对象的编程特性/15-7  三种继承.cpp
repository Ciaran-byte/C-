#include<iostream>
using namespace std;
class A
{
public:
	int a = 1;
protected:
	int b = 2;
private:
	int c = 3;

};
//01 public继承
class B1 :public A
{
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //不可访问
	}
};
class B2 :public B1
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //不可访问
	}
};

//02 protected继承
class C1 : protected A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //不可访问
	}
};
class C2 :public C1
{
public:
	void f()
	{
		//C1中的a和b是protected的，c是private的
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //不可访问
	}
};

//03 private继承
class D1 :private A
{
public:
	void f()
	{
		cout << a << endl;
		cout << b << endl;
		//cout << c << endl; //不可访问
	}
};

class D2 :public D1
{
public:
	void f()
	{
		//全部不可访问，D1中的a，b，c都是private的
		//cout << a << endl;
		//cout << b << endl;
		//cout << c << endl; //不可访问
	}
};
class E :private A
{
	
public:
	using A::a;
private:
	
};
int main()
{
	//01 派生类可以从基类以三种方式进行继承，分别是public，private和protected
	//public 继承
	//public继承意味着，B1类中继承的A类对象，保持原始访问级别
	//等价于 a，b，c仍然分别为public，protected和privated
	
	//01-1 B1的用户的访问权限
	A a;
	cout << a.a << endl;
	//cout << a.b << endl;
	//cout << a.c << endl;
	//用户不能访问私有和受保护的对象
	B1 b;
	cout << b.a << endl;
	// b继承的a，b，c都是一样的访问权限，不能调用b.b和b.c

	//01-2 B1的派生类B2的访问权限
	B2 bb;
	bb.f();// B2可以访问B1的a，b，因为是public和protected，不能访问c


	//02 protected 继承
	//protected继承相当于高于protected级别的public对象权限变为protected
	//也就是继承了A的a，b，c到了C1中变成了protected,protected和private
	C1 c;
	//因为到了C1中public的a变成了protected，因此c1创建的用户不能访问，但是C1的派生类C2可以，因为是protected的
	//cout << c.a << endl;
	//cout<<c.b<<endl;
	//cout<<c.c<<endl;
	c.f();

	//03 private继承
	//相当于D1中的a，b，c都被转换成了private的
	D1 d;
	//什么变量也不能使用,访问级别都是private

	//04 去掉个别成员
	//想E以private的形式继承A，但是希望变量a还是public的
	E e;
	cout << e.a << endl; //要在public里面用using进行声明
	return 0;
}

