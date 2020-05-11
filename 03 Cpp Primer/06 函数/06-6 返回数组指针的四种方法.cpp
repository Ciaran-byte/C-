#include<iostream>
using namespace std;

//01 使用别名的方法返回数组指针
//数组不能被复制，返回数组只能通过指针，使用别名可以让程序看起来更加简洁
using arrT = int[10];
arrT m = { 1,2,3,4,5,6,7,8,9,10 };
arrT n = { 2,3,4,5,6,6,6,6,6,2 };
arrT* f(int i)
{
	if (i == 1)return &m;
	else return &n;
	
}

//02 不使用别名返回数组指针

int (*func(int i))[10]  //因为返回值是一个指向数组的指针，所以函数名必须加括号以表明优先级
//从内往外看， func接受一个int类型的变量
//并且func是个指针
//这个指针指向的对象是个有10个变量的数组
//这个数组里面的元素的int类型的
{
	if (i == 1)return &m;
	else return &n;
}

//03 使用尾置返回 结构为：前有auto，后有返回值类型
auto func2(int i)->int(*)[10]
{
	if (i == 1)return &m;
	else return &n;
}

//04 使用decltype返回数组指针类型
decltype(m) *func3(int i)
{
	if (i == 1)return &m;
	else return &n;
}
int main()
{
	//01 使用别名的方法返回数组指针
	arrT* g = f(1);
	cout << *g[0] << endl;

	//02 不使用别名返回数组指针
	int(*p)[10] = func(1);
	cout << *p[1] << endl;


	//03 使用尾置返回类型
	//可以把返回值类型放在函数名之后，这种写法适合非常复杂的返回值

	int(*q)[10] = func2(1);
	cout << *q[1] << endl;


	//04 使用decltype
	//如果我们已经知道要返回哪个数组了，那我们就可以通过使用decltype读取数组类型的方式设定返回值
	//不过decltype对数组只能解析为数组，不能解析为指针。函数中定义任然需要指定指针类型
	
	
	int(*qq)[10] = func3(1);
	cout << *qq[1] << endl;



	return 0;
}


