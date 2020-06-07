#include<iostream>
using namespace std;
namespace my
{
	class myclass
	{
	public:
	private:
	};
}

namespace you
{
	class myclass
	{
	public:
	private:
		int i;
	};
}
namespace my
{
	void f()
	{
		cout << "f" << endl;
	}
}
int main()
{
	//01 每一个命名空间都是一个作用域，同名函数或者类可以位于不同命名空间内
	my::myclass mcls;
	you::myclass ycls;
	//02 命名空间可以不连续
	my::f();


	return 0;
}





