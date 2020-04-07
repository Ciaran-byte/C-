#include<iostream>
using namespace std;
extern int a  ;
extern int b;
extern int c;
int main()
{
	cout << a << endl;  //普通变量声明在此，定义在其他地方，正常使用
	//cout << b << endl;//const变量声明在此，定义在其他地方，不能使用，因为const立刻file就失效
	//cout << c << endl;//static 变量声明在此，定义在其他地方，不能使用，static具有隐藏特性
	return 0;
}

