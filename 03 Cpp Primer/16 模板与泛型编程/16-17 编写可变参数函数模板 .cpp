#include<iostream>
using namespace std;
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template<typename T,typename ...Args>
ostream& print(ostream& os, const T& t, const Args&...rest)
{
	os << t << ",";
	return print(os, rest...);
}
int main()
{
	int a = 1;
	int b = 2;
	double c = 5;
	string e = "12";
	print(cout, a, b, c, e);

	return 0;
}

