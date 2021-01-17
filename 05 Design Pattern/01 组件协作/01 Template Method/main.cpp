#include<iostream>
#define ON 1
using namespace std;


#if ON
	//使用了Template_Method
#include "Template2_App.h"
#elif

	//不使用Template_Method
#include"Template1_App.h"

#endif

int main()
{
#if ON
	//使用了Template Method
	//使用了之后，Run函数定义在了library中，一些有变动的步骤写成了虚函数，由application来继承实现。
	//具体实现的步骤在库中已经完成，只是具体实现细节留给了子类实现。
	Library* lb = new Application();
	lb->Run();
	delete lb;
#elif
	//没有使用Template Method
	//没有使用Template Method，Run实现在Application中，是应用层调用库函数层的实现
	Application a;
	a.Run();
#endif
}