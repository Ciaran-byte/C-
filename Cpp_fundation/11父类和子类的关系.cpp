//程序功能描述：父类对象有析构函数时候的继承
#include<iostream>
using namespace std;

class A
{
private:
	int size;
	int i;
public:
	A(int ii);
	~A();
	void print_size(int a);
	void print(int i)
	{
		cout << i << endl;
	}
	void print()
	{
		cout << "A_print" << endl;
	}
};

A::A(int ii):i(ii),size(0)
{
	cout << "这是A构造函数contributor" << endl;
}


A::~A()
{
	cout << "这是A析构函数decontributor" << endl;
}

void A::print_size(int a)
{
	size = a;
	cout << "size = " << size << endl;
}

class B :public A
{
public:
	B():A(10) //注解1知识点：因为父类A产生的时候需要一个int类型的初始化变量，子类产生之前，必定是先引用父类的东西，父类A构造函数不满足要求，必定无法运行，因此需要进行父类的构造函数初始化
	{
		cout << "这是构造B函数contributor" << endl;
	}
	~B()
	{
		cout << "这是B析构函数decontributor" << endl;
	}
	void print()
	{
		cout << "B_print" << endl;
	}
};


int main()
{
	cout << "进入括号之前" << endl;
	{
    // 括号表示类的作用域，出了括号之后，类就没有了
		B b;  //注解2知识点：运行这个类的实例化，发现构造函数运行顺序先A后B，析构运行顺序先B后A
		b.print_size(10);  
		b.print();
		//b.print(1); //注解3知识点：这句话是无效的，表面上看B继承了A应该具有A中的两个print，但是由于B中具有同名函数，A中的所有同名print函数的定义都会被忽略，B不继承A的print

	}
	cout << "进入括号之后" << endl;
	return 0;
}
//注解1：在这个例子中，我们可以看到父类A是有构造函数的，如果子类B在产生实例对象的时候，没有填入A构造所需要的参数，程序是无法运行的，我们仍然可以使用初始化列表的方法
//去满足父类A的构造函数初始化
//注解2：整个父类和子类的定义过程为：先定义父类，把父类有的东西搬运到子类来，再产生子类特有的东西。析构的时候，先把子类自己的东西清理完，再清理父类的东西
//因此会有构造函数先A后B，析构函数先B后A的情况。
//注解3: 如果父类具有和子类同名的函数，父类的函数会被忽略，c++认为此时只有子类中的函数有效。就比如这个程序中，A有两个print，是一种重载，而B也有一个print
//在这种情况下，A和B之间的print是没有任何关系的，B也没有办法找到A的两个print