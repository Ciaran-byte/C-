#include<iostream>
using namespace std;
//01 �������������ⲿ������ͬ����������������
string init()
{
	return "hello";
}

void print()
{
	string s=init();
	cout << s << endl;
}


//void print2()
//{
//	int init = 0;
//	string s = init();
//	cout << s << endl;
//}

//02 ͬ���ľֲ�������������������������
void p(int i);
void p(const string& s);
void p(double val);

void foo()
{
	//�ܹ��������ɺ�������
	p(1);
	p("hello");
	p(3.14);
}

void foo2()
{
	void p(int i); //����һ���ֲ��ĺ�������

	p(1);   //�����ɺ������أ���Ϊ�ֲ���������������ĺ���������������
	p(3.14);
	//p("hello");

}
int main()
{
	//01 ���������ⲿ������ͬ������������������

	//�������������������������

	print(); //��������ʹ��
	//print2(); //��������ʹ�ã��Ҳ���init������


	//02 ͬ���ľֲ�������������������������

	//���غ���ֻҪ��������ͬһ���������£����ܹ������أ�����ͷ����˺������ε�����
	foo();

	foo2(); //p�����޷��������أ������˺�������
	return 0;
}


void p(int i)
{
	cout << i << endl;
}
void p(const string& s)
{
	cout << s << endl;
}
void p(double val)
{
	cout << val << endl;
}