#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//capacity���� ��ǰ�������
	//size���� ʵ�ʺ���Ԫ�ظ���

	//shrink_to_fit ʹ�����˻ض�����ڴ�

	//reserve ���� ���������������
	vector<int> a;
	for (int i = 0; i < 505; i++)
	{
		a.push_back(i);
		cout << a.capacity() << endl;
	}
	while (a.size() != a.capacity())
	{
		a.push_back(0);
	}
	cout << a.capacity() << endl; 
	a.push_back(0);
	cout << a.capacity() << endl;
	a.shrink_to_fit();
	cout << a.capacity() << endl;
	a.reserve(3000);
	return 0;
}

