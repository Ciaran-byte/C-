#include<iostream>
#include<cassert>
using namespace std;
void d() { cout << "d()" << endl; };
void f(int) { cout << "f(int)" << endl; }
void f(int,int) { cout << "f(int,int)" << endl; }
void f(double,double =3.14) { cout << "f(double m,double i=3.14)" << endl; }


int main()
{
	//重载函数匹配的过程有三个步骤
	//(1) 发现候选函数，主要是通过函数名来确定
	//(2) 发现可行函数，根据参数列表的类型和个数进一步选择
	//(3）发现最佳选项，一般是有两个以上函数能够匹配的时候会选择一个最佳的，但是如果无法判断谁是最佳的函数
	//程序无法运行，叫做二义性。
	
	f(1);//通过名字判断选f不选d
		//通过参数列表只有一个，并且是int，找f（int)
	    //只有一个能匹配，不存在最佳选项
	
	f(3.14);//通过名字选f不选的
	        //f(int)和f(double,double=3.14)均可以调用，都是可行函数
	         //调用后面那个函数不发生数据信息丢失，做了一次最佳选项

	//f(5, 3, 14);//发生二义性，有两个函数可以调用，但都不是最佳的

	return 0;
}