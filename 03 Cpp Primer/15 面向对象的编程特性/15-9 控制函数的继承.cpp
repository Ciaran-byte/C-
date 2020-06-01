#include<iostream>
using namespace std;
//控制函数必须调用基类的相关函数来实现
class A
{
public:
	A(int a) :a(a) { cout << "A的构造！" << endl; }
	A(const A& A1)
	{
		cout << "A的拷贝构造！" << endl;
		a = A1.a;
	}
	A(A&& A1)noexcept
	{
		cout << "A的移动构造！" << endl;
		a = A1.a;
	}
	A& operator=(const A& A1)
	{
		cout << "A的拷贝赋值！" << endl;
		a = A1.a;
		return *this;
	}
	virtual ~A() { cout << "A的析构" << endl; }
private:
	int a;
};

class B:public A
{
public:
	B(int a, int b) :A(a), b(b) { cout << "B的构造" << endl; }
	
	B(const B& B1) :A(B1)
	{
		cout << "B拷贝构造！" << endl;
		b = B1.b;
	}
	B(B&& B1)noexcept :A(move(B1))
	{
		cout << "B移动构造" << endl;
		b = B1.b;
		
	}
	B& operator=(const B& rhs)
	{
		cout << "B拷贝赋值" << endl;
		A::operator=(rhs);
		b = rhs.b;
		return *this;
	}
	virtual ~B() { cout << "B的析构" << endl; }

private:
	int b;
};
int main()
{
	B b(1, 2);
	B c = b;
	B d(b);
	d = c;

	

	return 0;
}

