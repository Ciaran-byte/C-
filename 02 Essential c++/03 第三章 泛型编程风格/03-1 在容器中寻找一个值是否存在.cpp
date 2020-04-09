#include<iostream>
#include<vector>
using namespace std;

//01 最简单任务
int* find( vector<int>& num, int value)
{
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == value)
		{
			
			return &num[i];
		}
		
	}
	return 0;
}

//02 升级为对所有数据类型通用
template<typename T>
T* find2(vector<T>& num, T value)
{
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == value)
		{

			return &num[i];
		}

	}
	return 0;
}

//03-1 通过头指针和变量长度来实现
template<typename T>
T* find3(T *array,int size,T value)
{
	if (!array || size < 1)return 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == value)
			return &array[i];

	}
	return 0;
}

/// 03 - 2 通过头指针和终点指针来实现来实现
template<typename T>
T* find4(T* begin, T* end, T value)
{
	if (!begin || !end)return 0;
	for (; begin!=end; begin++)
	{
		if ((*begin) == value)
			return begin;

	}
	return 0;
}
/// 04  考虑array和vector的差异
template<typename T>
inline  T* Begin(T* vec)
{
	return vec==NULL ? 0 : &vec[0];
}
template<typename T>
inline  T* End( T* vec)
{
	return vec==NULL ? 0 : &vec[sizeof(vec)-1];
}
template<typename T>
T* find5(T* begin, T* end, T value)
{
	if (!begin || !end)return 0;
	for (; begin != end; begin++)
	{
		if (*begin == value)
			return begin;

	}
	return 0;
}

int main()
{
	//01 最原始的版本，仅仅需要输入一个向量，然后返回是否存在这个数字即可
	vector<int> num = { 1,2,3,4,5,6,7 };
	int array[]= { 1,2,3,4,5,6,7 };

	cout << *(find(num, 5)) << endl;

	//02 下面我们进行要求升级，如何做一个脱离变量类型的搜索函数呢？
	//用到以前的知识来考虑，仅仅需要使用模板即可
	cout << *(find2<int>(num, 5)) << endl;

	//03 需求继续升级，如何做一个对向量和数组均通用的搜索函数呢?
	
	//03-1 法一，通过头指针和数组长度来实现
	cout << *(find3(&num[0],num.size(),5)) << endl;
	//03-2 法二，通过头指针和终点指针来实现
	cout << *(find4<int>(&num[0], &num[num.size() - 1], 5)) << endl;
	
	//04 考虑向量和数组的差异：数组不可以为空，向量可以为空，因此，如果传入为空，会报错
	cout<<*(find5<int>(Begin(&num[0]), End(&num[0]), 5)) << endl;
	cout << *(find5<int>(Begin(&array[0]), End(&array[0]), 5)) << endl;
	
	return 0;
}


