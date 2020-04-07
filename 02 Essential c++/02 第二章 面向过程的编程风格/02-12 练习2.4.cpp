#include<iostream>
#include<vector>
using namespace std;


const vector<int>* Pentagonal(int index)
{
	static vector<int> pentagon;
	
	if (pentagon.size() < index)
	{
		for (int i = pentagon.size(); i < index; i++)
		{
			pentagon.push_back((i + 1) * (3 * (i + 1) - 1) / 2);
		}
	}
	return &pentagon;

}

bool PentagonalData(int index,int &value)
{
	//�����ⲿ������static�ı������Ұ��ҵĵ�ַ�������ˣ������Ҳ��������޸���
	if (index <= 0 || index > 60)return false;
	else
	{
		const vector<int>* pentagon = Pentagonal(index);
		value = (*pentagon)[index - 1];
	}
	return true;
	
	

	


}
int main()
{
	while (1)
	{
		cout << "����Ҫ�ĸ�����" << endl;
		int index;
		int a;
		cin >> index;
		if (PentagonalData(index, a))
		{
			cout << a << endl;
		}
		else

		{
			cout << "���������д���" << endl;
		}
	}


	return 0;
}



