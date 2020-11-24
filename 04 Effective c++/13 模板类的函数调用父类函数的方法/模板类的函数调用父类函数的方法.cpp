#include<iostream>
using namespace std;

//本例讲解，在模板类中，如果想调用父类的函数应该怎么做
template<typename T>
class A
{
public:
	
	void prt() { cout << 10 << endl; }
private:
	
};

template<>
class A<double>
{
public:
private:

};
template<typename T>
class B :public A<T>
{
public:
	
	//01 案例:模板化的派生类函数中，不能直接调用父类的函数
	//void prtB() { prt(); } //不能被调用成功，因为父类A没有被具象化，因为模板类可以被特例化，没有办法保证父类一定具有需要的函数
	
	//02 案例:解决法一，通过this调用父类函数
	void portB() { this->prt(); }

	//03 案例：解决法二，通过using调用父类函数
	//通过using声明以后，也可以在类的函数中调用父类的函数
	/*using A<T>::prt;
	void portB() { prt(); }*/

	//04 案例:解决法三，通过基类声明来调用基类函数
	/*void portB()
	{
		A<T>::prt();
	}*/
private:
};
int main()
{
	//01 讲解
	//在案例01 中，直接调用父类中的prt会被拒绝编译，因为父类没有被具象化，类中并不一定能够保证有函数prt
	//就比如 A<double> 这个类，被特化了以后，里面没写prt函数。
	B<int> a;
	a.prt();

	B <double> b;
	//b.prt();
	

	//02 讲解
	//当增加了关键字this之后，就可以在类函数中调用父类的prt了
	a.portB();
	//b.portB();
	//但是由于B<double> 继承了A<double>，里面并没有prt函数可以使用，因此调用b.portB()会出问题的

	//03 讲解
	//使用using A<T>这种声明以后，也可以在派生类的函数中直接调用基类函数了
	//因为using会告诉编译器，让他假设基类中是有这样的函数的
	//但是当存在A<double>这样不含有prt的特例化的类以后，还是不能使用using，因为不是每一个类都含有prt函数了


	//04 讲解
	//也可以使用 A<T>::prt()这种方法调用基类的函数。但是这种方法是最不好的，因为使用这种方法以后
	//如果函数是virtual的，就不能动态绑定了。

	return 0;
}

