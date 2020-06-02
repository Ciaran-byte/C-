#include<iostream>
using namespace std;


//01 只能访问同类型模板类的友元
template<typename T>
class A
{
	friend bool operator==<T>(const A<T>&, const A<T>&);
public:
	A( T m) :_m(m){}
private:
	T _m;
};
template<typename T>
bool operator==(const A<T>& a1, const A<T>& a2)
{
	return a1._m == a2._m;
}

//02 声明特定类型为友元
template<typename T> class B1; //需要前向声明
template<typename T> class B2
{
	friend class B1<int>; //只有int类型的B1是B2的友元
};

//03 声明所以类型都有友元
template<typename T> class C1
{
	template<typename T> friend class C2;//不需要前向声明，所以C2的实例都可以访问c1
};

//04 非模板类定义为友元
template<typename T> class D1
{
	friend class D2; //不需要前向声明
};


int main()
{
	//01 只能访问同类型模板类的友元
	A<int> a(5);
	A<int> b(5);
	cout << operator==<int>(a, b) << endl;

	A<double> c(0.5);
	A<double> d(0.5);
	//cout << operator==<int>(c, d) << endl; //不能使用

	//02 对实例化的类型授予友元权限
	

	return 0;
}

