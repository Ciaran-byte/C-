
//程序功能：说明了类的基本使用方法。构建了售票机的运作流程，初始化一个售票机的对象tm，显示一些内容，然后输入金额，显示余额。

#include<iostream>
#include "02TicketMachine.h"
using namespace std;
int main()
{
	TicketMachine tm(0);
	
	tm.showprompt();
	int a = 10;
	tm.insertmoney(a);
	tm.showbalance();

	return 0;
}
//头文件使用建议
//(1)每个类都使用一个单独的头文件存放
//（2）函数定义写在同名的cpp文件中
//(3)应该使用条件编译的方法定义头文件，以防重复定义的问题。