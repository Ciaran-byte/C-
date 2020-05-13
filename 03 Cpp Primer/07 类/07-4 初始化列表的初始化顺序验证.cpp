#include<iostream>
using namespace std;
class x
{
public:
	x(int val) :j(val), i(j)
	{

	}
	void print()
	{
		cout << 1 << endl;
		cout << i << endl;
		cout<<j << endl;
	}
private:
	int i; 
	int j;
};
int main()
{
	//初始化顺序按类中定义的顺序进行，也就是先对i赋予初始值，但是，j此时没有定义，所以i实际上没有东西
	x m(5);
	m.print();
	return 0;
}

