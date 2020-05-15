#include<iostream>
using namespace std;
void fun(string& s, const string& oldval, const string& newval)
{
	if (!oldval.size()||!newval.size())
	{
		return;
	}
	auto it = s.begin();
	string test;
	while (it <= s.end()- oldval.size())
	{
		if (*it == oldval[0])
		{
			test.assign(it,it+oldval.size());
			if (test == oldval)
			{
				it = s.erase(it, it+oldval.size());
				it = s.insert(it, newval.begin(), newval.end());
				
				it += newval.size();
				
			}
			else
			{
				it++;
			}
		}
		else
		{
			it++;
		}
		
	}
}

//¸Ä½ø°æ
void fun2(string& s, const string& oldval, const string& newval)
{

	if (!oldval.size() || !newval.size())
	{
		return;
	}
	auto it = s.begin();
	string::size_type pos = 0;
	while ((pos = s.find(oldval,pos))!=string::npos)
	{
		
		
			s.replace(pos, oldval.size(), newval);
			pos += newval.size();
				
	}
}
int main()
{
	string s = "mamamiya";
	
	fun2(s, "ma", "mi");
	cout << s << endl;
	
	return 0;
}

