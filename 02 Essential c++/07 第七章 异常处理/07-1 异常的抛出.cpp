#include<iostream>
#include<exception>
#include<sstream>
using namespace std;

//例一 抛出int 配合注解一
void f1(int num, int max = 50)
{
	if (num > max)
		throw 42;
	cout << "创建成功" << endl;
}
//例二 抛出string 配合注解一
void f2(int num, int max = 50)
{
	if (num > max)
		throw "输入越界";
	cout << "创建成功" << endl;
}

//例三 抛出class的两种写法 配合注解一
class error
{
public:
	error(int num,int max):_num(num),_max(max){}
	void what()
	{
		cout << _num << "超过了最大值" << _max << endl;
	}
private:
	int _num;
	int _max;
};
void f3(int num, int max = 50)
{
	if (num > max)
	{
		throw error(num, max);
	}
	cout << "创建成功" << endl;
}

void f4(int num, int max = 50)
{
	if (num > max)
	{
		error err(num, max);
		throw err;
	}
	cout << "创建成功" << endl;
}

//例四 配合注解二
class error1:public error
{
	error1(int num,int max):error(num,max){}
};
void f5(int num, int max = 50)
{
	if (num > max)
	{
		error err1(num, max);
		throw err1;
	}
	cout << "创建成功" << endl;

	
}

//例五 配合注解五，异常向上继续抛出
void level1()
{
	throw 1;
}
void level2()
{
	level1();

}

//例六 配合注解六，如何继承标准异常，来构建自己的异常
class exceptionError:public exception
{
public:
	exceptionError(int num,int max):_num(num),_max(max){}
	const char* what()
	{
		ostringstream ex_msg;
		static string msg;

		//技巧一 把混合数据类型的串变成字符串
		ex_msg << _num << "超过最大值" << _max << "!" << endl;
		msg = ex_msg.str();

		//技巧二 把字符串变成 const char *
		return msg.c_str();
	}
private:
	int _num;
	int _max;
};

void throwExceptionError(int num,int max=50)

{
	if (num > max)
	{
		throw exceptionError(num, max);
	}
	cout << "创建成功" << endl;
	
}
int main()
{
	// 配合注解一 
	//01 例程1
	cout << "抛出int" << endl;
	try
	{
		f1(100, 50);
	}
	catch (int len)
	{
		cout << len << endl;
		
	}
	cout << endl;
	//02 例程2
	cout << "抛出string" << endl;
	try
	{
		f2(100, 50);
	}
	catch (const char* str)
	{
		cout << str << endl;

	}
	cout << endl;

	//03 例程3-1
	cout << "抛出class1" << endl;
	try
	{
		f3(100, 50);
	}
	catch ( error& err)
	{
		err.what();

	}
	cout << endl;

	//03 例程3-2
	cout << "抛出class2" << endl;
	try
	{
		f4(100, 50);
	}
	catch (error & err)
	{
		err.what();

	}
	cout << endl;


	//配合注解二
	//01 从父类寻找异常类型
	cout << "从父类寻找异常类型" << endl;
	try
	{
		f5(100, 50);
	}
	catch (error & err)
	{
		err.what();

	}
	cout << endl;

	//配合注解三
	cout << "catch(...)全部抓住" << endl;
	try
	{
		f4(100, 50);
	}
	catch (...)
	{
		cout << "error!" << endl;

	}
	cout << endl;

	//配合注解四
	//01 catch不相互包含-异常屏蔽现象
	try
	{
		f4(100, 50);
	}
	
	//这个写在前面是错误的
	/*catch (...)
	{
		cout << "error!" << endl;

	}*/
	catch (error & err)
	{
		err.what();

	}
	cout << endl;

	//配合注解五
	cout << "沿着调用链上传异常" << endl;
	try
	{
		level2();
	}
	catch (int len)
	{
		cout << len << endl;
	}
	cout << endl;
	
	//配合注解六 通过继承标准异常库，来创建自己的异常

	cout << "继承标准异常库" << endl;
	try
	{
		throwExceptionError(100, 50);
	}
	
	catch (exception & exp)
	{
		exp.what();
	}

	cout << endl;

	return 0;
}


//注解一：异常抛出通过throw关键词进行，throw可以抛出任何类型作为异常变量，包括int，string等简单类型
//也可以包括class这样的复杂类型，具体使用方法见上面的四个例子

//注解二：异常抛出也可能在其中找不到，这个时候，catch回去找他的异常类型的父类有没有，如果有，还是会继续执行catch中的内容

//注解三：还有一种写法，就是catch(...)用来捕获所有的异常类型

//注解四：要注意的就是，catch之间不能有相互包含的关系，否则程序会运行出错，不知道该执行那个；另外，也不能在构造函数
//中抛出异常，尤其是使用new的时候。因为，构造函数如果抛出异常，意味着对象没有定义，但是内存以及被分配了，对象
//没定义，意味着不会执行析构函数，所以会造成内存泄露

//注解五：验证调用链向上传递

//注解六：通过继承exception类来定义自己的异常。注意两点，一个是必须有头文件exception，另外一个是，必须
//重载虚函数what，返回值为const char*。同时我们提出两个技巧，一是如何把混杂数据类型的串变成字符串，另外
//一个是，如何把string变成const char*