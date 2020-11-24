#include<iostream>
#include<algorithm>
using namespace std;

//Widget�෢��������ʱ�򣬲�����Ҫ���¹���һ������ֻҪ�ܹ�����ָ�����������
//������ʽ�ǣ�������swap�У���widget�Ľ��������ػ����������ǲ���ϣ�����swap����Ԫ
//��ˣ�������widget����д��һ���ڲ���swap���ⲿ��swap����swap��
//����ʵ����ֻ����ָ�����򣬲���ʵ���˲�����������Ԫ����������ĸ����ԡ�ͬʱ��STL���м�����



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

