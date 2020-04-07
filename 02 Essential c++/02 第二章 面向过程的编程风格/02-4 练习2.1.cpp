#include<iostream>
using namespace std;


bool FibonacciVal(int index, int& elem);

//程序目的：多次查询斐波那契数列的值，直到用户想要停止为止
int main()
{
	bool more = true;
	while (more)
	{


		cout << "请输入一个索引值，为你查询斐波那契数列的数值" << endl;
		int index;
		int elem;
		cin >> index;
		if (FibonacciVal(index, elem))
		{
			cout << "第#" << index << "个位置的数为" << elem << endl;


			bool correct = true;
			while (correct)
			{

				cout << "还想再试一次吗?(Y/N)" << endl;
				char usr_rsp;
				cin >> usr_rsp;
				if (usr_rsp == 'n' || usr_rsp == 'N' || usr_rsp == 'y' || usr_rsp == 'Y')
				{
					correct = false;
					if (usr_rsp == 'n' || usr_rsp == 'N')
					{
						more = false;
					}


				}
				else
				{
					cout << "请重新输入" << endl;
				}

			}
		
		}

		else
		{
			cout << "输入数据不正确" << endl;

		}
	}

	return 0;
}

bool FibonacciVal(int index, int& elem)
{
	if (index <= 0 || index > 1024)
	{
		return false;
	}

	elem = 1;
	int n1 = 1;
	int n2 = 1;
	for (int i = 3; i <= index; i++)
	{
		elem = n1 + n2;
		n1 = n2;
		n2 = elem;
	}

	return true;
}
