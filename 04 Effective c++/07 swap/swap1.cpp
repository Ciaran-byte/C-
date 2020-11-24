#include<iostream>
#include<algorithm>
using namespace std;

//Widget类发生交互的时候，并不需要重新构建一个对象，只要能够交互指针区域就行了
//构建方式是，我们在swap中，把widget的交换进行特化，但是我们并不希望这个swap是友元
//因此，我们在widget类中写了一个内部的swap，外部的swap调用swap。
//不但实现了只交互指针区域，并且实现了不加入多余的友元，不增加类的复杂性。同时与STL具有兼容性



class WidgetImpl
{
public:
	WidgetImpl(int a,int b):a(a),b(b){}
	~WidgetImpl(){}
	int getA() { return a; }
	int getB() { return b; }
private:
	int a;
	int b;
};

class Widget
{
public:
	Widget(WidgetImpl* pImpl):pImpl(pImpl){}
	void swap(Widget& other)
	{
		using std::swap;
		swap(pImpl, other.pImpl);
	}
	int outA() { return pImpl->getA(); }
	int outB() { return pImpl->getB(); }
private:
	WidgetImpl* pImpl;
};

namespace std
{
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}

int main()
{
	WidgetImpl a(2, 2);
	WidgetImpl b(3, 3);
	Widget A(&a);
	Widget B(&b);
	cout<<A.outA() << endl;
	cout << B.outA() << endl;
	cout << endl;
	swap(A, B);

	cout << A.outA() << endl;
	cout << B.outA() << endl;


	return 0;
}

