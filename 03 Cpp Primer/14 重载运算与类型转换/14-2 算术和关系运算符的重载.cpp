#include<iostream>
using namespace std;
class mycls
{
public:
	friend int operator+(const mycls&,const mycls&);
	friend bool operator==(const mycls&, const mycls&);
	friend bool operator!=(const mycls&, const mycls&);
private:
	int a;
};

//算术运算符
int operator+(const mycls& m, const mycls& n)
{
	return m + n;
}

//相等运算符
bool operator==(const mycls& m, const mycls& n)
{
	return m.a == n.a;
}
bool operator!=(const mycls& m, const mycls& n)
{
	return !(m == n);
}

//关系运算符

int main()
{

	return 0;
}

