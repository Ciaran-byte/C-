#include<iostream>
using namespace std;
class myCls
{
public:
	friend ostream& operator<<(ostream& os, const myCls& cls);
	friend istream& operator>>(istream& is, myCls& cls);
	myCls() = default;
	myCls(int a):_a(a){}
	
private:
	int _a;
};
//01 ������������
ostream& operator<<(ostream& os, const myCls& cls)
{
	os << cls._a;
	return os;
}

//02 �������������
istream& operator>>(istream& is, myCls& cls)
{
	is >> cls._a;
	if(is) //���������Ҫ���������������⣬������������Ҫ
	{}
	else
	{ }
	return is;
}
int main()
{
	myCls a(5);
	cout << a << endl;

	myCls b;
	cin >> b;
	cout << b << endl;

	return 0;
}

