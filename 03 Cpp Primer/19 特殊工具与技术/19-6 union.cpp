#include<iostream>
using namespace std;
union token
{
	char a;
	int b;
	double c;
};

union mm
{
	double c;
	int a[2];
};
int main()
{
	mm n;

	cout << &n.a << endl;
	cout << &n.c << endl;

	return 0;
}


