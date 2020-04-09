#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int main()

{
	ifstream in_file("1.txt");
	ofstream out_file("2.txt");
	vector<string> words;

	//输入迭代器
	istream_iterator<string> it(in_file);
	istream_iterator<string> eof;

	//将输入迭代器内容放置到向量中
	copy(it, eof, back_inserter(words));

	//排序
	sort(words.begin(), words.end());

	ostream_iterator<string> os(out_file, " ");

	copy(words.begin(), words.end(), os);

	return 0;
}

