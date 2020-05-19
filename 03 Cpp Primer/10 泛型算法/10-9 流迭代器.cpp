#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<functional>
#include<numeric>
#include<sstream>
using namespace std;

int main()
{
	//流迭代器的使用
	//01 istream_iterator
	////01-1 istream_iteratoe流迭代器的使用方法
	
		istream_iterator<int> it(cin);
		istream_iterator<int> eof;
		vector<int> a;
		while (it != eof)
		{
			a.push_back(*it++);
		}
		for (auto i : a)
		{
			cout << i << endl;
		}
		cin.clear();
		cin.ignore(200, '\n');
	
	//01-2 使用算法操作流迭代器
	istream_iterator<int> in(cin), eof2;
	
	cout << accumulate(in, eof2, 0) << endl;
	//02 ostream_iterator

	//输出流迭代器用法
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vec = { 1,2,3,4,5,6 };
	for (auto e : vec)
	{
		*out_iter++ = e;//等价于cout<<e<<ends;
		//out_iter = e;//这么写也行

	}
	cout << endl;

	//可以利用copy和输出流迭代器输出东西
	cout << endl;
	ostream_iterator<int> oos(cout, " ");
	copy(vec.begin(), vec.end(), oos);


	//03 使用流迭代器处理类类型

	return 0;
}

