#include<iostream>

using namespace std;
class SmallInt
{
public:
	SmallInt(int a):_a(a){}
	operator int()const { return _a; } //类型转换运算符
private:
	int _a;
};
int main()
{
	SmallInt f(5);
	int a = f;
	cout << a << endl;
	

	return 0;
}

