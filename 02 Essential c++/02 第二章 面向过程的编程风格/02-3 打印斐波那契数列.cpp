#include<iostream>
using namespace std;


bool FibonacciPrint(int index);


int main()
{
	

		cout << endl;
		cout << "你想打印多少长度的斐波那契数列" << endl;
		int index;
		cin >> index;

		if (FibonacciPrint(index));
		else
		{
			cerr << "你输入数据有问题" << endl;
		}

	
		return 0;
	
}

bool FibonacciPrint(int index)
{
	int elem = 1;
	int n1 = 1;
	int n2 = 1;
	if (index <= 0 || index > 1024)return false;
	switch (index)
	{
	default:
	case 2:
		cout << "1\t";
	case 1:
		cout << "1\t";
		break;
	}
	
	for (int i = 3; i <= index; i++)
	{
		elem = n1 + n2;
		n1 = n2;
		n2 = elem;
		cout << elem << (i%10?"\t":"\n");
	}

	return true;
}
