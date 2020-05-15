#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//01 默认初始化
	vector<int> v1;

	//02 拷贝初始化
	vector<int> v2(v1);
	vector<int> v3 = v2;

	//03 初始化列表
	vector<int> v4 = { 1,2,3 };
	vector<int> v5{ 1,2,3 };

	//04 定义长度初始化
	vector<int> v6(5);
	vector<int> v7(5, 1);
	//05 使用迭代器赋值
	vector<int> v8(v7.begin(), v7.end());
	
	return 0;
}

