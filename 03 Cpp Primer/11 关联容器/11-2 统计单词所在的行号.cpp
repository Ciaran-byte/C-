#include<set>
#include<map>
#include<vector>
#include<iostream>
#include<list>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	
	ifstream in_file("1.txt");
	if (!in_file)return -1;
	string line;
	string word;
	int line_no = 0;
	istringstream sstring;
	map<string, vector<int>> index;
	while (getline(in_file, line))
	{
		line_no++;
		sstring.str(line);

		while (sstring >> word)
		{
			index[word].push_back(line_no);
		}
		sstring.clear();
	}

	for (auto i : index)
	{
		cout << "单词" << i.first << "出现在了以下行:";
		for (auto ii : i.second)
		{
			cout << ii << ends;
		}
		cout << endl;
		
	}

	
	return 0;
}

