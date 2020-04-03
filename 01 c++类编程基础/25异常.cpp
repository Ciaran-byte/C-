#include<iostream>
using namespace std;


class Error
{
public:
	string s = "xx错误";
};
class Error1 :public Error
{

};
class Error2 :public Error
{

};
class Construction //配合测试代码7
{
public:
	Construction()
	{
		//delete this;  //视频里面讲的为了防止出现new关键词造成内存垃圾，在抛出错误之前先把自身删除。但是实际上这句话不能运行，可能跟编译器有关系
		Error e;
		throw e;
		
	}
};
void f(void)//配合测试代码1
{
	
	throw 5;
}

void ff(void)//配合测试代码2
{
	Error e;
	throw e;
}

void out1(void)//配合测试代码3
{
	f();
	cout << "this is out1" << endl;
}
void out2(void)//配合测试代码3
{
	out1();
	cout << "this is out2" << endl;
}
void test4(void)//配合测试代码4
{
	try
	{
		f();
	}
	catch (int i)
	{
		throw;
	}
	
}
void test5(void)//配合测试代码5
{

		Error1 e1;
		throw e1;

}

int main()
{

	//测试代码1，异常的基本使用方法
	try
	{
		f();
	}
	catch (int i)
	{
		cout << i<<endl;
	}
	//测试代码2，异常抛出实例对象
	try
	{
		ff();
	}
	catch (Error e)
	{
		cout << e.s<<endl;
	}

	//测试代码3
	//可以看出，out1（）和out2（）后面的字符串输出函数都没有被输出
	cout << endl;
	try
	{
		out2();
	}
	catch (int i)
	{
		cout << i << endl;
	}

	//测试代码4:异常的传递的写法
	cout << endl;
	try
	{
		test4();
	}
	catch(int i)
	{
		cout << i << endl;
	}

	//测试代码5：异常的继承
	cout << endl;
		try
	{
		test5();
	}
	catch (Error e)
	{
		cout << e.s << endl;

	}
	catch (...)
	{
		cout << "error" << endl;
	}

	//测试代码6：异常的屏蔽
	cout << endl;
	try
	{
		test5();
	}
	/*catch (...)  //这句话写上会报错
	{
		cout << "..." << endl;
	}*/
	catch (Error e)
	{
		cout << "error" << endl;
	}
	catch (Error1 e)
	{
		cout << "error1" << endl;
	}

	//测试代码7：构造函数中写异常抛出的弊端,这样创建的对象，在构造函数中产生异常抛出，会跳出类的定义，析构函数不运行。而且也会跳出try，delete也不运行，造成内存浪费。
	try
	{
		Construction* cs = new Construction();
		delete cs;//这句话不会执行的，因此被new的内存空间无法回收，造成内存资源浪费
		

	}
	catch (Error e)
	{
		cout << e.s << endl;
	}


	return 0;
}







//   注解一：异常主要包括三个关键词 try,throw和catch，其中try和catch组成一组语句，用来捕获异常语句的。throw是抛出异常的语句。异常抛出和接受的变量
//即可以是对象，也可以是变量。一般来说抛出错误类型使用对象比较常见，因为可以携带多个数据内容
//   注解二：异常处理的过程是，当检测到某个语句抛出异常之后，系统会检测抛出异常所在的大括号，然后抛出异常语句之后的内容就都不会执行了。如果当前括号内没有catch
//来处理异常，那么就会跳出去，跳到调用他的地方，继续运行程序。
//   注解三：异常的抛出也可以由测试代码4所示，一个函数调用了一个语句，那个语句（f函数）抛出了异常，然后test4函数继续向外层抛出异常，因为这是属于抛出异常的传递
//函数里面throw不需继续再写东西，只要写一个throw即可。使用这种异常抛出传递的方法，很大程度上是因为在当前异常抛出的层面上，不能解决问题，必须往外传递，传递到
//其他层次来解决问题。

//  注解四: catch判断异常是哪种种类是通过下面三种方法实现的（1）通过系统定义的或者自己定义的异常（2）如果catch里面没有这种异常，会去查找他的父类在不在其中
//比如测试代码5中，test5函数抛出了error1错误，但是catch里面没有，catch里面有他的父类error，所以，仍然可以读取到这种错误，并且执行相关的异常处理代码
//(3)通过...的方法进行访问 就像这样：try{} catch(...)。...代表的是所有异常，可以类别switch case语句中最后那个default的功能。

// 注解五：注意，catch语句里面的异常不能有互相包含的，否则程序无法运行。当系统获取了异常之后，会按照我们书写的顺序与catch逐个匹配
//如果出现像catch（...)写在第一个；抛出Error1错误，但是catch语句里面既有Error1，又有他的父类Error。这两种情况就属于前面的catch类型与后面的catch类型有
//相互包含的关系，编译器是不能识别的。从测试代码6来看catch（。。。）放到最前面出现了异常捕获屏蔽的问题。Error1和Error同时出现在VS中没有出现问题，异常读取是
//读取的第一个出现的那个

//注解六：在构造函数中设置异常的抛出。在构造函数中设置异常的抛出是有危险的，因为一旦抛出这个异常，构造函数没有完全运行结束，
//这个对象不会被成功创建，而且析构函数不会被运行。如果构造函数中含有创建内存的new语句，会分配内存，但是没有办法回收，造成内存垃圾。
