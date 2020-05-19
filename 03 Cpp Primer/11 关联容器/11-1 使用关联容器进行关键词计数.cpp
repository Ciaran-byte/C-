#include<iostream>
#include<map>
#include<fstream>
#include<iterator>
#include<set>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	map<string, size_t> word_count;
	set<string> exclude = { "hello","hi" };
	ifstream in_file("1.txt");
	istream_iterator<string> it(in_file);
	istream_iterator<string> eof;
	
	while (it!=eof)
	{
		
		
		
		if (exclude.find(*it) == exclude.end())//ªÚ’ﬂexclude.count(*iter);
		{
			++word_count[*it];
			
		}
		++it;
	}
	for (auto i : word_count)
	{
		cout << i.first << ":" << i.second << endl;
	}


	return 0;
}

