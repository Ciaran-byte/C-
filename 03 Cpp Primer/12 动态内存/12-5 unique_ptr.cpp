#include<iostream>
#include<memory>
using namespace std;
unique_ptr<int> fun()
{
	return unique_ptr<int>(new int(5));
}
unique_ptr<int> fun2()
{
	unique_ptr<int>ret(new int(5));
	return ret;
}
int main()
{
	//01 unique_ptr的基本使用
	//定义方法,只能通过new，并且不能拷贝
	unique_ptr<int> p(new int(5));

	//02 智能指针的移交
	//可以通过使用release和reset函数移交指针控制权，注意，release必须有人接受这个内存，否则就出现内存泄露
	unique_ptr<int> p2(p.release());
	//指针控制权从p交给p2，p被清空

	unique_ptr<int> p3(new int(6));
	p3.reset(p2.release());
	//控制权从p2交给p3，p2清空

	//如果没有智能指针接受这个内存，而是通过普通指针接受，必须用delete
	auto p4 = p3.release();
	delete p4;

	//03 unique_ptr用于函数传递
	//unique_ptr虽然不能直接拷贝，但是我们可以通过返回一个即将被释放的对象，实现拷贝，这是允许的
	//如函数fun和fun2，要么返回临时对象，要么返回局部对象

	//04 重载删除器
	


	return 0;
}