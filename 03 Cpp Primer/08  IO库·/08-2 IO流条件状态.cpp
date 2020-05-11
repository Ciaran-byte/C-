#include<iostream>
using namespace std;

int main()
{
	// 01 bad函数只要非常严重的系统级错误时，才会报错
	if (cin.bad())
	{
		cout << "cin is bad" << endl;
	}
	else
	{
		cout << "cin is not bad" << endl;
	}
	//02 fail是一种读取失败的状态，比如需要一个int，给了一个char，无法转换，就能够使fail为true
	int i;
	cin >> i;
	if (cin.fail())
	{
		cout << "cin is fail" << endl;
	}
	else
	{
		cout << "cin is not fail" << endl;
	}

	//03 eof 是否到达文件最后,输入 ctrl+z就是结束符
	int m;
	cin >> m;
	if (cin.eof())
	{
		cout << "结束了" << endl;
	}
	else
	{
		cout << "没结束" << endl;
	}

	//04 good状态，是除去bad,fail,eof以外的状态
	int n;
	cin >> n;
	if (cin.good())
	{
		cout << "好！" << endl;
	}
	else
	{
		cout << "不好" << endl;
	}
	return 0;
}

