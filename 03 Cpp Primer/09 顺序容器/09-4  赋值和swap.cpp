#include<iostream>
#include<array>
#include<vector>
using namespace std;
int main()
{
	//01 赋值
	//array支持赋值运算，但是必须左右两边值相同
	vector<int> v1 = { 1,2,3 };
	vector<int> v2;
	//直接赋值
	v2 = v1;
	//使用列表赋值
	v2 = { 1,2,3,4,5 };
	
	array<int, 10> ar = { 0 };
	array<int, 10> ar2;
	ar2 = ar;
	//02 swap
	//交换两个容器中的变量

	//原始数值
	vector<int> v3 = { 1,2,3,4,5 };
	vector<int> v4 = { 2,3,4,6,7,8 };
	for (auto& i : v3)
	{
		cout << i << endl;
	}
	cout << endl;

	for (auto& i : v4)
	{
		cout << i << endl;
	}
	cout << endl;

	//交换一次
	swap(v3, v4);
	for (auto& i : v3)
	{
		cout << i << endl;
	}
	cout << endl;

	for (auto& i : v4)
	{
		cout << i << endl;
	}
	cout << endl;

	//再交换一次
	v3.swap(v4);
	for (auto& i : v3)
	{
		cout << i << endl;
	}
	cout << endl;

	for (auto& i : v4)
	{
		cout << i << endl;
	}
	cout << endl;
	//03 assign
	//用一组迭代器变量，替换当前迭代器的内容
	vector<int> v5 = { 1,2,3,4,5 };
	vector<int> v6 = { 0,1,2,3,4 };

	//用v6中的元素取代原来v5的值
	v5.assign(v6.begin(), v6.end());
	for (auto& i : v5)
	{
		cout << i << endl;
	}
	cout << endl;

	//用列表取代v5的值
	v5.assign({ 6,7,8,9 });
	for (auto& i : v5)
	{
		cout << i << endl;
	}
	cout << endl;

	//用5个6来代替v5的值
	v5.assign(5, 6);
	for (auto& i : v5)
	{
		cout << i << endl;
	}
	cout << endl;
	return 0;
}


