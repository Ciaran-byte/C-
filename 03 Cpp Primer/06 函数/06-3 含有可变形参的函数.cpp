#include<iostream>
using namespace std;

//01 initializer_list �ķ��������������Ҫ���벻ͬ�����Ĳ���
void f(initializer_list<string> str)
{
	auto it = str.begin();
	for (;it != str.end(); ++it)
	{
		cout << *it << endl;
	}
}

int main()
{
	//01 ʹ��initialize_list �βδ��ݱ���������ʵ�ֺ������ܹ����벻ͬ�����Ĳ���
	//ע�⴫�ݱ�����ʱ��һ��Ҫ�ӻ����ţ���Ȼû�а취��Ϊ��ʼ��ֵ���ݸ�����f��ͬʱ�������ڲ����б�������initializer_list
	//����Ĳ���
	f({ "hell0","hi","how are you" });
	

	return 0;
}