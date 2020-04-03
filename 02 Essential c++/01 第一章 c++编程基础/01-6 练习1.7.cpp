#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	ifstream infile("test.txt");
	ofstream outfile("out.txt");
	string a; //一开始我用的char做读入变量，不太好
	vector<string> str;
	
		if (!infile) //这个挺重要的
		{
			cerr << "infile error" << endl;
		return -1;
		}
	if (!outfile)
	{
		cerr << "outfile error" << endl;
		return -2;
	}
		//读入
	while (infile >> a)
	{
		str.push_back(a);
	}
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i]<<endl;
	}

	//排序
	cout << endl;
	sort(str.begin(), str.end());
	//显示
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}
	//输出
	for (int i = 0; i < str.size(); i++)
	{
		outfile << str[i] << endl;
	}
	return 0;
}

