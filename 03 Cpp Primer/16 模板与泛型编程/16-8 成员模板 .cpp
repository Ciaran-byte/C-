#include<iostream>
#include<vector>
using namespace std;

class DebugDelete
{
public:
	DebugDelete(ostream&s = cerr):os(s){}
	template<typename T>
	void operator()(T* p)const
	{
		os << "deleting unique_ptr" << endl;
		delete p;
	}
private:
	ostream& os;
};


//02 模板类含有模板的成员函数
template<typename T>
class A
{
public:
	template<typename LT>
	void fun(T a, LT b);
	
private:
	T _a;
};

//成员模板在类外进行定义

//因为涉及到两个模板参数，都要写出来，类模板参数在前，函数的模板参数在后
template<typename T>
template<typename LT>
void A<T> ::fun(T a, LT b)
{
	cout << a << " " << b << endl;
}
int main()
{
	//01 普通类中含有模板
	double* p = new double;
	DebugDelete d;
	d(p);

	unique_ptr<int, DebugDelete> q(new int, DebugDelete());

	////02 模板类中含有模板函数
	A<int> a;
	a.fun<double>(1, 2.5);

	return 0;
}

