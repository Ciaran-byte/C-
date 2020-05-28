#include<iostream>
using namespace std;
class mycls
{
public:
	mycls() = default;
	mycls(int a):_a(a){}
	//前置版本，返回改变后本身，改变就是_a++，然后返回对象
	mycls& operator++()
	{
		_a++;
		return *this;
	}

	//后置办法返回++前的状态，因此预先保存*this的内容，返回改变前的内容

	mycls operator++(int)
	{
		mycls ret = *this;
		++* this;
		return ret;
	}

	int _a;
};
int main()
{
	mycls m1(6);
	mycls m2 = m1++;
	cout << m2._a << endl;
	cout << m1._a << endl;

	cout << endl;

	mycls ma(6);
	mycls mb = ++ma;
	cout << mb._a << endl;
	cout << ma._a << endl;

	
	return 0;
}

