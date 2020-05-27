#include<iostream>
using namespace std;

//深拷贝本质上是值拷贝，会重新生成一个空间进行对象的储存
//浅拷贝本质上是地址的拷贝，多个对象之间共享一组底层对象


//01 深拷贝--定义行为像值的类
class HasPtr
{
public:
	HasPtr(const string &str = string()):_str(new string(str)),_i(0){}
	HasPtr(HasPtr& rhs)
	{
		
		_str = new string(*rhs._str);
		_i = rhs._i;
	}
	HasPtr& operator=(HasPtr& rhs) //一定要释放内存然后重新产生内存。
	{
		if (_str != rhs._str)
		{
			delete _str;
		}
		_str = new string(*rhs._str);
		_i = rhs._i;

		
		return *this;

		/* //另外一种写法
		auto str = new string(*rhs._str);
		delete _str;
		_str = str;
		i = rhs._i;
		return *this;
		
		*/
	}
	~HasPtr()
	{
		delete _str;
	}
private:
	string* _str;
	int _i;
};

//02 浅拷贝--定义行为像指针的类
class HasPtr2
{
public:
	HasPtr2(const string& str = string()):_str(make_shared<string>(str)),_i(0){}
	HasPtr2(shared_ptr<string> str):_str(str),_i(0){}
	//没必要定义拷贝构造和拷贝赋值以及析构函数，一一拷贝是没有问题的。
private:
	shared_ptr<string> _str;
	int _i;
};

//03 浅拷贝--定义自己的智能指针（引用计数)
//思路：计数器也作出动态内存，用于在各个对象之间记录有多少个对象指向值内存
//构造函数产生对象，并且新建计数器
//拷贝构造函数递增计数器，并拷贝对象
//拷贝赋值函数递增rhs计数器，递减lhs计数器
//析构函数用于当计数器为0的时候释放内存对象
class HasPtr3
{
public:
	HasPtr3(const string& str = string()) :_str(new string(str)),_count(new int(1)){}
	HasPtr3(HasPtr3& rhs):_str(_str = rhs._str),_count(rhs._count)
	{ 
		(*_count)++; 
	}
	HasPtr3& operator=(HasPtr3& rhs)
	{
		*(rhs._count)++;
		if (-- * _count == 0)
		{
			delete _str;
			delete _count;
		}
		_str = rhs._str;
		_count = rhs._count;
		return *this;
	}
	~HasPtr3()
	{	
		if (-- (* _count) == 0)
		{
			delete _str;
			delete _count;
		}
	}
private:
	string* _str;
	int* _count;



};
int main()
{
	{
		HasPtr3 b("123");
		HasPtr3 a("234");
		b = a;
	}
	
	return 0;
}

