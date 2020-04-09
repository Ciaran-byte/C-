#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<iterator>

using namespace std;

int main()
{
	ifstream input_file("3.txt");
	if(!input_file)return -1;

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

	map<string, int>::iterator itr_map = imap.begin();
	for (; itr_map != imap.end(); itr_map++)
	{
		cout << "´ÊÃû: " << itr_map->first << endl;
		cout << "´ÎÊý: " << itr_map->second << endl;
		cout << endl;

	}

	return 0;
}

