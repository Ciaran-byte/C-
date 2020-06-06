#include<iostream>
#include<regex>
using namespace std;
int main()
{
	
		//每个括号表示一个子表达式，str(0）表示显示全部匹配表达式
		regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);

		string str;
		smatch results;

		while (cin >> str)
		{
			if (regex_search(str, results, r))
			{
				cout << results.str(1) << endl;
			}
		}

	return 0;
}




