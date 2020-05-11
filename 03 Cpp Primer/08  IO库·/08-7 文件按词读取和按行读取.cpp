#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	vector<string> str;
	vector<string> str2;

	ifstream infile("four.txt");
	string s;
	
	while (getline(infile,s))
	{
		cout << s << endl;
		str.push_back(s);
	}
	infile.close();
	infile.open("four.txt");
	while (infile>>s)
	{
		cout << s << endl;
		str2.push_back(s);
	}

	return 0;
}
