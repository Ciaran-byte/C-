#include<iostream>
#include<type_traits>
using namespace std;

template<typename It>
auto fun(It beg, It end)-> typename remove_reference<decltype(*beg)>::type  
//type������������Ҫ������ģ����ǰ�����typename����������Ϊ���������Ǳ�������

{
	return *beg;
}
int main()
{

	//����decltype����ģ��������������ͣ�ʹ��remove_reference��ȥ�������ԣ����ֵ����
	//��������˽������������Ͳ��ҷ�����ֵ����



	return 0;
}


