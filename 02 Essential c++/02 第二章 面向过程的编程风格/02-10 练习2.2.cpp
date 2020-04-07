#include<iostream>
#include<vector>
#include<iterator>
#include<string>

using namespace std;



bool Pentagonal(int index, vector<int>& list)
{
	if (index <= 0 || index >= 1024)return false;
	static vector<int> elems;
	if (elems.size() < index)
	{
		for (int i = elems.size(); i < index; i++)
		{
			elems.push_back((i+1) * (3 * (i+1) - 1) / 2);
		}

	}
	list.assign(elems.begin(), elems.begin() + index);
	
	return true;
}
void PentagonalPrint(vector<int>& list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i] << endl;
	}
}
int main()
{
	while (1)
	{
		cout << "多少？" << endl;
		int index;
		cin >> index;

		vector<int> list;
		if (Pentagonal(index, list))
		{
			PentagonalPrint(list);
		}
		else
		{
			cout << "输入数据有问题" << endl;
		}
		
	}
	


	return 0;
}



