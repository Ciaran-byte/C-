#include<iostream>
#include<vector>
using namespace std;

void calcValue(int index, vector<int>& elems)
{
	for (int i = elems.size(); i < index; i++)
	{
		elems.push_back((i + 1) * (3 * (i + 1) - 1) / 2);
	}
}

inline bool Pentagonal(int index, vector<int>& list)
{
	if (index <= 0 || index >= 60)return false;
	static vector<int> elems;
	if (elems.size() < index) calcValue( index,elems);
	list.assign(elems.begin(), elems.begin() + index);
	return true;
}

int main()
{
	vector<int> list;
	int index = 10;
	if (Pentagonal(10, list))
	{
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i] << endl;
		}
	}
	else
	{
		cout << "数据输入有问题" << endl;
	}


	

	return 0;
}





