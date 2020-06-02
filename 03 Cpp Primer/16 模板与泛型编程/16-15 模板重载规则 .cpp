#include<iostream>
using namespace std;
template<typename T>
void debug_rep(const T& p)
{
	cout << "const T&" << endl;
}

template<typename T>
void debug_rep(T* p)
{
	cout << "T*" << endl;
}
void debug_rep(const string&)
{
	cout << "string&" << endl;
}
int main()
{
	//01 只能调用引用版本，字符串指针不能直接传递
	string s = "12";
	debug_rep(s);
	//02 两个版本都可，但是T*是完全匹配版本，
	int a = 1;
	int* p = &a;
	debug_rep(p);

	//03 两个版本都可以，而且都是完全匹配，但是T*适用面更窄，因此更加特化，会调用更特化的版本
	const int* q = &a;
	debug_rep(q);

	//04 非模板和模板都可以的时候，使用非模板版本，因为更加特化
	string ss = "123";
	const string& ps = s;
	debug_rep(ps);



	return 0;
}

