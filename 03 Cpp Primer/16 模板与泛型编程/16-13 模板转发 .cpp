#include<iostream>
#include<utility>
using namespace std;

//01 配合第一部分
void f(int v1, int& v2)
{
	cout << v1 << " " << ++v2 << endl;
}

template<typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
	f(t2, t1);

}

//02 配合第二部分
template<typename F, typename T1, typename T2>
void flip2(F f, T1&& t1, T2&& t2)
{
	f(t2, t1);
}

//03 配合第三部分
void f2(int&& t1, int& t2)
{
	cout << t1 << " " << ++t2 << endl;
}

//04 配合第四部分
template<typename F,typename T1,typename T2>
void flip3(F f, T1&& t1, T2&& t2)
{
	f(forward<T2>(t2), forward<T1>(t1));
}
int main()
{
	//01 一般模板会丢失变量参数的左值属性还有const属性
	cout << "第一组" << endl;
	int i = 5;
	f(10, i);
	cout << i << endl;

	int j = 5;
	flip1(f, j, 10); //j本来是个int，送入flip1以后失去左值特性，因此后面调用了f对j没有影响，与原f函数效果并不完全相同

	cout << j << endl;
	

	//02 保全左值属性和const属性的方法
	cout << "第二组" << endl;
	int m = 5;
	flip2(f, m, 10);
	cout << m << endl;
	//使用右值引用模板，利用解析规则和折叠规则，保护了原始变量的左值特性

	//03  上一个优化函数存在的缺陷
	//使用02仍有问题，即10虽然是个常量，但是进入flip2之后，被解析为右值引用，右值引用是个左值量
	//如果f函数需要参数t1不是int，而是int&&，仍然不能跟f函数匹配
	cout << "第三组" << endl;
	int n = 5;
	f2(10, n);

	//flip2(f2, n, 10); //无法调用这个翻转函数，因为10送入以后解析为右值引用，右值引用是左值，不能继续送入f2

	//04 进一步优化
	cout << "第四组" << endl;
	int p = 5;
	flip3(f2, p, 10);
		cout << p << endl;
		//forward的作用是继续保证从外部传入变量的左右值属性和常量属性
		//02做的只是保留外部变量的左值属性，forward在此处保留变量的右值属性
		//forward会把T类型变量，转换成T&&类型变量，也就是说，10送入flip3，通过右值引用int&&，变成了左值类型int
		//f2函数要求一个右值类型，10就丢失了右值属性，使用forward把int变成int&&，继续获得右值特性
	return 0;
}


