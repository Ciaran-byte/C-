#include<iostream>
#include<vector>
#include "Triangular.h"
using namespace std;


int main()
{
	while (1)
	{
		cout << "����һ������" << endl;
		int value;
		cin >> value;
		bool rst=Triangular::is_elem(value);
		if (rst)
		{
			cout << "�����������" << endl;
		}
		else
		{
			cout << "�������������" << endl;
		}
		cout << endl;
	}
}