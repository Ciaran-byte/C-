#include<iostream>
#include<iterator>
#include<fstream>
#include<vector>
using namespace std;


int main()
{
	//来自标准输入的迭代器
	istream_iterator<int> it(cin);
	istream_iterator<int> eof;

	//文件的标准输出
	ofstream outfile_even("4.txt");
	ofstream outfile_odd("5.txt");
	if (!outfile_even || !outfile_odd)
	{
		cerr << "文件打不开！" << endl;
		return -1;
	}
	//储存数据
	vector<int> even_number;
	vector<int> odd_number;

	//按照奇数和偶数进行划分数据
	for (; it != eof; it++)
	{
		if ((*it) % 2 == 0)even_number.push_back(*it);
		else odd_number.push_back(*it);
	}

	//迭代器输出到文件中
	ostream_iterator<int> os_even(outfile_even, "\n");
	ostream_iterator<int> os_odd(outfile_odd, " ");
	copy(even_number.begin(), even_number.end(), os_even);
	copy(odd_number.begin(), odd_number.end(), os_odd);



	return 0;
}


