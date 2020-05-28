#include<iostream>
#include<vector>
#include<string>
using namespace std;

class mycls
{
public:
	int operator()(int a, int b, int c)
	{
		if (a >= 5)return b;
		else return c;
	}
};

class ReadingString
{
public:
	ReadingString(istream& is=cin) :_is(is){}
	string operator()()
	{
		string str;
		if (!(getline(_is, str)))
		{
			return " ";
		}
		else return str;
	}

private:
	istream& _is;
};
int main()
{
	mycls fi;
	cout << fi(10, 1, 6) << endl;
	
	vector<string> vec;
	ReadingString rs;
	vec.push_back(rs());
	cout << vec[0] << endl;
	return 0;
}

