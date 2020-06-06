#include<iostream>
#include<regex>
using namespace std;

bool valid(const smatch& m)
{
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}
int main()
{					//1     2      3       4      5        6      7
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})";
	regex r(phone);

	smatch m;
	string s;
	while (getline(cin, s))
	{
		for (sregex_iterator it(s.begin(), s.end(), r), end; it != end; it++)
		{
			if(valid(*it))
			cout<<"valid" << it->str() << endl;
			else
				cout<<"unvalid"<<it->str()<<endl;
		}
		
	}

	return 0;
}


