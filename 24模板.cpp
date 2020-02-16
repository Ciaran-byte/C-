#include<iostream>
using namespace std;

template <class T>
void my_swap(T& t, T& m)
{
	T a = t;
	t = m;
	m = a;
}


template<class T>
class A
{
public:
	A(T ii):i(ii){}
	T f(T a)
	{
		return a;
	}
	 
private:
	T i;
};

template<class T>
class B : public A<int>
{
public:
	T i;
	B():A(10){}
};
int main()
{

	//（1）函数模板
	int i = 1, j = 2;
	double m = 1, n = 2;
	my_swap(m, n);
	my_swap(i, j);
	cout << "i= " << i << "j= " << j<<endl;
	cout << "m= " << m << "n= " << n << endl;

	//（2）类模板
	A<int> c(5);

    
	//(3)继承
	cout << endl;
	B<int> b;
	b.i = 10;
	cout << b.i<<endl;


	return 0;
}

//  注解1:模板有什么用：模板使用的情境在于，如果你要使用的多个类，只有变量类型不同，其他结构几乎相同，就可以使用模板来做这件事情，这么做的优点是管理方法
//如果需要修改类结构的话，就把模板修改一下就行。
//  注解2:模板分为函数模板和类模板。不论是函数模板还是类模板，都必须在前面声明 template <class T> 其中T是可以变的，其他两个是关键字。
//函数模板定义的时候，把T替换变量类型即可，使用时直接调用即可。
//类模板定义的时候，把T替换为变量类型，使用的时候要在后面加一个尖括号，说明取代变量的类型。
//  注解3：template<class T>这句话是声明而不是定义，只有运行到具体类创建实例或者函数调用的时候，才会替换上实际的变量类型。
//   注解4：template<class T, class P>里面可以写两种变量
//   注解5：如果想要继承模板类，必须先给那个类一个准确的变量。模板可以继承模板类，也可以继承非模板类