#include<iostream>
using namespace std;

//01 函数指针的定义和使用
bool lengthCompare(const string& s1, const string& s2)
{
	return s1.size() == s2.size();
}
//02 函数指针作为参数列表
//记得一定要使用括号，不使用括号就不是函数指针了
bool moreComepare(const string& s1, const string& s2, bool(*pf)(const string& s1, const string& s2))
{
	return (*pf)(s1, s2);
}

//03 函数指针作为返回值
int F1(int num)
{
	return num;
}

int (*FFF(int i))(int num)  
{
	int (*q)(int num) = &F1;
	return q;
 }
//从内往外看，最里面的括号表示 FFF是一个函数，需要一个参数为i。返回值是个*，说明是个指针
//再往外层仔细看，发现这个指针指向的是一个函数，函数样子为 int func(int num)

//04 函数指针的简化

//04-2 函数作为参数列表的简化

//一种别名方法
typedef bool(*DEF_B)(const string& s1, const string& s2); 
bool moreCompare2(const string& s1, const string& s2, DEF_B ptr2)
{
	return ptr2(s1, s2);
}

//两种别名定义方法
typedef decltype(lengthCompare)* DEF_C;
bool moreCompare3(const string& s1, const string& s2, DEF_C ptr3)
{
	return ptr3(s1, s2);
}

//第三种定义别名的方法
using DEF_D = bool (*)(const string & s1, const string & s2);
bool moreCompare4(const string& s1, const string& s2, DEF_D ptr4)
{
	return ptr4(s1, s2);
}

//04-3 函数作为返回类型的使用简化
//第一种方法
typedef int(*F_A)(int num);
F_A FFF2(int i)
{
	F_A ptr1 = &F1;
	return ptr1;
}
//第二种方法
typedef decltype(F1)* F_B;
F_B FFF3(int i)
{
	F_B ptr2 = &F1;
	return ptr2;
}
//第三种方法
using F_C = int (*)(int num);
F_C FFF4(int i)
{
	F_C ptr3 = &F1;
	return ptr3;
}

//第四种方法 除了定义别名以外，还可以使用尾置返回方法
auto FFF5(int i)->int(*)(int i)
{
	F_C ptr4 = &F1;
	return ptr4;
}

int main()
{
	//01 函数指针的定义和使用

	//函数指针的定义必须有函数样子完全相同
	//01-1 函数指针的定义
	bool (*ptr)(const string & s1, const string & s2);

	//01-2 函数指针的赋值
	//就像其他的指针类型一样，通过取函数地址就可以对函数指针进行赋值
	ptr = &lengthCompare;
	//不过因为函数名本身可以被解析为指针，不带取地址符也是可以的
	ptr = lengthCompare;

	//01-3 函数指针的使用
	cout << (*ptr)("hell0", "hi") << endl;
	cout << ptr("hell0", "hi") << endl; //不使用解引用符号也行
	cout << lengthCompare("hell0", "hi") << endl;//可以看出来跟原来的函数效果是一样的

	//02 函数指针作为参数列表
	//函数指针也是可以当做参数列表的
	//使用的时候即可以传入函数指针，也可以传入原来的函数
	cout << endl;
	cout << moreComepare("123", "321", lengthCompare)<<endl;
	cout << moreComepare("123", "321", ptr) << endl;;


	//03 函数指针作为返回值
	//函数指针也可以当做返回值使用，不过定义起来非常的麻烦
	cout << endl;
	cout << FFF(1)(5) << endl;
	//第一个括号FFF(1)是调用了函数FFF，返回值是int fun(int num); 
	//所以FFF（1）作为一个函数类型继续调用，fun(5)，返回值就是5

	//04 使用别名的方法简化函数指针
//可以通过定义别名的方法简化这些东西

	//04-1 函数指针的使用简化
	cout << endl;
	cout << "04-1" << endl;
	typedef bool(*DEF_A)(const string& s1, const string& s2);
	DEF_A ptr1; //DEF是一个函数指针
	ptr1 = &lengthCompare; //对这个函数指针进行赋值
	cout<<ptr1("hi", "hello")<<endl; //使用这个函数指针
	//04-2 函数作为参数列表的使用简化
	cout << endl;
	cout << "04-2" << endl;
	cout << moreCompare2("123", "321", lengthCompare)<<endl;
	cout << moreCompare2("123", "321", ptr1)<<endl;
	cout << moreCompare3("123", "321", lengthCompare) << endl;
	cout << moreCompare4("123", "321", lengthCompare) << endl;

	//04-3 函数作为返回类型的使用简化
	cout << endl;
	cout << "04-3" << endl;
	cout << FFF2(2)(5) << endl;
	cout << FFF3(2)(5) << endl;
	cout << FFF4(2)(5) << endl;
	cout << FFF5(2)(5) << endl;

	//05 指向重载函数的函数指针
	//指向重载函数的指针比较简单，就是函数指针必须跟其中一种重载函数完全匹配即可，这里不举例子了

}