#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	//�ļ�ģʽ��ָ��д�ļ��ķ�ʽ�����ļ������ļ��󶨵�ʱ����ж���,�ļ�ģʽһ�㶼��Ĭ��ֵ

	//01 ifstream
	//ifstreamĬ����in����ʽ���ж�ȡ������ɾ��ԭ�����ݣ����ļ�ָ�붨λ���ļ���ͷ

	ifstream infile("file1.txt", ifstream::in);
	string s;
	infile >> s;
	cout << s << endl;
	infile.close();
	//02 ofstream 
	//02-1
	//ofstream Ĭ����out��ʽ���ļ�,��outģʽ��Ĭ����truncģʽ�󶨣����������д����ļ���ǰ�����ݣ��ᱻ���
	ofstream of1("file2.txt");
	ofstream of2("file2.txt",ofstream::out);
	ofstream of3("file2.txt", ofstream::out|ofstream::trunc);
	//��������д���ǵȼ۵�

	of1 << "hello�� nice to meet you��" << endl;
	of1.close();

	//02-2 
	//���ϣ����ԭ�ļ�������в��룬��Ҫ��appģʽ
	ofstream of4("file3.txt", ofstream::out | ofstream::app);
	of4 << "hello�� nice to meet you��" << endl;
	of4.close();

	//03 fstream
	//03-1Ĭ�����
	//fstream���ܹ�ͬʱ���ļ����ж�д���������ͣ�Ĭ��ֵ��inģʽ��outģʽ�����Ҵ򿪲���������ݣ������ļ�ָ�붨λ�ڿ�ͷ
	fstream ff1("file4.txt");
	fstream ff2("file4.txt", fstream::in | fstream::out);//���ߵȼ�

	string ss = "hello";
	ff1 << ss;
	//���Կ���file4��û�б���գ������ַ���������ǰ��,���һ�ȡ��ԭ�����ļ�����

	//03-2 
	//���ϣ���ܹ�������д�룬��Ҫ��ateģʽ��ָ���ǣ����ļ��Ͱ��ļ�ָ��ŵ������
	fstream ff3("file4.txt", fstream::in | fstream::out | fstream::ate);
	ff3 << ss;
	return 0;
}

