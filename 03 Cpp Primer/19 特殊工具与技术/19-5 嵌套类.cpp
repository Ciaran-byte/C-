#include<iostream>
using namespace std;

class A
{
public:
	A(int i):i(i){}
	
	class B
	{
	public:
		B(int b):b(b){}
		int pp()
		{
			
			return b;
		}
		
	private:
		int b;
	};

	void f()
	{
		B b(1);
		cout << b.pp()<<endl;

	}
private:
	int i;
	
};

int main()
{
	A a(1);
	a.f();
	A::B b(5);
	cout<<b.pp()<<endl;

}