#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	//01 д����
	/*ofstream outfile("seq_data.txt");
	if (!outfile)cerr << "unable to save data!" << endl;
	else
	{
		outfile << "abc" << endl;
	}*/

	//02 ������
	string a;
	ifstream infile("seq_data.txt");
	if (!infile)
	{

	}
	else
	{
		infile.seekg(0);//���¶�λ���ļ�����ǰ��
		infile >> a;
	}
	
	cout << a << endl;
	return 0;

}

