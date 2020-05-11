#include<iostream>
#include<cassert>
//d#define NDEBUG
using namespace std;


//02 NDEBUG
void f()
{
#ifndef  NDEBUG
	cout << __func__ << endl;
#endif // ! NDEBUF

}

//03 预定义的调试程序的局部静态变量
void ff(int i)
{
	if (i == 1)
	{
		cout << "ERROR:" << __FILE__ << " in function" << __func__ << "at line" << __LINE__
			<< "	compile on " << __DATE__ << " at " << __TIME__ << endl;
	}

}
int main()
{
	//01 assert
	//（1）assert位于头文件cassert中
	//（2）assert是一个宏，由预处理器管理，而非编译器管理
	//（3）assert(expr) exprt条件为假时，触发错误，用于检测不可以发生的条件

	string s;
	cin >> s;
	assert(s!="");

	//02 NDEBUG
	//(1)NDEBUG是一个宏，当它被定义时，assert会什么也不做，不过亲测，好像对assert没有半毛钱影响
	//(2)NDEBUG可以用于条件编译，比如不定义这个参数的时候，做调试功能，定义这个参数的时候，调试语句就不运行了
	
	
	f();//测试条件编译


	//03 预定义的调试程序的局部变量
	ff(1);


	

	return 0;
}


