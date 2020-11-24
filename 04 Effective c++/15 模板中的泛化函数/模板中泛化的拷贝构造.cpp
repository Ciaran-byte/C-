#include<iostream>
using namespace std;


template <typename T>
class smart_ptr1
{
public:
	explicit smart_ptr1(T* realPtr) :realPtr(realPtr) {}

	
private:
	T* realPtr;
};



template <typename T>
class smart_ptr
{
public:
	explicit smart_ptr(T* realPtr):realPtr(realPtr){}

	template<typename U>
	smart_ptr(const smart_ptr<U>& other) : realPtr(other.get()) { }

	 T* get() const { return realPtr; }
private:
	T* realPtr;
};



class A
{
public:
	virtual void ptr() { cout << "a" << endl; }
};

class B:public A
{
public:
	virtual void ptr() { cout << "b" << endl; }
};

int main()
{
	//01 对于泛型类来说，我们常常会通过向下造型的方法构建指针，以支持虚函数的调用
	//事实上，智能指针shared_ptr也是支持使用子类的指针指针来进行拷贝构造的，这是怎么实现的呢?
	shared_ptr<A> apA= make_shared<A>();
	shared_ptr<A> apB = make_shared<B>();
	apA->ptr();
	apB->ptr();
	
	//02 我们先实现一个最简单的智能指针类smart_ptr1
	A a;
	B b;
	A* pa = &a;
	B* pb = &b;
	smart_ptr1<A> sma(pa);
	smart_ptr1<B> smb(pb);

	//smart_ptr1<A> asmb(smb);
	//可以看到，如果直接使用B类型的智能指针给A类型进行拷贝构造，是报错的。
	//因为对于智能指针来说，各个对象之间是独立的，不存在继承不继承这个东西
	//但是如果我们为每一个类型都定义一种拷贝构造函数又是不现实的。
	//因为模板意味着有无穷的类型可以被具象化，我们不可能为无穷的智能指针类型定义自己的拷贝构造

	//03 来看看怎么做智能指针的拷贝构造
	//这个时候，我们引入泛化的构造函数这个概念
	//见smart_ptr类的拷贝构造函数，我们发现，拷贝构造函数也是给泛型类
	//有了泛型类以后，就可以实现任意两个智能指针的互相拷贝


	//template<typename U>
	//smart_ptr(const smart_ptr<U> & other);

	//等下，是不是还有些问题?我们不希望发生一些指针的类型转换，比如double指针变成int指针，怎么再
	//泛化的拷贝构造函数中做这个限定呢?

	//这个时候，我们构造了一个get函数返回数据指针，通过初始化列表的方法进行拷贝构造
	//在初始化列表中，只要支持隐式类型转换的时候，这个返回的拷贝构造函数才能通过编译

	int ia = 5;
	double db = 6.0;
	int* pia = &ia;
	double* pdb = &db;
	smart_ptr<int> smpia(pia);
	smart_ptr<double> smpdb(pdb);

	//smart_ptr<int> sm(smpdb); //double的指针转int不能被编译通过
	//smart_ptr<double> sm(smpdb); //int的指针转double也不能被编译通过

	A a1;
	B b1;
	smart_ptr<A> pa1(&a1);
	smart_ptr<B> pb1(&b1);
	smart_ptr<A> pa2(pb1); //向下造型能过编译
	//smart_ptr<B> pb2(pa1); //向上造型不能过编译

	

	//04 除了泛化的拷贝构造以外，也可以用同样的方法实现赋值函数
	//同时，写构造函数的时候，应该支持不同类型智能指针之间的转换
	//比如shared_ptr,weak_ptr,unique_ptr等
	//也应该通过泛化的构造函数进行声明

	return 0;
}

