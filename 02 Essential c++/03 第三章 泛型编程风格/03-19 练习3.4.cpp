#include<iostream>
#include<iterator>
#include<fstream>
#include<vector>
using namespace std;


int main()
{
	//���Ա�׼����ĵ�����
	istream_iterator<int> it(cin);
	istream_iterator<int> eof;

	//�ļ��ı�׼���
	ofstream outfile_even("4.txt");
	ofstream outfile_odd("5.txt");
	if (!outfile_even || !outfile_odd)
	{
		cerr << "�ļ��򲻿���" << endl;
		return -1;
	}
	//��������
	vector<int> even_number;
	vector<int> odd_number;

	//����������ż�����л�������
	for (; it != eof; it++)
	{
		if ((*it) % 2 == 0)even_number.push_back(*it);
		else odd_number.push_back(*it);
	}

	//������������ļ���
	ostream_iterator<int> os_even(outfile_even, "\n");
	ostream_iterator<int> os_odd(outfile_odd, " ");
	copy(even_number.begin(), even_number.end(), os_even);
	copy(odd_number.begin(), odd_number.end(), os_odd);



	return 0;
}


