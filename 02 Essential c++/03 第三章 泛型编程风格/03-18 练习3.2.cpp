#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

class string_length
{
public:
	bool operator()(const string& str1, const string& str2)
	{
		return (str1.size() < str2.size());


	}
};


int main()
{
	ifstream input_file("3.txt");
	if (!input_file)return -1;

	istream_iterator<string> it(input_file);
	istream_iterator<string> eof;

	map<string, int>imap;
	set<string> iset = { "a","an","or","the","and","but" };

	string words;
	for (; it != eof; it++)
	{
		words = *it;
		if (iset.count(words))
		{
			continue;
		}
		else
		{
			imap[words]++;
		}
	}

	vector<string> context;
	map<string, int>::iterator itr_map = imap.begin();
	for (; itr_map != imap.end(); itr_map++)
	{
		cout << "´ÊÃû: " << itr_map->first << endl;
		cout << "´ÎÊý: " << itr_map->second << endl;
		cout << endl;
		context.push_back(itr_map->first);
	}


	sort(context.begin(), context.end(), string_length());

	vector<string>::iterator itr_context = context.begin();
	for (; itr_context != context.end(); itr_context++)
	{
		cout << (*itr_context) << endl;
	}
	return 0;
}

