#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	ifstream infile("test.txt");
	ofstream outfile("out.txt");
	string a; //һ��ʼ���õ�char�������������̫��
	vector<string> str;
	
		if (!infile) //���ͦ��Ҫ��
		{
			cerr << "infile error" << endl;
		return -1;
		}
	if (!outfile)
	{
		cerr << "outfile error" << endl;
		return -2;
	}
		//����
	while (infile >> a)
	{
		str.push_back(a);
	}
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i]<<endl;
	}

	//����
	cout << endl;
	sort(str.begin(), str.end());
	//��ʾ
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}
	//���
	for (int i = 0; i < str.size(); i++)
	{
		outfile << str[i] << endl;
	}
	return 0;
}

