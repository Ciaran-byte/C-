#include<iostream>
using namespace std;
template<typename T>
void debug_rep(const T& p)
{
	cout << "const T&" << endl;
}

template<typename T>
void debug_rep(T* p)
{
	cout << "T*" << endl;
}
void debug_rep(const string&)
{
	cout << "string&" << endl;
}
int main()
{
	//01 ֻ�ܵ������ð汾���ַ���ָ�벻��ֱ�Ӵ���
	string s = "12";
	debug_rep(s);
	//02 �����汾���ɣ�����T*����ȫƥ��汾��
	int a = 1;
	int* p = &a;
	debug_rep(p);

	//03 �����汾�����ԣ����Ҷ�����ȫƥ�䣬����T*�������խ����˸����ػ�������ø��ػ��İ汾
	const int* q = &a;
	debug_rep(q);

	//04 ��ģ���ģ�嶼���Ե�ʱ��ʹ�÷�ģ��汾����Ϊ�����ػ�
	string ss = "123";
	const string& ps = s;
	debug_rep(ps);



	return 0;
}

