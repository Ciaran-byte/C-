#include<iostream>
using namespace std;


//01 typename�����ԣ����ڶ���template��Ҫһ�����ͣ����ڱ���Ƕ�״���������
template<typename T>
void print2nd(const T& container)
{
	if (constainer.size() > 2)
	{
		//T::const_iterator iter(container.begin());//���в��ܱ���ɹ�����Ϊ���ǲ���֪��T::const_iterator �Ǹ��������Ǹ�����
		typename T::const_iterator iter(container.begin()); //ֻ��ǰ�����typename�Ժ󣬲���ȷ���Ǹ����Ͳ��Ǳ�����
		++iter;
		int value = *iter;
		cout << value;
	}
}
//02 typename�����ڱ���Ƕ�״������Ƶ�����--�̳еĻ�����ǰ��initialization list�в���ʹ��


int main()
{

	return 0;
}

