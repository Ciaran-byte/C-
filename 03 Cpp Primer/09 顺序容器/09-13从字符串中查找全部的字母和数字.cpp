#include<iostream>
using namespace std;
int main()
{

	string s = "ab2c3d7R4E6";
	string num = "0123456789";
	string character = "abcdER";

	string::size_type pos = 0;
	while ((pos = s.find_first_of(num, pos))!=string::npos)
	{
		cout << s[pos];
		pos++;
	}
	cout << endl;
	pos = 0;
	while ((pos = s.find_first_of(character, pos)) != string::npos)
	{
		cout << s[pos];
		pos++;
	}
	return 0;
}

