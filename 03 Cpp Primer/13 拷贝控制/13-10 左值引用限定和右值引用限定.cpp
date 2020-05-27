#include<iostream>
#include<memory>
using namespace std;

class FOO
{
public:
	int f1()&
	{
		cout << "左值对象使用" << endl;
		return 1;
	}
	int  f1()&&
	{
		cout << "右值对象使用" << endl;
		return 2;
	}
private:
};
int main()
{
	FOO i;
	i.f1();
	int a = FOO().f1();

	

	return 0;
}

