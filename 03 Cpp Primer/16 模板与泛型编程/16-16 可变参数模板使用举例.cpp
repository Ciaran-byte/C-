#include<iostream>

using namespace std;

template<typename T,typename...Args> //ģ�������,��ʾ0-n��ģ���������
void foo(const T& t, Args... rest)//��������������ʾ0-n����������
{
	cout << sizeof...(Args) << endl; //����������ͺ���������������
	cout << sizeof...(rest) << endl;
}  
int main()
{
	int a = 1;
	double b = 0.1;
	string s = "123";
	foo(a, b, s);//������Զ����ͽ���

	
	return 0;
}

