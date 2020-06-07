#include<iostream>
#include<regex>
using namespace std;

int main()
{
	try
	{
		string file = "receipt freind ojbk theif receive";
		string pattern = "[^c]ei";
		pattern = "[[:alnum:]]*" + pattern + "[[:alnum:]]*";
		regex r(pattern);
		for (sregex_iterator it(file.begin(), file.end(), r), end; it != end; it++)
		{
			auto pos = it->prefix().length();
			pos = pos > 5 ? pos - 5 : 0;
			cout << it->prefix().str().substr(pos) << endl;
			cout <<"\t\t"<< it->str() << endl;
			cout << it->suffix().str().substr(0, 5) << endl;
		}
	}
	catch (regex_error r)
	{
		cout << r.what() << endl;
	}
	



	return 0;
}

