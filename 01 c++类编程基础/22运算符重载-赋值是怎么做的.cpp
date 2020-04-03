#include<iostream>
#include<cstring>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class A
{
public:
	int i;
	A(int ii):i(ii){}
	const A& operator =(const A &that)  //引用实际上就是常量指针  const A& 等价于 const A const *
	{
		if (this != &that)//判断this和that是不是指向了同一片地址，如果执向同一片地址，说明是一个东西，不操作了
		{
			this->i = that.i;
		}
		return *this; 
	}
};


class B
{
public:
	char* p;
	const B& operator =(const B& that)  //引用实际上就是常量指针  const A& 等价于 const A const *
	{
		
		delete p;
		p = new char[strlen(that.p) + 1];
		strcpy(p, that.p);
		return *this;
			
	}
};

int main()
{
	B b;
	char a[5]="1233";
	b.p = a;
	cout << b.p << endl;
	B c = b;
	cout << c.p << endl;
	//b = b; //这句话运行会出错的


	return 0;
}
// 注解1：赋值号=一定只能在类中被使用，类A中说明了赋值号重载的意义，而且赋值号重载里面的判断很重要。
// 注解2：类B给出了赋值号重载没有加判断出错的一种例子。因为类B里面有指针变量，指针赋值的时候，先删除旧的，在赋予新的，而在B中，如果b=b，那么删除旧的就是把要赋值的
//新的也删除了，就没有值可以赋予给b了，所以内存会出错，不能正常运行，说明了赋值号重载必须加判断自己指针是否相等这一判断