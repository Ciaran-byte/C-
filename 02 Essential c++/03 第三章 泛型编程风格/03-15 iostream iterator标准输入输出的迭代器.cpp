#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using namespace std;
int main()

{
	vector<string> words;

	//输入迭代器
	istream_iterator<string> it(cin);
	istream_iterator<string> eof;

	//将输入迭代器内容放置到向量中
	copy(it, eof, back_inserter(words));

	//排序
	sort(words.begin(), words.end());
	
	ostream_iterator<string> os(cout, " ");

	copy(words.begin(), words.end(), os);

	return 0;
}

