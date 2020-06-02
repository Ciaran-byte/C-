#include<iostream>
using namespace std;

//01 ��ͨ�İ���չ
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}

template<typename T, typename ...Args>
ostream& print(ostream& os, const T& t, const Args&...rest) //��ͬģ�������չ�������
{
	os << t << ",";
	return print(os, rest...); //�ѱ���������չ�ȼ��� print(os,rest1,rest2...)�ȵ�
}

//02 �߼���չ
//return print(os,func(rest)...); �ȼ��� print(os,func(rest1),func(rest2))

//return print(os,func(rest...)); �ȼ���print(os,func(rest1,rest2,rest3....));

int main()
{

	return 0;
}

