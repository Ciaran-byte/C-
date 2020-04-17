#include<iostream>
#include<vector>
#include "Triangular.h"
using namespace std;


int main()
{
	while (1)
	{
		cout << "输入一个数字" << endl;
		int value;
		cin >> value;
		bool rst=Triangular::is_elem(value);
		if (rst)
		{
			cout << "属于这个数列" << endl;
		}
		else
		{
			cout << "不属于这个数列" << endl;
		}
		cout << endl;
	}
}