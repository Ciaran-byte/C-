#include<iostream>
using namespace std;
class myClass
{
public:
	int myNum()
	{
		
		return num;
	}

	int myNum2()const
	{
		
		return num;
	}
private:
	 int num = 1;
};

int main()
{
	//01 类的成员函数访问成员变量的实质
	//通常我们想要通过类中的函数访问私有成员变量是这样做的

	myClass cls;
	cout << cls.myNum();

	//	可是这句话是怎么实现调用cls中的num对象的呢？
	//这是因为，每一个类中都有一个隐藏的指针this，指向实例本身
	//return num 实际上等价于 return this.num  只要外部的实例对象能够把自己指针传入进函数，函数就能够找到
	//实例对象中的成员变量

	//	所以，cls.myNum()这句话，实质上更像是myNum(&cls); cls这个实例对象把自己的地址传给了函数myNum
	//然后this指针得到了赋值


	//02 this指针的本质
	//	同时还应该注意一下，this指针本质是个常量指针，不能更改地址的指针

	//03 const成员函数
	//const类型的成员函数是指，通过这个函数，不允许修改类中的成员变量
	//const成员函数的本质在于，把this指针变成了指向常量的常量指针，因此就不能在函数中修改成员变量了
	
	//等价于
	// int myNum2(const myClass* const this)
	//{
	//           return this.num;
	//}

	return 0;
}

