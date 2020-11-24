#include<iostream>
using namespace std;


//01 使用把拷贝构造和拷贝赋值定义为私有函数，并且只声明不实现的方法，阻止类A的拷贝
class A
{
public:
	A(){}
	~A() {}
private:
	A(const A&);
	A& operator=(const A&);
};

//02 通过定义不可复制的基类，并且进行继承

class BaseB
{
protected:
	BaseB(){}
	~BaseB(){}
private:

	BaseB(const BaseB&);
	BaseB& operator=(const BaseB&);
};


class B : private BaseB
{

};

//03 通过delete关键字实现

class C
{
public:
	C(){}
	~C() {	}
	C(const C&) = delete;
	C& operator=(const C&)=delete;
};
int main()
{

	//01 法一
	A a;
	//A b = a;
	//A b(a);

	//02 法二
	B b;
	//B m = b;
	//B m(b);

	//03 法三
	C c;
	//C m = c;
	//C n(c);


}