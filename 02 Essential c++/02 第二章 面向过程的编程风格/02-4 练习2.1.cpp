#include<iostream>
using namespace std;


bool FibonacciVal(int index, int& elem);

//����Ŀ�ģ���β�ѯ쳲��������е�ֵ��ֱ���û���ҪֹͣΪֹ
int main()
{
	bool more = true;
	while (more)
	{


		cout << "������һ������ֵ��Ϊ���ѯ쳲��������е���ֵ" << endl;
		int index;
		int elem;
		cin >> index;
		if (FibonacciVal(index, elem))
		{
			cout << "��#" << index << "��λ�õ���Ϊ" << elem << endl;


			bool correct = true;
			while (correct)
			{

				cout << "��������һ����?(Y/N)" << endl;
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
					cout << "����������" << endl;
				}

			}
		
		}

		else
		{
			cout << "�������ݲ���ȷ" << endl;

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
