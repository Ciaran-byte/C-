#include<iostream>
#include<fstream>
using namespace std;

//����������ͼ�ǣ���һ���ļ����ж�ȡ����ӡ���е���������
ifstream& open_file(ifstream& infile, const string& name)
{
	
	infile.close();
	infile.clear();
	infile.open(name, ifstream::in);
	return infile;
}

istream& get(istream& is)
{
	int ival;
	while (is >> ival, !is.eof())
	{
		if (is.bad())
		{
			throw runtime_error("ϵͳ�����ˣ�");
		}
		if (is.fail())
		{
			cerr << "��ȡʧ�ܣ�������������" << endl;
			is.clear();
			is.ignore(200, '\n');
			continue;
		}
		cout << ival << endl;
	}
	is.clear();
	return is;
}

int main()
{
	string name;
	cout << "����һ����Ҫ��ȡ���ļ���" << endl;
	cin >> name;
	ifstream infile;
	
	if (!open_file(infile, name))
	{
		cerr << "�ļ��򲻿�" << endl;
	}

	get(infile);
	infile.close();
	return 0;
}