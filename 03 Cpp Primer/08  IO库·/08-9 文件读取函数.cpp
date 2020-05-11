#include<iostream>
#include<fstream>
using namespace std;

//这个程序的意图是，打开一个文件进行读取，打印所有的数字量。
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
			throw runtime_error("系统出错了！");
		}
		if (is.fail())
		{
			cerr << "读取失败，数据类型有误" << endl;
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
	cout << "输入一个想要读取的文件名" << endl;
	cin >> name;
	ifstream infile;
	
	if (!open_file(infile, name))
	{
		cerr << "文件打不开" << endl;
	}

	get(infile);
	infile.close();
	return 0;
}