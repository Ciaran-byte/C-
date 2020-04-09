#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> ilist = { 1,2,3,4,5,6,7 };

	//01 第一种插入方法，在指定地址前插入
	list<int>::iterator it = find(ilist.begin(), ilist.end(), 7);
	ilist.insert(it, 5);
	//02 第二种方法，在指定地址前插入n个相同的数
	ilist.insert(it, 3, 5);//在it的地址前面插入3个5
	//03 第三种方法，在指定地址前面插入一个其他的序列
	int a1[] = { 2,3,4,5,6 };
	list<int>add(a1, a1 + 5); //这个截取是[left,right) 所以右边那个数字选择的时候，应该再往下取一个地址
	ilist.insert(it, add.begin(), add.end());
	//输出应该是 1,2,3,4,5,6,5,5,5,5,2,3,4,5,6,7
	it = ilist.begin();
	list<int>::iterator end = ilist.end();
	for (; it != end; it++)
	{
		cout << (*it) << endl;
	}



	return 0;
}

