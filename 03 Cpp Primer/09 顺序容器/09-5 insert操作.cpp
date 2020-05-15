#include<iostream>
#include<array>
#include<vector>
#include<string>
#include<list>
#include<deque>
using namespace std;
int main()
{

	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 2,3,4 };
	//01 insert基本使用方法
	v1.insert(v1.begin(), 1); //往某个位置插入值
	v1.insert(v1.begin(), v2.begin(), v2.end()); //范围插值
	v1.insert(v1.begin(), 10, 5);//插入固定数量
	v1.insert(v1.begin(), { 1,2,3,4,5 });//插入列表

	//02 使用insert返回值实现连续插入
	int i;
	auto it = v1.begin();
	while (cin >> i)
	{
		it = v1.insert(it, i);//insert返回值是插入的新值的第一个位置
	}
	

	return 0;
}

