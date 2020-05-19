#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <class valType>
bool isshorter(const valType& v1, const valType& v2)
{
	return (v1 < v2);
}
bool shorter(const string& v1, const string& v2)
{
	return (v1.size() < v2.size());
}
int main()
{
	//01 谓词就是返回值为bool的一种函数
	vector<int> v1 = { 1,7,3,4,5 };
	sort(v1.begin(), v1.end(), isshorter<int>);

	for (auto i : v1)
	{
		cout << i << endl;
	}

	//02 给字符串数组排序，要求先按长度排序，再按字典顺序排序
	//stable_sort函数能够保证等长字符串按字典排序
	vector<string> s = { "ac","bc","abc","ba","abcd","aaaaaaaa"};
	stable_sort(s.begin(), s.end(),shorter);
	for (auto i : s)
	{
		cout << i << endl;
	}
	//直接排序的话，发现全部都是安字典顺序排的。



	return 0;
}

