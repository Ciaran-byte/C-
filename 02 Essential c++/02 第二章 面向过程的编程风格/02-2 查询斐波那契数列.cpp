#include<iostream>
using namespace std;


bool FibonacciVal(int index, int& elem);


int main()
{
	
		cout << "������һ������ֵ��Ϊ���ѯ쳲��������е���ֵ" << endl;
		int index;
		int elem;
		cin >> index;
		if (FibonacciVal(index, elem))
		{
			cout << "��#" << index << "��λ�õ���Ϊ" << elem << endl;
		}
		else
		{
			cout << "�������ݲ���ȷ" << endl;
		}

	
	return 0;
}

bool FibonacciVal(int index, int& elem)
{
	if (index <= 0 || index>1024)
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
