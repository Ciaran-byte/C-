#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int>& v);
void display(vector<int> v);
void swap(int& m, int& n);

int main()
{
	

	//ԭʼvector
	vector<int> v = { 9,2,3,6,1,4,5,0,11 };
	//����ǰ
	cout << "����ǰ" << endl;
	display(v);


	//��������
	bubble_sort(v);

	//��ӡ
	cout << "�����" << endl;
	display(v);

	
	return 0;
}

void display(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
	}
	cout << endl;
}

void bubble_sort(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[i])
			{
				swap(v[j], v[i]);
			}
		}
	}
}
void swap(int& m, int& n)
{
	int t;
	t = m;
	m = n;
	n = t;
}