#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int main()
{
	vector<string> name;
	name.push_back("one.txt");
	name.push_back("two.txt");
	name.push_back("1.txt");
	name.push_back("three.txt");

	ifstream inputfile;
	
	auto it = name.begin();
	while (it != name.end())
	{
		inputfile.open(*it);
		if (!inputfile)
		{
			cerr << "文件"<<*it<<"打开不开" << endl;
			
			inputfile.clear();
			it++;
			
		}
		else
		{
			string s;
			while (inputfile >> s)
			{
				cout << s << endl;
			}
			inputfile.close();
			inputfile.clear();
			it++;
		}
	}


	return 0;
}

