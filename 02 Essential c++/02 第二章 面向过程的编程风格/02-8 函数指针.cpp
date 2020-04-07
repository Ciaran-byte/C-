#include<iostream>
using namespace std;

//01 函数指针怎么用
//01-1 假设我有一些专门打印序列名字的函数
void fibonPrint()
{
	cout << "this is fibon" << endl;
}

void lucusPrint()
{
	cout << "this is lucus" << endl;
}
void pellPrint()
{
	cout << "this is pell" << endl;
}
void trianglePrint()
{
	cout << "this is triangle" << endl;
}
void squarePrint()
{
	cout << "this is square" << endl;
}
void pentPrint()
{
	cout << "this is pent" << endl;
}


//01-2 假如我有一个专门处理数列的函数(假设返回数列第几个数字）,处理完了以后打印数列名字

//如果直接写，要写多个函数，处理fibno函数的打印fibno名字,就要写多个函数
void func_fibno()
{
	//随便什么处理

	fibonPrint();
}
void func_pell()
{
	pellPrint();
}

//使用函数指针,可以用一个函数代表全部的函数
void func2(void (*ptr)(void))
{
	ptr();
}

//02 函数指针使用的进一步优化

//用数组来储存函数指针，这样就可以用序列来访问了
void (*ptr_array[])(void) =
{
	fibonPrint,lucusPrint,pellPrint,trianglePrint,squarePrint,pentPrint
};

//用枚举给每个序列赋予意义

enum ns_type
{
	ns_bibno,
	ns_lucus,
	ns_pell,
	ns_triangle,
	ns_square,
	ns_pent
};


int main()
{
	//解决问题：有同样参数列表、同样返回值的函数，在其他函数中需要调用这些函数，就可用函数指针的方法来
	//减少函数的定义数量。因为相当于你要为每个调用的函数写一个专门的函数。

	//01 函数指针的使用
	//直接写各个函数的处理+打印函数
	func_fibno();
	func_pell();

	//用函数指针就可以一个函数代表了,与上面效果一样，但是更简单
	func2(fibonPrint);
	func2(pellPrint);
	
	//02 用序列的方法优化函数指针，不然要记住很多函数的名字

	//用序列对函数指针进行管理，更加的方便
	func2(ptr_array[0]);
	func2(ptr_array[ns_pell]);
	return 0;
}

