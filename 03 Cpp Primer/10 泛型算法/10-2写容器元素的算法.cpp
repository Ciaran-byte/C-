#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<numeric>
#include<iterator>
using namespace std;
int main()
{
	//01 fill
	vector<int> v1 = { 1,2,3,4,5,6,7,8 };
	fill(v1.begin(), v1.end(), 0);
	for (auto i : v1)
	{
		cout << i << endl;
	}

	//02 fill_n
	fill_n(v1.begin(), v1.size(), 1);
	for (auto i : v1)
	{
		cout << i << endl;
	}
	//03 back_inserter
	vector<int> void_vec = { 1,2 };
	auto iter = back_inserter(void_vec);
	*iter = 5; //这个插入迭代器能够执行push_back操作
	cout << void_vec[2] << endl;

	vector<int> v;
	fill_n(back_inserter(v), 10, 0);

	//04 拷贝
	vector<int> a = { 1,2,3 };
	vector<int> b(a.size());
	copy(a.begin(), a.end(), b.begin());
	for (auto i : b)
	{
		cout << i << endl;
	}
	
	vector<int>c = { 1,2,3 };
	vector<int> d;
	copy(a.begin(), a.end(), back_inserter(d));
	cout << endl;
	for (auto i : d)
	{
		cout << i << endl;
	}
	//05 replace
	//把0换成255
	cout << endl;
	vector<int> rep = { 1,0,1,0,1,1,0 };
	replace(rep.begin(), rep.end(), 0, 255);
	for (auto i : rep)
	{
		cout << i << endl;
	}

	cout << endl;
	vector<int> rep2;
	//通过replace_copy将结果放到其他地方
	replace_copy(rep.begin(), rep.end(), back_inserter(rep2), 255, 0);
	for (auto i : rep2)
	{
		cout << i << endl;
	}
	return 0;
}

