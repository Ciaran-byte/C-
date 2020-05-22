#include<iostream>
#include<memory>
#include<map>
#include<set>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<functional>
using namespace std;
using namespace placeholders;
bool find_word(map<string, set<int>>::iterator it, const string& str)
{
	if (it->first == str)
	{
		return true;
	}
	return false;
}
int main()
{
	ifstream in_file("1.txt");
	vector<string> vec;
	string str;
	string word;
	map<string, set<int>> word_map;
	int line = 0;
	while (getline(in_file, str))
	{
		vec.push_back(str);
		istringstream is(str);
		line++;
		while (is >> word)
		{
			
			if (word[word.size() - 1] == ',' || word[word.size() - 1] == '.' || word[word.size() - 1] == '?' || word[word.size() - 1] == '"' || word[word.size() - 1] == '"')
			{
				word.erase(word.size() - 1,1);
			}
			if (word[0] == '"')
			{
				word.erase(0, 1);
			}
			for (auto& i : word)
			{
				i = tolower(i);
			}
			word_map[word].insert(line);
		}
	}
	string in;
	cout << "要找哪个词?" << endl;
	while (cin >> in)
	{
		for (auto& i : in)
		{
			i = tolower(i);
		}
		map<string, set<int>>::iterator it = word_map.find(in);
		if (it == word_map.end())
		{
			cout << "没有" << endl;
		}
		else
		{
			set<int>::iterator set_beg = it->second.begin();
			set<int>::iterator set_end = it->second.end();
			cout << in << "出现了" << it->second.size() << "次,分别在：" << endl;
			while (set_beg != set_end)
			{
				cout << "(line " << *set_beg << ")" << vec[(*set_beg) - 1] << endl;
				set_beg++;
			}

		}
	}
	return 0;

}





