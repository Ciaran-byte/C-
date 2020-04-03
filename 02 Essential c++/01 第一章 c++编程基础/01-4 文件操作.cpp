#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	//01 写操作
	/*ofstream outfile("seq_data.txt");
	if (!outfile)cerr << "unable to save data!" << endl;
	else
	{
		outfile << "abc" << endl;
	}*/

	//02 读操作
	string a;
	ifstream infile("seq_data.txt");
	if (!infile)
	{

	}
	else
	{
		infile.seekg(0);//重新定位到文件的最前面
		infile >> a;
	}
	
	cout << a << endl;
	return 0;

}

