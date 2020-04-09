#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<string, int> words;
	string tword;
	for (int i = 0; i < 10; i++)
	{
		cin >> tword;
		words[tword]++;
	}
	map<string, int>::iterator it = words.begin();
	map<string, int>::iterator end = words.end();
	cout << endl;
	for (; it != end; it++)
	{
		cout << "key " << it->first << endl;
		cout << "value " << it->second << endl;
	}
	
	
	return 0;
}

