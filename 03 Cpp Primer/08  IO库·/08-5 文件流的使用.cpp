#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//01 �ļ����Ļ���ʹ�÷���-���ļ������ļ����а�
	cout << "01 �ļ������ļ����а�" << endl;
	//��1���ļ����Ļ���ʹ�÷������ǽ��ļ������ļ������а󶨣�Ȼ�����������
	ifstream is("one.txt");
	string s;
	while (is >> s)
	{
		cout << s << endl;
	}
	is.close();
	
	//��2�� �ļ���ʹ��ʱ�򣬳���ʹ������ֵ��Ϊ�ļ����⣬Ҳ����ʹ��string���ͻ���c�����ַ�������
	string test = "two.txt";
	ifstream is2(test);
	while (is2 >> s)
	{
		cout << s << endl;
	}
	is2.close();//�ǵùر��ļ���

	//02  �ļ���ʹ�÷���-����ļ��Ƿ�ɹ���
	//��ʱ���ļ�����ֲ��������򿪵���������ʱ�����Ҫ�����ļ��򿪵ļ�⣬����ݴ�����
	cout << endl;
	cout << "02 ����ļ��Ƿ��ܹ�������" << endl;
	ifstream is3("1.txt");
	if (!is3)
	{
		cerr << "�ļ����������򿪣�" << endl;
	}
	else
	{
		while (is3 >> s)
		{
			cout << s << endl;
		}
	}
	is3.close();
	cout << endl;
	cout << "������ʱ" << endl;
	ifstream is4("three.txt");
	if (!is4)
	{
		cerr << "�ļ����������򿪣�" << endl;
	}
	else
	{
		while (is4 >> s)
		{
			cout << s << endl;
		}
	}
	is4.close();
	//03 ���ļ����������°�
	//03-1 �ļ������ʱ����ʵ���Բ���ֱ�ӽ����ļ��󶨣�������open���������
	cout << endl;
	cout << "03 �ļ�����������°�" << endl;
	ifstream is5;
	is5.open("one.txt");
	if (!is5)
	{
		cerr << "�ļ����������򿪣�" << endl;
	}
	else
	{
		while (is5 >> s)
		{
			cout << s << endl;
		}
	}
	
	is5.close();
	



	//03-2 �ļ�����������ĵ����а�
	is5.clear(); //����ע��һ�£����clearһ�£���Ȼ���ܴ�����һ���ļ���������־λ����eof����������ܲ��������л��ĵ�
	is5.open("two.txt");
	if (!is5)
	{
		cerr << "�ļ����������򿪣�" << endl;
	}
	else
	{
		while (is5 >> s)
		{
			cout << s << endl;
		}
	}
	is5.close();
	return 0;
}

