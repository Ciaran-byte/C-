#include<iostream>
using namespace std;

string s[4] = { "hello","hi","food","good" };

string(&func1(int i))[4]
{
	return s;
}

using str = string[4];

str& func2(int i)
{
	return s;
}

auto func3(int i)->string (&)[4]
{
	return s;
}

decltype(s)& func4(int i)
{
	return s;

}

int main()
{
	string (&n)[4] = func3(0);
	func3(0)[0] = "if";
	cout << s[0] << endl;



	return 0;
}

