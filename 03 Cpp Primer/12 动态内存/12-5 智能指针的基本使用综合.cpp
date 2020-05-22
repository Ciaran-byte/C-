#include<iostream>
#include<memory>
using namespace std;
int main()
{
	//01 智能指针的定义与初始化
	shared_ptr<int> p1;   //默认初始化，无定义
	//shared_ptr<int> p2();//值初始化
	shared_ptr<int> p3(make_shared<int>(1)); //使用make_shared函数进行初始化
	shared_ptr<int> p4 = make_shared<int>(1); //这个函数可以用来进行默认初始化，产生临时的智能指针对象赋值给p5
	shared_ptr<int> p5(new int(6));  //使用new来作为参数进行初始化，但是这种的构造函数是explicit的
	cout << *p5 << endl;
	//02 智能指针的赋重新值
	shared_ptr<int> p6;
	p6 = p5; //与p5共享内存
	p6 = make_shared<int>(7); //独立重新产生内存
	p6.reset(new int(5));  //独立重新产生内存

	
	
	//03 智能指针修改值时要注意一点
	//如果就想改一个值，要先判断一下是否是unique是，如果不是，复制一份再改
	if (!p6.unique())
	{
		p6.reset(new int(*p6));  //重新分配内存地址进行赋值
	}
	else
	{
		(*p6)++;//如果是只有它一个，直接修改就行
	}

	//04 关于智能指针动态内存地址的删除
	//会在count值为0的时候自动释放

	
	return 0;
}

