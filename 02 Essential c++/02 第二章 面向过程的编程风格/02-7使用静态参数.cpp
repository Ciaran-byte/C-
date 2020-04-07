#include<iostream>
#include<vector>
using namespace std;


bool FibnoPrint(int index);


int main()
{

	//���⣺쳲��������д�ӡ�У����ص�vector����ʮ������������߳���Ч��

	//01 ��һ����vector����file scope�� ȱ�㣺������̫��
	//02 ������ʹ�þֲ���̬�����ķ���,����ÿ�ζ�ֻ��Ҫ���������ĳ��Ȳ��ּ��ɡ�
	while (1)
	{
		cout << "��ӡ�೤������" << endl;
		int index;
		cin >> index;
		if(FibnoPrint(index));
		else
		{
			cerr << "������������" << endl;
		}
	}
	

}


bool FibnoPrint(int index)
{

	static vector<int> fib;

	const int max_num = 1024;
	if (index <= 0 || index >= max_num)
	{
		
		return false;
	}
	
		for (int i = fib.size(); i < index; i++)
		{
			if (i == 0 || i == 1)fib.push_back(1);
			else fib.push_back(fib[i - 1] + fib[i - 2]);
		}

	
	for (int i = 0; i < index; i++)
	{
		cout << fib[i] << endl;
	}
	return true;
}

