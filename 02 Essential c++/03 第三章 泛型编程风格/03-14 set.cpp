#include<iostream>
#include<set>
#include<map>
using namespace std;

int main()
{

	set<string> iset = { "I","my","we" };
	map<string, int> imap;
	string mystring;
	for (int i = 0; i < 10; i++)
	{
		cin >> mystring;
		if (iset.count(mystring))
		{
			continue;
		}
		else
		{
			imap[mystring]++;
		}
	}

	map<string, int>::iterator iter = imap.begin();

	for (; iter != imap.end(); iter++)
	{
		cout << iter->first << endl;
		cout << iter->second<< endl;
		cout << endl;
	}


	return 0;
}

