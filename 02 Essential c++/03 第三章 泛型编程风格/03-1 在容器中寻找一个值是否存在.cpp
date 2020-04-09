#include<iostream>
#include<vector>
using namespace std;

//01 �������
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

//02 ����Ϊ��������������ͨ��
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

//03-1 ͨ��ͷָ��ͱ���������ʵ��
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

/// 03 - 2 ͨ��ͷָ����յ�ָ����ʵ����ʵ��
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
/// 04  ����array��vector�Ĳ���
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
	//01 ��ԭʼ�İ汾��������Ҫ����һ��������Ȼ�󷵻��Ƿ����������ּ���
	vector<int> num = { 1,2,3,4,5,6,7 };
	int array[]= { 1,2,3,4,5,6,7 };

	cout << *(find(num, 5)) << endl;

	//02 �������ǽ���Ҫ�������������һ������������͵����������أ�
	//�õ���ǰ��֪ʶ�����ǣ�������Ҫʹ��ģ�弴��
	cout << *(find2<int>(num, 5)) << endl;

	//03 ������������������һ���������������ͨ�õ�����������?
	
	//03-1 ��һ��ͨ��ͷָ������鳤����ʵ��
	cout << *(find3(&num[0],num.size(),5)) << endl;
	//03-2 ������ͨ��ͷָ����յ�ָ����ʵ��
	cout << *(find4<int>(&num[0], &num[num.size() - 1], 5)) << endl;
	
	//04 ��������������Ĳ��죺���鲻����Ϊ�գ���������Ϊ�գ���ˣ��������Ϊ�գ��ᱨ��
	cout<<*(find5<int>(Begin(&num[0]), End(&num[0]), 5)) << endl;
	cout << *(find5<int>(Begin(&array[0]), End(&array[0]), 5)) << endl;
	
	return 0;
}


