#include<iostream>
using namespace std;

void check()
{
	if (cin.bad())
	{
		cout << "cin is bad!" << endl;
	}
	else
	{ 
		cout << "cin is not bad" << endl;
	}
		

	if (cin.fail())
	{
		cout << "cin is fail!" << endl;
	}
		
	else
	{
		cout << "cin is not fail!" << endl;
	}
		

	if (cin.eof())
		cout << "cin is eof" << endl;
	else
		cout << "cin is not eof" << endl;
	cout << endl;
}
int main()
{

	int i;
	cin >> i;

	//01 ��������״̬λ

	//cin.setstate(istream::badbit);
	cin.setstate(istream::failbit);
	//����������״̬���ÿ���ֻ��һ����Ҳ��������ͬʱ����.��bad��־λ����λʱ��fail����ֵҲ����true

	//cin.setstate(istream::failbit| istream::badbit);
	check();

	//02 ����쳣״̬
	//cin.clear(); //����ȫ��״̬
	//cin.clear(cin.rdstate()&~cin.badbit);
	cin.clear(cin.rdstate() & ~cin.failbit); //���fail��־λ
	
	check();
	//03 �쳣����״̬�ı�����ָ�
	cout << "����" << endl;
	cin.setstate(istream::failbit | istream::badbit);
	check();
	cout << "����״̬" << endl;
	istream::iostate state = cin.rdstate();
	cout << "ɾ��״̬" << endl;
	cin.clear();
	check();
	cout << "�ָ�״̬" << endl;
	cin.setstate(state);
	check();

	return 0;
}


