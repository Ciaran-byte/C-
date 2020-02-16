//多态的原理，使用和应用场景。

#include<iostream>
using namespace std;
class A            //类A和类B是一组测试代码，B继承了A，里面分别有一个实函数和一个虚函数
{ 
private :
	int i;
public:
		A() :i(10) {}
		void print(void)
		{
			cout << "this is A" << endl;
		}
		virtual void print_virtual(void)
		{
			cout << "this is A" << endl;
		}
		virtual ~A() {};
		 int test_a =1;
};

class B: public A
{
private:
	int i;
public:
	B() :i(10) {}
	void print(void)
	{
		cout << "this is B" << endl;
	}
	virtual void print_virtual(void)
	{
		cout << "this is B" << endl;
	}

	virtual ~B() {};
	int test_a = 2;
};


//另外一组类的定义，定义的图形，图形包含椭圆，椭圆包含圆。下面三个类就是这种关系

class xypoint
{
public:
	int x;
	int y;
	xypoint() :x(0), y(0) {};
};
class shape
{
private:
		
		xypoint center;
public:
	shape(int a, int b)
	{
		center.x = a;
		center.y = b;

	}
	virtual void draw()
	{
		cout << "x=" << center.x << " " << "y=" << " " << center.y<<endl;

	}
	virtual ~shape(){}
};
class ellipse:public shape
{
private:

	int max_radius;
	int min_radius;
	
public:
	ellipse(int a, int b,int max,int min):shape(a,b),max_radius(max),min_radius(min)
	{
		

	}
	virtual void draw()
	{
		shape::draw();
		cout << "max=" << max_radius << " " << "min" << min_radius<<endl;


	}
	virtual ~ellipse() {}
};

class circle:public ellipse
{
private:

	int radius;

public:
	circle(int a,int b,int radius):ellipse(a,b,radius,radius),radius(radius)
	{


	}
	virtual void draw()
	{
		shape::draw();
		cout << "raduius=" << " " << radius<<endl;


	}
	virtual ~circle() {}
};

//定义了绘图函数
void draw(shape* sp)
{
	sp->draw();
}

int main()
{
	//测试代码1：
	//见注解1，这里回顾一下向上造型的写法，说明把子类当做父类使用后，输出的函数为父类的函数。
	A* m;
	A a;
	B b;
	m = &b;
	m->print(); 
	
	//测试代码2
	cout << sizeof(a)<<endl; //见注解3，通常来说，只有一个int的类应该占4个字节，而具有虚函数的类里面，却占了8个位，这就说明，实例a里面储存结构多了一些东西。
	                          //如果运行程序测试，我们发现没有virtual，只有一个int的类占4个字节，而有virtual函数的类占了16个字节

	//测试代码3
	A n;                 //见注解3：这部分用来测试带有虚函数的类里面数据结构是怎么样的，我们发现在储存的数据10之前，内存里有一些其他数据
	int* p = (int*)&n;
	cout << *p<<endl;
	cout << *(p+=2)<<endl;

	//测试代码4 多态的使用：实际上就是向上构型+动态引用。使得我们在向上造型中调用子类的同名函数,从而实现了函数功能的扩展和多样性。
	A* polyA;
	B polyB;
	polyA = &polyB;
	polyA->print_virtual();

	//测试代码5 利用多态扩展函数的多样性,我们定义了形状类shape，shape有一个函数draw，我们从shape的draw函数扩展出来了ellipse和circle的draw函数，这就是多态的应用
	shape* sp;
	ellipse ep(0,0,7,5);
	circle cir(0,0,5);
	sp = &ep;
	sp->draw();
	sp = &cir;
	sp->draw();

	//测试代码6：代码5可以写成更简洁的样子，我们定义了draw函数，需要shape*的指针,在函数内部完成向上构型的功能
	cout << endl;
	ellipse ep2(0, 0, 7, 5);
	circle cir2(0, 0, 5);
	draw(&ep2);
	draw(&cir2);
	
	

   

	return 0;
}


//      多态两大特性：（1）向上构造（2）动态绑定
//      注解1：我们在父类和子类关系中，提到了这样一件事情，当父类和子类具有同名函数的时候，子类会忽略父类的函数，因为父类和子类的函数不相关。而在向上造型中，我们
//提到了类似的事情，当子类被用作父类的时候，子类的函数也会失效，调用的函数会是父类的。这个问题的原理与函数的动态绑定和静态绑定有关。例子看测试代码1


//      注解2： 所谓函数的静态绑定，就是指当我们对一个类初始化实例的时候，这个实例能够使用的函数就是确定的了，比如我们创建父类A的时候，里面有一个函数print,
//当我们初始化A的实例a的时候，a里面print函数就对应着A类的print，这个绑定关系是不可修改的，因此a不能再接受b中的print的定义，所以，即使是把b的指针交给了a
//，a既不能调用b的变量和非同名函数，因为a没有这些变量的结构；a也不能调用b的同名函数，因为这个函数具体要使用哪个，已经在实例初始化的时候被确定了，也就是说，
//函数的绑定发生在编译的时候。


//      注解3：既然有函数的静态绑定，必然就有函数的动态绑定。这里，我们首先引入虚函数virtual的概念。虚函数意思就是，这个函数具体会调用哪个，不是在实例定义的时候决定
//而是在函数运行的时候决定。具体实现原理是，当我们定义了一个类A的时候，类A含有一个虚函数print_virtual，只要这个类含有虚函数的定义，在类A的储存空间的最前面，就会出现
//类型为vptr的函数表指针。也就是说，现在的类A的数据结构为：
//      A:    |Vptr| int i|  就像这个样子，vptr是一个二重的函数表指针。每个类都有一套相同的函数表，这个vptr里面包含的内容就是类中具有的所有虚函数,比如A具有两个虚函数，指向的虚函数表为
//      vptr: |~A()|print_virtual()|  ，这个表就是虚函数表，虚函数表仍然是一个指针，这个指针会指向具体保存函数的内存地址。
//所以，虚函数的调用原理为，我们定义了一个类A，类A里面有一个vptr指针，指向虚函数表vtable，当我们调用函数的时候，vptr指针会找到函数表里面的这个函数名，再有函数名
//去继续寻找储存这个函数定义的地址。这就是一种动态的调用。在类实例创建的时候，只是给函数添加了一个指针的指向路径，并不是完全固定的，如果后面我们通过修改虚函数表的指针
//我们完全可以让这个实例去调用别人的函数表中的函数。从这个角度来看，只要我们在父类和子类之间传递参数的时候，如果我们能够同时更改虚函数表的位置指向，我们就能够让父类去调用子类的同名函数了
//虚函数以及动态调用的原理和结构看测试代码2和3



//      注解4：现在，我们知道了，虚函数就是通过动态绑定的方法被定义的函数。他具有实例创建时不确定具体调用哪个函数的特性，只有在运行时，系统才会去判断调用哪个表中的函数。
//由此，我们可以引出多态的概念。多态实际上就是，在向上造型中，将子类当成父类使用时，可以通过动态绑定的方法，调用子类的同名函数，使得父类和子类的同名函数之间发生联系
//，而不是静态绑定，二者同名函数毫无关联的情况。通过测试代码5和6我们看出，多态的方法能够扩展父类函数的功能。


//       注解5：为什么需要一个虚的构造函数。我们看到，上面用到了虚函数的程序中，全都有虚的析构函数，为什么需要虚的析构函数呢？以程序5和6为例说明。我们定义了一个
//shape类型的指针，并且用他来接受类型circle和ellipse类型的类，而且shape的指针能够通过动态调用的方法，去获取circle和ellipse类里面的函数。这样就有一个问题，如果
//shape里面的析构函数是静态调用，当shape指针要被释放的时候，必然会去调用自身的析构函数，只会释放自己定义的资源，但是shape已经能够调用circle和ellipse里面自己没有的
//函数资源了，如果我们还用shape的析构函数，必然会出现shape不能释放自身没有的资源的问题，这个时候，更应该去调用circle和ellipse的析构函数，以求把shape不具有的资源也
//全部释放的功能。


