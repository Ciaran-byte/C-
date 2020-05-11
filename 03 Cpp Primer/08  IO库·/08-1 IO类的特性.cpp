#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//01 无拷贝特性
void f(ifstream fs)
{
	cout << "hell0" << endl;
}

void ff(ifstream& fs)
{
	cout << "hell0" << endl;
}


//会报错
//ostream fff(ostream& os)
//{
//	return os;
//}


ostream& ffff(ostream& os)
{
	return os;
}


int main()
{
	//01 无拷贝特性
	//无拷贝是指，IO类直接不能直接复制，包括作为返回值或者函数参数列表

	//01-1不支持直接拷贝
	ifstream s1, s2;
	//s1 = s2;  //报错 不支持拷贝

	//01-2 不支持直接作为参数列表传递，如果要是有必须使用指针或者引用类型
	//f(s1);
	ff(s1);

	//01-3 不支持直接作为返回值，如果要使用可以使用引用类型
	ffff(cout)<<"123";

	//02 利用继承结构，可以使用多态的特性，使用基类作为参数列表，提供函数的扩展性。
	return 0;
}

