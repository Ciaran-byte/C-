#include<iostream>
using namespace std;
void func(int& x) //引用做函数
{
	x += 1;
}
int main()
{
	int c = 47;
	int& r = c;  //&表示引用

	const int& m = c;//前面加了const意思是，我们不能通过m修改c，但是可以通过c来修改m
	func(c);
	cout << c << endl << r << endl << m << endl;
	return 0;
}

//引用又可以叫做别名，对于本程序而言，意思就是，使用r就是使用c，只是名字不同



