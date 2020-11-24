#include<iostream>
#include<algorithm>
using namespace std;


template <typename T>
class WidgetImpl
{
public:
	WidgetImpl(T a, T b) :a(a), b(b) {}
	~WidgetImpl() {}
	T getA() { return a; }
	T getB() { return b; }
private:
	T a;
	T b;
};


template <typename T>
class Widget
{
public:
	Widget(WidgetImpl<T>* pImpl) :pImpl(pImpl) {}
	
	int outA() { return pImpl->getA(); }
	int outB() { return pImpl->getB(); }
	void swap(Widget<T>& other)
	{
		using std::swap;
		swap(pImpl, other.pImpl);
	}
private:
	WidgetImpl<T>* pImpl;
};

namespace std
{
	template <typename T>
	void swap(Widget<T>& lhs, Widget<T>& rhs)
	{
		lhs.swap(rhs);
	}
}

int main()
{
	WidgetImpl<int> a(2, 2);
	WidgetImpl<int> b(3, 3);
	Widget<int> A(&a);
	Widget<int> B(&b);
	cout << A.outA() << endl;
	cout << B.outA() << endl;
	cout << endl;
	
	swap(A, B);
	cout << A.outA() << endl;
	cout << B.outA() << endl;
	cout << endl;

	return 0;
}

